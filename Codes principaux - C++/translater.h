#ifndef TRANSLATER_H_INCLUDED
#define TRANSLATER_H_INCLUDED
#include <iostream>

#include "Coordonnees.h"
#include "Vecteur.h"

Coordonnees operator+(Coordonnees const &p, Vecteur const &v); // translater le point p par le vecteur v

#endif // TRANSLATER_H_INCLUDED
