//*******************************************************************
//*																	*
//* Programme: reseau.cpp											*
//*                                                                 *
//* nom 1       : CISSE OUSMANE                                     *
//*	matricule 1 : 16 154 215									    *
//*															        *
//*******************************************************************
//*																	*
//* Description:													*
//*		Simulation d'un reseau pour le réseau de masses-ressorts :  *
//*     drapeau                                                     *
//*                                                                 *
//*******************************************************************

#include "StdAfx.h"
#include "reseau.h"
 

//vecteur force_total = vecteurnul;  //contient le resultat total des forces


reel Uniforme(const reel& a, const reel& b)
{	reel seedri;
	seedri=(reel) rand() / RAND_MAX;
	return(seedri*(b-a) + a);
}

vecteur generevent()
// Genere du vent aleatoire, appeler une seule fois par tranche de temps
{
	vecteur v_wind = vecteurnul;
	static reel vx = 5.0;
	static reel vz = 0.0;

	vx += Uniforme(-2, 2);
	vz += Uniforme(-1, 1);

	if (vx < 2.0)
		vx=2.0;
		
	if (vx > 5.0)
		vx=5.0;
		
	if (vz < -3.0)
		vz=-3.0;
		
	if (vz > 3.0)
		vz=3.0;
		
	v_wind = vecteur(vx,0.0,vz);

	return v_wind;
}



reseau::reseau(const int massenumber,const int ressortnumber,const int trinumber)
{
	nbmasses = massenumber;
	nbressort = ressortnumber;
	nbtriangles = trinumber;
	ConstFricAirMasses = 0.0;
	ConstFricAirTriangles = 0.0;
	cptmass = 0;
	cptressort = 0;
	cpttri = 0;

	m_masse = new masse[nbmasses];
	m_normal = new vecteur[nbmasses];
	m_ressort = new ressort[nbressort];
	m_tri = new triangle[nbtriangles];

	for(int i=0;i<nbmasses;i++)
		m_normal[i]= vecteur (0,0,1);

}

reseau::~reseau(void)
{
	delete [] m_masse;
	delete [] m_ressort;
	delete [] m_tri;
	delete [] m_normal;
}


void reseau::AjoutMasse(const masse& cmasse)
{
	m_masse[cptmass] = cmasse;
	cptmass++;
}

void reseau::AjoutRessort(const ressort& cressort)
{
	m_ressort[cptressort] = cressort; 
	cptressort++;
}

void reseau::AjoutTriangle(const triangle& ctri) 
{
	m_tri[cpttri] = ctri;	
	cpttri++;
}

void reseau::setConstFricAirMasses(const reel cconstAmort)
{
	ConstFricAirMasses = cconstAmort;
}

void reseau::setConstFricAirTriangles(const reel cconstFric)
{
	ConstFricAirTriangles = cconstFric;
}

void reseau::Afficher(  const bool affichermasse, 
					    const bool afficherressort,
					    const bool affichertriangle,
						const bool affichernormal)
{
	int i;
	if (affichermasse)
	{ 
		
		for(i=0;i<nbmasses;i++)
		{
			double x = m_masse[i].GetPosition().x();
			double y = m_masse[i].GetPosition().y();
			double z = m_masse[i].GetPosition().z();

			glDisable(GL_LIGHTING);
				glColor3d(0.0,1.0,0.0);
				glPushMatrix();
				glTranslated(x,y,z);
				glutSolidSphere(0.1,4,4);
				glPopMatrix();
			glEnable(GL_LIGHTING);
		}
	}


	if (afficherressort)
	{
		for(i=0;i<nbressort;i++)
		{
			double x1 = m_masse[m_ressort[i].Getmasse1id()].GetPosition().x();
			double y1 = m_masse[m_ressort[i].Getmasse1id()].GetPosition().y();
			double z1 = m_masse[m_ressort[i].Getmasse1id()].GetPosition().z();

			double x2 = m_masse[m_ressort[i].Getmasse2id()].GetPosition().x();
			double y2 = m_masse[m_ressort[i].Getmasse2id()].GetPosition().y();
			double z2 = m_masse[m_ressort[i].Getmasse2id()].GetPosition().z();

		glDisable(GL_LIGHTING);
			glLineWidth(1.0);
			glColor3f(1.0f, 0.0f, 0.0f);   
			glBegin(GL_LINES);              
			glVertex3f(x1, y1, z1);  
			glVertex3f(x2, y2, z2);  
			glEnd();
		glEnable(GL_LIGHTING);
		}
	}

	if(affichernormal)
	{
	// Affiche le verteur normal à chaque vertex
		glDisable(GL_LIGHTING);
		for(i=0;i<nbmasses;i++)
		{
			//double x = m_masse[i].GetPosition().x();
			glColor3d(0.0,1.0,1.0);
			glBegin(GL_LINES);
			glVertex3f( m_masse[i].GetPosition().x(),
				        m_masse[i].GetPosition().y(),
						m_masse[i].GetPosition().z());
			glVertex3f( m_masse[i].GetPosition().x() + m_normal[i].x(),
				        m_masse[i].GetPosition().y() + m_normal[i].y(),
						m_masse[i].GetPosition().z() + m_normal[i].z());
			glEnd(); 
				
		} 
	}

	if (affichertriangle)
	{
		
		glEnable(GL_LIGHTING);
		
		for(i=0;i<nbtriangles;i++)
		{
			
					glBegin(GL_TRIANGLES);
					glColor3f(0.8f,0.8f,0.8f);	
					glNormal3d( m_normal[m_tri[i].Getmasse1id()].x(),
							    m_normal[m_tri[i].Getmasse1id()].y(),
						        m_normal[m_tri[i].Getmasse1id()].z());
					glVertex3d( m_masse[m_tri[i].Getmasse1id()].GetPosition().x(),
						        m_masse[m_tri[i].Getmasse1id()].GetPosition().y(),
							    m_masse[m_tri[i].Getmasse1id()].GetPosition().z() );
						
					glNormal3d( m_normal[m_tri[i].Getmasse2id()].x(),
							    m_normal[m_tri[i].Getmasse2id()].y(),
						        m_normal[m_tri[i].Getmasse2id()].z());
					glVertex3d( m_masse[m_tri[i].Getmasse2id()].GetPosition().x(),
						        m_masse[m_tri[i].Getmasse2id()].GetPosition().y(),
								m_masse[m_tri[i].Getmasse2id()].GetPosition().z() );
					
					glNormal3d( m_normal[m_tri[i].Getmasse3id()].x(),
							    m_normal[m_tri[i].Getmasse3id()].y(),
						        m_normal[m_tri[i].Getmasse3id()].z());	
					glVertex3d( m_masse[m_tri[i].Getmasse3id()].GetPosition().x(),
						        m_masse[m_tri[i].Getmasse3id()].GetPosition().y(),
								m_masse[m_tri[i].Getmasse3id()].GetPosition().z());
					glEnd();
					
		}
	}
	
}


void reseau::IntegrationEuler() // à compléter
	// Euler semi-implicite
{
	for (int i = 0; i < nbmasses; i++) {

		vecteur vitesse = m_masse[i].GetVitesse();
		point position = m_masse[i].GetPosition();
		vecteur acceleration = (1 / m_masse[i].Getmasse())*m_masse[i].GetForce();


		m_masse[i].setVitesse(vitesse + acceleration * deltat);
		m_masse[i].setPosition(position + m_masse[i].GetVitesse()*deltat);

	}
	
	
}


void reseau::CalculForces() // à compléter
{
	

	for (int i = 0; i < nbmasses; i++) {


		vecteur force_masse_air = vecteurnul;
		vecteur force_gravite = vecteurnul;

		force_masse_air =  - ConstFricAirMasses * (m_masse[i].GetVitesse() - vent) * (m_masse[i].GetVitesse() - vent).norme();
		force_gravite = gravit * m_masse[i].Getmasse();

		m_masse[i].setForce(vent + force_masse_air + force_gravite);

	}

	
	for (int i = 0; i < nbtriangles; i++) {
		vecteur vitesse_surface = vecteurnul;
		vitesse_surface = (1.0 / 3.0)*(m_masse[m_tri[i].Getmasse1id()].GetVitesse() + m_masse[m_tri[i].Getmasse2id()].GetVitesse()  //Vitesse de la surface
			+ m_masse[m_tri[i].Getmasse3id()].GetVitesse());

		vecteur normal = vecteurnul;
		vecteur p2p1 = m_masse[m_tri[i].Getmasse2id()].GetPosition() - m_masse[m_tri[i].Getmasse1id()].GetPosition();
		vecteur p3p2 = m_masse[m_tri[i].Getmasse3id()].GetPosition() - m_masse[m_tri[i].Getmasse1id()].GetPosition();

		normal = p2p1 ^ p3p2;

		normal.normalise();
		vecteur force_air_surface = - ConstFricAirMasses * (normal*(vent - vitesse_surface)) * normal;
		m_masse[m_tri[i].Getmasse1id()].setForce(m_masse[m_tri[i].Getmasse1id()].GetForce() + (1 / 3.0)*force_air_surface);
		m_masse[m_tri[i].Getmasse2id()].setForce(m_masse[m_tri[i].Getmasse2id()].GetForce() + (1 / 3.0)*force_air_surface);
		m_masse[m_tri[i].Getmasse3id()].setForce(m_masse[m_tri[i].Getmasse3id()].GetForce() + (1 / 3.0)*force_air_surface);

	}

	for (int i = 0; i < nbressort; i++) {
		vecteur v = m_masse[m_ressort[i].Getmasse1id()].GetPosition() - m_masse[m_ressort[i].Getmasse2id()].GetPosition();
		v.normalise();
		reel x = (m_masse[m_ressort[i].Getmasse1id()].GetPosition() - m_masse[m_ressort[i].Getmasse2id()].GetPosition()).norme();
		vecteur vect_m1m2 = (m_masse[m_ressort[i].Getmasse1id()].GetPosition() - m_masse[m_ressort[i].Getmasse2id()].GetPosition());
		vect_m1m2.normalise();
		reel distance = x - m_ressort[i].GetLongueurRepos();
		vecteur force_ressort = -m_ressort[i].GetconstRaideur()* distance * vect_m1m2;


		m_masse[m_ressort[i].Getmasse2id()].setForce(m_masse[m_ressort[i].Getmasse2id()].GetForce() - force_ressort);
		m_masse[m_ressort[i].Getmasse1id()].setForce(m_masse[m_ressort[i].Getmasse1id()].GetForce() + force_ressort);
	}

	

}


void reseau::Miseajour(const reel dt)
{
	deltat = dt;

	// Calcul des normales au vertex pour l'affichage
   // ... à compléter

		//for (int i = 0; i < nbmasses; i++) m_masse[i].setForce(vecteurnul);


		for (int i = 0; i < nbmasses; i++) m_normal[i] = vecteurnul;


		for (int i = 0; i < nbtriangles; i++) {

			vecteur normal = vecteurnul;
			vecteur p2p1 = m_masse[m_tri[i].Getmasse2id()].GetPosition() - m_masse[m_tri[i].Getmasse1id()].GetPosition();
			vecteur p3p2 = m_masse[m_tri[i].Getmasse3id()].GetPosition() - m_masse[m_tri[i].Getmasse1id()].GetPosition();

			normal = p2p1 ^ p3p2;
			normal.normalise();

			m_normal[m_tri[i].Getmasse1id()] = m_normal[m_tri[i].Getmasse1id()] + normal;
			m_normal[m_tri[i].Getmasse2id()] = m_normal[m_tri[i].Getmasse2id()] + normal;
			m_normal[m_tri[i].Getmasse3id()] = m_normal[m_tri[i].Getmasse3id()] + normal;
			//m_masse[i].
			
		}

		for (int i = 0; i < nbmasses; i++) {
			m_normal[i].normalise();
			}

		CalculForces();
		IntegrationEuler();

		
	

	}
	

