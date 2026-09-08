#include <iostream>
#include <math.h>
using namespace std;
#include "Coordonnees.h"

// Definition d'une classe coordonnees qui prend 2 coordonnees cartesiennes dans le plan (O,x,y)

//Constructeurs :
    Coordonnees::Coordonnees(): m_x(0.0), m_y(0.0) //constructeur par defaut (O,0,0)
    {
    }
    Coordonnees::Coordonnees(double p_x): m_x(p_x), m_y(0.0) // constructeur (O, m_x, 0)
    {
    }
    Coordonnees::Coordonnees(double p_x, double p_y): m_x(p_x), m_y(p_y) // constructeur (O,m_x, m_y)
    {
    }

    Coordonnees::~Coordonnees()//Destructeur
    {
    }

//Methodes :
    //Accesseurs
    double Coordonnees::getX()const
    {
        return m_x;
    }
    double Coordonnees::getY()const
    {
        return m_y;
    }
    //Modificateurs
    void Coordonnees::setX(double nouvX)
    {
        m_x = nouvX;
    }
    void Coordonnees::setY(double nouvY)
    {
        m_y = nouvY;
    }
    //.
    void Coordonnees::translation(double tx, double ty)// translation du point A de tx selon l'abscisse et de ty selon l'ordonnee
    {
       m_x += tx; // A_x = A_x + tx
       m_y += ty; // A_y = A_y + ty
    }

    double Coordonnees::distance(const Coordonnees &A, const Coordonnees &B) // calcul de la distance entre les points A et B
    {
        double d = sqrt(pow(A.getX()-B.getX(),2) + pow(A.getY()-B.getY(),2)); // d = sqrt[(A_x - B_x)^2 + (A_y - B_y)^2]
        return d;
    }

