#ifndef POINT_MATERIEL_H
#define POINT_MATERIEL_H
#include <iostream>

#include "Coordonnees.h"
#include "Vecteur.h"


class point_materiel
{
    public:
        point_materiel(); // Constructeur par defaut. Masse nulle. Position à l'origine. Vitesse nulle
        point_materiel(double p_m); // Constructeur. Masse = m_m. Position à l'origine, Vitesse nulle
        point_materiel(double p_m, Vecteur p_v, Coordonnees p_p); // Constructeur. Masse = m_m. Position en m_p. Vitesse = m_v
        ~point_materiel();// Destructeur

    //Methodes:
        //accesseurs :
        double getM()const; // masse
        Coordonnees getC()const; //position
        Vecteur getV() const; // vitesse

        //modificateurs :
        void setM(double nouvM); // masse
        void setV(Vecteur nouvV); // vitesse

        void mod_pos(double dt); // modification de la position pendant dt
        void mod_vit(Vecteur a, double dt); // modification de la vitesse

        Vecteur f_attrac(point_materiel a)const; // calcul de la force d'attraction du point b sur le point a

    private:
        double m_m; //masse du point
        Vecteur m_v; //sa vitesse
        Coordonnees m_p; //sa position
};

#endif // POINT_MATERIEL_H
