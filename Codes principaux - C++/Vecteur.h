#ifndef VECTEUR_H
#define VECTEUR_H
#include <iostream>

#include "Coordonnees.h"

// Definition d'une classe vecteur definit par sa valeur selon x, selon y, sa norme et son angle de direction
class Vecteur : public Coordonnees
{
    public:
        Vecteur(); // Constructeur par defaut. Vecteur nul
        Vecteur(double p_x, double p_y); // Constructeur V =[m_x,m_y]
        Vecteur(Coordonnees A, Coordonnees B); // Constructeur V =[B_x -A_x, B_y -A_y]
        ~Vecteur(); // Destructeur

    //Methodes :
        virtual Coordonnees getC()const;
        double cal_norme() const; // calcul de la norme du vecteur (norme = sqrt[m_x^2 + m_y^2])
        double cal_ang()const; // calcul de l'angle du vecteur avec l'axe des abscisses (angle = arctan(m_y/m_x))
        void rot(double alp); // rotation d'un vecteur d'un angle alp

    protected:
        double m_nor; // norme du vecteur
        double m_dir; // angle de direction du vecteur (angle avec l'abscisse)
};

Vecteur operator+(Vecteur const &a, Vecteur const &b); // somme des vecteurs a et b
Vecteur operator*(Vecteur &a, double d); // multiplication du vecteur a par d
Vecteur operator*(double d, Vecteur &a);
Vecteur operator-(Vecteur const &a, Vecteur const &b); // somme des vecteurs a et b

#endif // VECTEUR_H
