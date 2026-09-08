#ifndef COORDONNEES_H
#define COORDONNEES_H

// definition d'une classe coordonnees qui prend 2 coordonnees cartesiennes dans le plan (O,x,y)
class Coordonnees
{
    public: //prototype
        Coordonnees(); //constructeur par defaut (O,0,0)
        Coordonnees(double m_x); // constructeur (O, m_x, 0)
        Coordonnees(double m_x, double m_y); // constructeur (O,m_x, m_y)
        ~Coordonnees(); // destructeur

    //Methodes :
    //accesseurs
    double getX()const;
    double getY()const;
    //modificateurs
    void setX(double nouvX);
    void setY(double nouvY);
    //.
    void translation(double tx, double ty); // translation du point A de tx selon l'abscisse et de ty selon l'ordonnee
    double distance(const Coordonnees &A, const Coordonnees &B); // calcul de la distance entre les points A et B

    protected:
        double m_x; //coordonnee en x
        double m_y; //coordonnee en y
};

#endif // COORDONNEES_H
