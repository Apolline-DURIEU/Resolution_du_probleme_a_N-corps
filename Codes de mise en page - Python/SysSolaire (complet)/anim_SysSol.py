# -*- coding: utf-8 -*-
"""
Created on Mon Dec  1 14:49:17 2025

@author: apoll
"""

from matplotlib import pyplot as plt
import numpy as np

XS = [];
YS = [];
XV = [];
YV = [];
XT = [];
YT = [];
XM = [];
YM = [];

XJ = [];
YJ = [];
XSA = [];
YSA = [];
XU = [];
YU = [];
XN = [];
YN = [];

with open("Resultats_SysSolLONG.txt", "r", encoding="utf-8") as R:
    for ligne in R:
        colonnes = ligne.split()  # découpe par espace ou tabulation
        if len(colonnes) < 7:
            continue
        xS = float(colonnes[1])      # 2e colonne (index 1)
        yS = float(colonnes[2])     # 3e colonne (index 2)
        xV = float(colonnes[3])      # 2e colonne (index 1)
        yV = float(colonnes[4]) 
        xT = float(colonnes[5])      # 2e colonne (index 1)
        yT = float(colonnes[6])  
        xM = float(colonnes[7])   
        yM = float(colonnes[8])
        
        xJ = float(colonnes[9])      # 2e colonne (index 1)
        yJ = float(colonnes[10])     # 3e colonne (index 2)
        xSA = float(colonnes[11])      # 2e colonne (index 1)
        ySA = float(colonnes[12]) 
        xU = float(colonnes[13])      # 2e colonne (index 1)
        yU = float(colonnes[14])  
        xN = float(colonnes[15])   
        yN = float(colonnes[16])
        
        XS.append(xS)
        YS.append(yS)
        XV.append(xV)
        YV.append(yV)
        XT.append(xT)
        YT.append(yT)
        XM.append(xM)
        YM.append(yM)
        
        XJ.append(xJ)
        YJ.append(yJ)
        XSA.append(xSA)
        YSA.append(ySA)
        XU.append(xU)
        YU.append(yU)
        XN.append(xN)
        YN.append(yN)

XS = np.array(XS)
XT = np.array(XT)
XM = np.array(XM)
YS = np.array(YS)
YT = np.array(YT)
YM = np.array(YM)
XV = np.array(XV)
YV = np.array(YV)

XJ = np.array(XJ)
YJ = np.array(YJ)
XSA = np.array(XSA)
YSA = np.array(YSA)
XU = np.array(XU)
YU = np.array(YU)
XN = np.array(XN)
YN = np.array(YN)

n = np.shape(XS)[0];
i=0;

while(i<n):
    fig, ax = plt.subplots(figsize=(6,6))
    ax.set_facecolor("black")       # fond de l'axe en noir
    fig.patch.set_facecolor("black") # fond de la figure en noir
    ax.set_aspect("equal")
    # Couleurs des labels en blanc
    ax.tick_params(colors='white')
    ax.xaxis.label.set_color(color='white')
    ax.yaxis.label.set_color(color='white')
    
    ax.set_xlim(-6*1e12, 6*1e12)
    ax.set_ylim(-6*1e12, 6*1e12)

    plt.plot(XS[i],YS[i], 'o', color='#FFD700',markersize=6, label="Soleil")
    plt.plot(XV[i],YV[i], 'o', color="#B8860B", markersize=4, label="Venus")
    plt.plot(XT[i],YT[i], 'o', color='#7BC8F6', markersize=4, label="Terre")
    plt.plot(XM[i],YM[i], 'o', color='#FC5A50', markersize=2, label="Mars")
    plt.plot(XJ[i],YJ[i], 'o', color="navajowhite", markersize=8, label="Jupiter")
    plt.plot(XSA[i],YSA[i], 'o', color="lightsalmon", markersize=7, label="Saturne")
    plt.plot(XU[i],YU[i], 'o', color='paleturquoise', markersize=4, label="Uranus")
    plt.plot(XN[i],YN[i], 'o', color='mediumblue', markersize=4, label="Neptune")
    
    plt.legend(("Soleil", "Venus", "Terre", "Mars", "Jupiter", "Saturne", "Uranus", "Neptune"), loc='upper right')
    plt.xlabel("x")
    plt.ylabel("y")
    plt.title('Système Solaire',color='white')
    #plt.grid(color='#808080')
    plt.show()
    
    #plt.savefig("fig{:09d}_SysSol.png".format(i));
    
    i=i+1;