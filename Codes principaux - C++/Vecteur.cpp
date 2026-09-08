#include <iostream>
#include <math.h>
using namespace std;

#include "Vecteur.h"

// Definition d'une classe vecteur definit par sa valeur selon x, selon y, sa norme et son angle de direction

// Constructeurs
Vecteur::Vecteur(): Coordonnees(), m_nor(0.0), m_dir(0.0) // Constructeur par defaut. Vecteur nul
{
}
Vecteur::Vecteur(double p_x, double p_y): Coordonnees(p_x, p_y), m_nor(cal_norme()), m_dir(cal_ang())// Constructeur V =[m_x,m_y]
{
}
Vecteur::Vecteur(Coordonnees A, Coordonnees B): Coordonnees(B.getX()-A.getX(), B.getY()-A.getY()), m_nor(cal_norme()), m_dir(cal_ang()) // Constructeur V =[B_x -A_x, B_y -A_y]
{
}

Vecteur::~Vecteur() //Destructeur
{
}

//Methodes :
    Coordonnees Vecteur::getC() const
    {
        Coordonnees C(getX(),getY());
        return C;
    }
    double Vecteur::cal_norme() const // calcul de la norme du vecteur (norme = sqrt[m_x^2 + m_y^2])
    {
        double n = sqrt(pow(getX(),2)+pow(getY(),2));
        return n;
    }

    double Vecteur::cal_ang()const // calcul de l'angle du vecteur avec l'axe des abscisses (angle = arctan(m_y/m_x))
    {
        double alp = atan2(getY(),getX());
        return alp;
    }

    void Vecteur::rot(double alp) // rotation d'un vecteur d'un angle alp
    {
       m_dir = m_dir + alp;
       setX(m_nor*cos(m_dir));
       setY(m_nor*sin(m_dir));
    }

Vecteur operator+(Vecteur const &a, Vecteur const &b) // somme des vecteurs a et b
{
    Vecteur s(a.getX()+b.getX(), a.getY()+b.getY());
    return s;
}
Vecteur operator-(Vecteur const &a, Vecteur const &b) // somme des vecteurs a et b
{
    Vecteur s(a.getX()-b.getX(), a.getY()-b.getY());
    return s;
}

Vecteur operator*(Vecteur &a, double d) // multiplication du vecteur a par d
{
    return Vecteur(a.getX() * d, a.getY() * d);
}

Vecteur operator*(double d, Vecteur const &a)
{
    return Vecteur(a.getX() * d, a.getY() * d);
}
