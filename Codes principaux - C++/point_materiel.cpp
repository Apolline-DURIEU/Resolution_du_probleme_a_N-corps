#include <iostream>
#include <math.h>
using namespace std;

#include "point_materiel.h"

point_materiel::point_materiel(): m_m(0.0), m_v(Vecteur()), m_p(Coordonnees()) // Constructeur par defaut. Masse nulle. Position à l'origine. Vitesse nulle
{
}
point_materiel::point_materiel(double p_m): m_m(p_m), m_v(Vecteur()), m_p(Coordonnees()) // Constructeur. Masse = m_m. Position en m_p. Vitesse = m_v
{
}
point_materiel::point_materiel(double p_m, Vecteur p_v, Coordonnees p_p): m_m(p_m), m_v(p_v), m_p(p_p) // Constructeur. Masse = m_m. Position en m_p. Vitesse = m_v
{
}

point_materiel::~point_materiel() // Destructeur
{
}

//Methodes :
    double point_materiel::getM()const // accesseur de la masse
    {
        return m_m;
    }
    Coordonnees point_materiel::getC()const
    {
        return m_p;
    }
    Vecteur point_materiel::getV() const // modificateur de la vitesse selon x
    {
        return m_v;
    }
    void point_materiel::setM(double nouvM) // modificateur de la masse
    {
        m_m = nouvM;
    }
    void point_materiel::setV(Vecteur nouvV) //
    {
        m_v = nouvV;
    }


    void point_materiel::mod_pos(double dt) // modification de la position pendant dt
    {
        m_p.setX(m_p.getX() + dt*m_v.getX());
        m_p.setY(m_p.getY() + dt*m_v.getY());
    }

    void point_materiel::mod_vit(Vecteur a, double dt) // modification de la vitesse pendant dt
    {
        m_v = m_v+a*(dt);
    }

    Vecteur point_materiel::f_attrac(point_materiel a)const // calcul de la force d'attraction du point b sur le point a
    {
        double G(6.674e-11);
        Vecteur xab = Vecteur(m_p, a.getC()); // vecteur ab
        double n = (G*m_m*(a.getM())/pow(xab.cal_norme(),3)); //scalaire
        Vecteur f = xab*n;
        return f;
    }
