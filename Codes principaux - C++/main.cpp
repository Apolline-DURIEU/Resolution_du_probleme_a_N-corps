#include <iostream>
#include <fstream> // Pour utiliser un fichier
using namespace std;
#include <math.h>
#include <string>

#include "Coordonnees.h"
#include "Vecteur.h"
#include "point_materiel.h"
#include "translater.h"


int main()
{
    double t_max = 3.0e10;//Duree d'etude du mouvement des corps (a renseigner)
    double dt = 100.00; // delta de temps pour la methode d'Euler
    double mS = 1.989e30; // masse du soleil
    double mV = 4.867e24; //masse de Venus
    double mT = 5.972e24 ; // masse de la terre
    double mM = 6.39e23; // masse de mars
    /*double mJ = 1.898e27; //jupiter
    double mSa = 5.683e26; //saturne
    double mU = 8.681e25; //uranus
    double mN = 1.024e26; //neptune*/
    //double mL = 7.36e22; //masse de la lune

    string const chemin("C:\\Users\\apoll\\Documents\\Polytech_Lyon\\CODING\\TP4\\Resultat.txt");
    ofstream Fichier(chemin.c_str(),ios::app);

    //Coordonnees des positions initiales :
        Coordonnees posS;
        Coordonnees posV(0.0,1.08e11);
        Coordonnees posT(0.0,1.49597870e11);//1.49597870e11m du soleil
        Coordonnees posM(0.0, 2.27937e11);
        /*Coordonnees posJ(0.0,7.785e11);
        Coordonnees posSa(0.0,1.434e12);
        Coordonnees posU(0.0,2.871e12);
        Coordonnees posN(0.0,4.5e12);*/
        //Coordonnees posL(0.0,3.844e8+1.49597870e11);

    //Vecteurs vitesse initiaux :
        Vecteur vV(3.502571e4,0.0);
        Vecteur vT(29800.0,0.0);
        Vecteur vM(2.4080e4,0.0);
        /*Vecteur vJ(13070.0,0.0);
        Vecteur vSa(9.68e3,0.0);
        Vecteur vU(6.796732e3,0.0);
        Vecteur vN(5.43248e3,0.0);*/
        //Vecteur vL(29800.0-1023.219504,0.0);//vitesse de la lune autour de la terre
        //Vecteur vS((-1.0/mS)*(mT*vT.getC().getX()+mS*vS.getC().getX()+mM*vM.getC().getX()+mV*vV.getC().getX()+mJ*vJ.getC().getX()+mSa*vSa.getC().getX()+mU*vU.getC().getX()+mN*vN.getC().getX()),0.0);
        Vecteur vS((-1.0/mS)*(mT*vT.getC().getX()+mS*vS.getC().getX()+mM*vM.getC().getX()+mV*vV.getC().getX()),0.0);


    int temps = (int)(floor(t_max/dt))+1; // le nombre de temps etudies
    cout<<"temps : "<<temps<<endl;
    double t=0.0;//le temps au moment de l'etude
    int i=0;

    //Vecteurs des forces d'un corps sur un autre :
        Vecteur F_sv;// Vecteur de la force de venus sur le soleil

        Vecteur F_st;
        Vecteur F_vt;

        Vecteur F_sm;
        Vecteur F_vm;
        Vecteur F_tm;

        /*Vecteur F_tl;
        Vecteur F_sl;*/

        /*Vecteur F_sj;
        Vecteur F_vj;
        Vecteur F_tj;
        Vecteur F_mj;

        Vecteur F_ssa;
        Vecteur F_vsa;
        Vecteur F_tsa;
        Vecteur F_msa;
        Vecteur F_jsa;

        Vecteur F_su;
        Vecteur F_vu;
        Vecteur F_tu;
        Vecteur F_mu;
        Vecteur F_ju;
        Vecteur F_sau;

        Vecteur F_sn;
        Vecteur F_vn;
        Vecteur F_tn;
        Vecteur F_mn;
        Vecteur F_jn;
        Vecteur F_san;
        Vecteur F_un;*/

    //Vecteur de toutes les forces appliquees sur un corps :
        Vecteur S;
        Vecteur T;
        Vecteur M;
        Vecteur V;
        /*Vecteur J;
        Vecteur Sa;
        Vecteur U;
        Vecteur N;*/
        //Vecteur L;

    //Position des condition initiales
        point_materiel Soleil(mS, vS, posS);
        point_materiel Venus(mV, vV, posV);
        point_materiel Terre(mT, vT, posT);
        point_materiel Mars(mM, vM, posM);
        /*point_materiel Jupiter(mJ, vJ, posJ);
        point_materiel Saturne(mSa, vSa, posSa);
        point_materiel Uranus(mU, vU, posU);
        point_materiel Neptune(mN, vN, posN);*/
        //point_materiel Lune(mL, vL, posL);

    cout<<"Calculs lances"<<endl;

    //Boucles de calcul
    for(i=1;i<temps;i++)
    {
        F_sv= Soleil.f_attrac(Venus);

        F_st= Soleil.f_attrac(Terre); // force de la terre sur le soleil*/
        F_vt= Venus.f_attrac(Terre);

        F_sm= Soleil.f_attrac(Mars);
        F_tm= Terre.f_attrac(Mars);
        F_vm= Venus.f_attrac(Mars);

        //F_sl= Soleil.f_attrac(Lune);
        //F_tl= Terre.f_attrac(Lune); //force de la terre sur la lune
        //F_ml= Mars.f_attrac(Lune);

        /*F_sj = Soleil.f_attrac(Jupiter);
        F_vj = Venus.f_attrac(Jupiter);
        F_tj = Terre.f_attrac(Jupiter);
        F_mj = Mars.f_attrac(Jupiter);

        F_ssa = Soleil.f_attrac(Saturne);
        F_vsa = Venus.f_attrac(Saturne);
        F_tsa = Terre.f_attrac(Saturne);
        F_msa = Mars.f_attrac(Saturne);
        F_jsa = Jupiter.f_attrac(Saturne);

        F_su = Soleil.f_attrac(Uranus);
        F_vu = Venus.f_attrac(Uranus);
        F_tu = Terre.f_attrac(Uranus);
        F_mu = Mars.f_attrac(Uranus);
        F_ju = Jupiter.f_attrac(Uranus);
        F_sau = Saturne.f_attrac(Uranus);

        F_sn = Soleil.f_attrac(Neptune);
        F_vn = Venus.f_attrac(Neptune);
        F_tn = Terre.f_attrac(Neptune);
        F_mn = Mars.f_attrac(Neptune);
        F_jn = Jupiter.f_attrac(Neptune);
        F_san = Saturne.f_attrac(Neptune);
        F_un = Uranus.f_attrac(Neptune);*/


        S = F_sm+F_st+/*F_sl;*/F_sv/*+F_sj+F_ssa+F_su+F_sn*/; //forces appliquee sur le soleil
        V = F_vt+F_vm-F_sv/*+F_vj+F_vsa+F_vu+F_vn*/;
        T = /*F_tl*/F_tm-F_st-F_vt/*+F_tj+F_tsa+F_tu+F_tn*/; //forces appliquee sur la terre
        M = /*F_mj+F_msa+F_mu+F_mn*/(F_tm+F_sm+F_vm);
        /*J = F_jsa-F_sj-F_vj-F_tj-F_mj+F_ju+F_jn;
        Sa = F_sau+F_san-F_ssa-F_vsa-F_tsa-F_msa-F_jsa;
        U = F_un-F_su-F_vu-F_tu-F_mu-F_ju-F_sau;
        N = F_sn+F_vn+F_tn+F_mn+F_jn+F_san+F_un;*/
        //L = F_tl+F_sl;//+F_sl; //forces appliquee sur la lune

        //Modification des vitesses :
            Soleil.mod_vit(S*(1.0/mS), dt); //mod de la vitesse selon l'acceleration
            Venus.mod_vit(V*(1.0/mV), dt);
            Terre.mod_vit(T*(1.0/mT), dt);
            //Lune.mod_vit(L*(-1.0/mL), dt);
            Mars.mod_vit(M*(-1.0/mM), dt);
            /*Jupiter.mod_vit(J*(1.0/mJ), dt);
            Saturne.mod_vit(Sa*(1.0/mSa), dt);
            Uranus.mod_vit(U*(1.0/mU), dt);
            Neptune.mod_vit(N*(-1.0/mN), dt);*/

        //Modification des positions :
            Soleil.mod_pos(dt);
            Venus.mod_pos(dt);
            Terre.mod_pos(dt);
            //Lune.mod_pos(dt);
            Mars.mod_pos(dt);
            /*Jupiter.mod_pos(dt);
            Saturne.mod_pos(dt);
            Uranus.mod_pos(dt);
            Neptune.mod_pos(dt);*/

        t = t + dt;

        //enregistrement des positions 1 fois tous les 1000 calculs
        if(i % 1000 != 0)
        //if(i % 50 != 0)
        {
            //ne rien faire
        }
        else
        {
            if(Fichier)//enregistrement dans le fichier
            {
                //Fichier<<t<<"\t"<<Soleil.getC().getX()<<"\t"<<Soleil.getC().getY()<<"\t"<<Terre.getC().getX()<<"\t"<<Terre.getC().getY()<<"\t"<<Lune.getC().getX()<<"\t"<<Lune.getC().getY()<<endl;
                //Fichier<<t<<"\t"<<Soleil.getC().getX()<<"\t"<<Soleil.getC().getY()<<"\t"<<Venus.getC().getX()<<"\t"<<Venus.getC().getY()<<"\t"<<Terre.getC().getX()<<"\t"<<Terre.getC().getY()<<"\t"<<Mars.getC().getX()<<"\t"<<Mars.getC().getY()<<"\t"<<Jupiter.getC().getX()<<"\t"<<Jupiter.getC().getY()<<"\t"<<Saturne.getC().getX()<<"\t"<<Saturne.getC().getY()<<"\t"<<Uranus.getC().getX()<<"\t"<<Uranus.getC().getY()<<"\t"<<Neptune.getC().getX()<<"\t"<<Neptune.getC().getY()<<endl;
                Fichier<<t<<"\t"<<Soleil.getC().getX()<<"\t"<<Soleil.getC().getY()<<"\t"<<Venus.getC().getX()<<"\t"<<Venus.getC().getY()<<"\t"<<Terre.getC().getX()<<"\t"<<Terre.getC().getY()<<"\t"<<Mars.getC().getX()<<"\t"<<Mars.getC().getY()<<endl;
            }
            else
            {
                cout<<"erreur a l'ouverture du fichier"<<endl;
            }
        }
    }
    return 0;
}
