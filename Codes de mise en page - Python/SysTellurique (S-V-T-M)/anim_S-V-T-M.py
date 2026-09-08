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

with open("Resultats_S-V-T-M.txt", "r", encoding="utf-8") as R:
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
        XS.append(xS)
        YS.append(yS)
        XV.append(xV)
        YV.append(yV)
        XT.append(xT)
        YT.append(yT)
        XM.append(xM)
        YM.append(yM)

XS = np.array(XS)
XT = np.array(XT)
XM = np.array(XM)
YS = np.array(YS)
YT = np.array(YT)
YM = np.array(YM)
XV = np.array(XV)
YV = np.array(YV)

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
    
    ax.set_xlim(-3*1e11, 3*1e11)
    ax.set_ylim(-3*1e11, 3*1e11)
    
    plt.plot(XS[i],YS[i], 'o', color='#FFD700', markersize=15, label="Soleil")
    plt.plot(XV[i],YV[i], 'o', color='#B8860B', markersize=8, label="Venus")
    plt.plot(XT[i],YT[i], 'o', color='#7BC8F6', markersize=8, label="Terre")
    plt.plot(XM[i],YM[i], 'o', color='#FC5A50', markersize=4, label="Mars")

    plt.legend(("Soleil", "Venus", "Terre", "Mars"), loc='upper left')
    plt.xlabel("x")
    plt.ylabel("y")
    plt.title('Planetes Telluriques',color='white')
    
    #plt.show()
    plt.savefig("fig{:09d}_S-V-T-L.png".format(i));
    
    i=i+4;