#include <iostream>
#include <math.h>
using namespace std;

#include "translater.h"

Coordonnees operator+(Coordonnees const &p, Vecteur const &v) // translater le point p par le vecteur v
{
    Coordonnees t(p.getX()+v.getX(),p.getY()+v.getY());
    return t;
}
