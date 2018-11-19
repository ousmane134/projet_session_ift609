//*******************************************************************
//*																	*
//* Programme: GenerePhoton.cpp	       							    *
//*																	*
//*******************************************************************
//*																	*
//* Description:													*
//*		Génération de photons.                     					*
//*																	*
//* nom1 : CISSE OUSMANE                                            *
//* matricule1: 16 154 215                                          *
//*																	*
//*******************************************************************


#include "GenerePhoton.h"
#include "inter.h"
#include "util.h"
#include "utilalg.h"
#include "aff.h"
#include "segment.h"
#include "ensemble.h"
#include "geo.h"
#include "mat.h"
#include <math.h>
#include "Point.h"
#include "time.h"
#include "main.h"

#include "spotlight.h"
#include "ponctuelle.h"
#include "settingTracePhoton.h"




booleen 
GenerePhotons( const Camera& camera, Objet* scene )
{


    const Lumiere* lum = NULL;
	
    PhotonMap* CaustiqueMap = pFenAff3D->PhotonTracing()->PhotonMapCaustique();

    int nbLum = camera.NbLumiere(); // pour avoir le nombre de lumiere
    //lum = camera.GetLumiere( 0 );  // la première lumiere : n'oubliez pas les autres ...


    printf( "\nGeneration des photons...\n");

    clock_t  clk = clock();

//	... à compléter

	reel enrgie_totale = 0;
	for (int i = 0; i < nbLum; i++) {
		enrgie_totale += camera.GetLumiere(i)->EnergiePhoton().rouge() + camera.GetLumiere(i)->EnergiePhoton().bleu() + camera.GetLumiere(i)->EnergiePhoton().vert();
	}

	for (int i = 0; i < nbLum; i++) {

		lum = camera.GetLumiere(i);

		reel nombre_photons = (lum->EnergiePhoton().bleu() + lum->EnergiePhoton().rouge() + lum->EnergiePhoton().vert()) * (NB_PHOTON_CAUSTIQUE / enrgie_totale);
		Couleur puissance_photon = lum->EnergiePhoton() / nombre_photons;

		for (int i = 0; i < nombre_photons; i++) {
			point p = lum->Position();
			vecteur direction = lum->RayonAleatoire();

			bool reflechi = true;
			int nombre_reflexion = 0;


			while (reflechi) {

				reel distance;
				vecteur vecteur_normale;
				Couleurs couleurs;

				reflechi = false;

				if (Objet_Inter(*scene, p, direction, &distance, &vecteur_normale, &couleurs)) {
					p = p + direction * distance;

					if (couleurs.reflechi() != NOIR) {
						direction = Reflechi(direction, vecteur_normale);
						puissance_photon = puissance_photon * couleurs.reflechi();

						reflechi = true;
						nombre_reflexion += 1;
					}
				}
			}

			if (nombre_reflexion > 0) {
				direction.normalise();
				CaustiqueMap->Store(puissance_photon, p, direction);
			}

		}
	}
    printf( "\nFin du trace de photon\n" );

    printf("Balancement du photon map caustique...\n");
    CaustiqueMap->Balance();
    printf("Fin du balancement du photon map caustique\n\n");

    clk = clock() - clk;
    clk /= CLOCKS_PER_SEC;

    Affiche( *CaustiqueMap, &scene, camera );


    printf( "Temps pour generer les photons : %d:%02d\n\n", clk / 60, clk % 60 );

    return VRAI;
}



void Affiche( const PhotonMap& table, Objet **scene, const Camera& camera )
{
    Attributs* a = new Attributs;

    Couleur cd( 1,1,1 );

    a->diffus( cd );
    a->ambiant( cd );

    Ensemble* ens = new Ensemble;
    const Lumiere* lum = NULL;

    for ( int i = 1; i <= table.NbPhotons(); i += 100 )
    {
        point p1;
        p1 = table[i].position();


        vecteur vec;
        vec = table[i].PhotonDir();

        vec = -vec;

        point p2 = p1 + ( vec );

        Segment* seg = new Segment( p1, p2 );
        seg->attributs( a );
        ens->ajoute( seg );
    }

    // affiche la direction du spot light
    for ( int j = 0; j < camera.NbLumiere(); j++ )
    {
        lum = camera.GetLumiere(j);

        if ( lum->Type() == unSpotlight )
        {
            Spotlight * spot = (Spotlight*)lum;
            // direction du spot light
            point p2 = spot->Position() + ( spot->GetDirection() * 2 );
            Segment* seg = new Segment( spot->Position(), p2 );
    
            seg->attributs( a );
            ens->ajoute( seg );
        }
    }

    ens->attributs( a );

    ((Ensemble*)(*scene))->ajoute( ens );
}