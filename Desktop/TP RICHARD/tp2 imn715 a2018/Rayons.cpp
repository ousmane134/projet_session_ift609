//*******************************************************************
//* nom1 : CISSE OUSMANE                                            *
//* matricule1:  16 154 215                                         *
//*******************************************************************


#include "rayons.h"
#include "couleurs.h" 
#include "attr.h"
#include "ensemble.h"
#include "point.h"
#include "transfo.h"
#include "inter.h"
#include "vision.h"
#include "util.h"
#include "utilalg.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "main.h"
#include "canon.h"
#include "time.h"

#include "spotlight.h"
#include "photonmap.h"


Couleur calculer_intensite_rayon( point origine, vecteur direction, Objet* scene, const Camera& camera);

void Enregistre_pixel (int no_x, int no_y, Couleur intens, Fichier f)
// enregistre la couleur du pixel dans le fichier f
// Chacune des composantes de la couleur doit etre de 0 a 1,
// sinon elle sera ramene a une borne.
{
     
	reel r,v,b;
	char c;
 
	intens=intens*255.0;
	r=intens.rouge();
	if (r<0) r=0;
	if (r>255)r=255;
	c=(unsigned char) r;
	f.Wcarac(c);

	v=intens.vert();
	if (v<0) v=0;
	if (v>255) 
		v=255;
	c=(unsigned char) v;
	f.Wcarac(c);

	b=intens.bleu();
	if (b<0) b=0;
	if (b>255) b=255;
	c=(unsigned char) b;
	f.Wcarac(c);

}
Couleur calculer_intensite_point_inter(Objet* scene, const Camera& camera, vecteur direction, point pt_inter, vecteur vn, Couleurs couleurs)
{
	Couleur intensite(0.0, 0.0, 0.0);

	vecteur o = -direction.unitaire();

	vn.unitaire();


	if (vn * o < 0) {
		vn = -vn;
	}

	PhotonMap* CaustiqueMap = pFenAff3D->PhotonTracing()->PhotonMapCaustique();

	reel rayon_maximal = 0.3;

	int nbPhotons = 200;
    int found;

	reel *dist2 = NULL;

	const Photon **ph = NULL;

	for (int i = 0; i < camera.NbLumiere(); i++) {

		vecteur vl = (camera.Position(i) - pt_inter).unitaire();

		reel cos_theta = vn * vl;

		if (cos_theta < 0) 	cos_theta = 0;
		
		Couleur Id = camera.GetLumiere(i)->Intensite() * couleurs.diffus() * cos_theta;
		

		if (!camera.GetLumiere(i)->Eclaire(pt_inter)) Id = 0;	
		intensite = intensite + Id;

	}

	CaustiqueMap->Locate(pt_inter, rayon_maximal, nbPhotons, found, &dist2, &ph);

	Couleur energie_photon_totale = Couleur(0, 0, 0);
	Couleur intensite_caustique = Couleur(0, 0, 0);

	reel tmp_rayon = 0;

	if (found > 0) {
		for (int i = 1; i <= found; i++) {

			ph[i]->PhotonDir().normalise();
			vn.normalise();

		
			energie_photon_totale = energie_photon_totale + ph[i]->energie() * couleurs.diffus();
		

			if (*dist2 > tmp_rayon) tmp_rayon = *dist2;
			
		}

		reel pi_rayon = PI * tmp_rayon;

		intensite_caustique = ((energie_photon_totale) / (PI * tmp_rayon));
	}

	delete[] dist2;
	delete[] ph;

	intensite = intensite + intensite_caustique;

	if (couleurs.reflechi() != NOIR) {
		vecteur vr = 2 * (vn*o)*vn - o;

		intensite = intensite + calculer_intensite_rayon( pt_inter, vr, scene, camera) * couleurs.reflechi();
	}

	return intensite;
}

Couleur calculer_intensite_rayon( point o, vecteur direction, Objet* scene, const Camera& camera)
{
	reel dist;
	vecteur vn;
	Couleurs couleurs;

	Couleur intensite(NOIR);

	if (Objet_Inter(*scene, o, direction, &dist, &vn, &couleurs)) {
		point pt_inter = o + direction * dist;
		intensite = calculer_intensite_point_inter(scene, camera, direction, pt_inter, vn, couleurs);
	}

	else {
		intensite = NOIR; 
	}

	return intensite;
}


booleen TraceRayons(const Camera& camera, Objet *scene, const entier& res, char fichier[])
// Genere un rayon pour chacun des pixel et calcul l'intensite de chacuns
{ 
	Couleur Intensite;

	entier nb_pixel_x = res;
	entier nb_pixel_y = res;

	Transformation transfInv = Vision_Normee(camera).inverse();

// ...
	reel dx = 2.0 / nb_pixel_x;
	reel dy = 2.0 / nb_pixel_y;

	//Ouverture du fichier pour y enregistrer le trace de rayon
	Fichier f;
	if ( !f.Open(fichier, "wb") ) return FAUX;

	f.Wchaine("P6\r");
	f.Wentier(res); f.Wcarac(' '); f.Wentier(res);	f.Wchaine("\r");
	f.Wentier(255);	f.Wchaine("\r");

	printf("\nDebut du trace de rayons\n");
	printf ("%4d source(s) lumineuse(s)\n", camera.NbLumiere());
// ...
	point o = camera.PO();
	for (int no_y = 1; no_y <= nb_pixel_y; no_y++)   
	{ 
		for (int no_x = 1; no_x <= nb_pixel_x; no_x++)    
		{
// ...

			reel x = 1.0 - dx / 2.0 - (no_x - 1) * dx;
			reel y = 1.0 - dy / 2.0 - (no_y - 1) * dy;

			point pcu = transfInv.transforme(point(x, y, 1));

			vecteur dir = pcu - o;

			Intensite = calculer_intensite_rayon( o, dir, scene, camera);
			Enregistre_pixel(no_x, no_y,Intensite, f);
		}

		//Imprime le # de ligne rendu
		if ( no_y % 15 == 0 ) printf("\n");
		printf ("%3d ", no_y);	
	}
	printf ("\n\nFin du trace de rayons.\n");


	f.Close();
	return VRAI;
}


  
