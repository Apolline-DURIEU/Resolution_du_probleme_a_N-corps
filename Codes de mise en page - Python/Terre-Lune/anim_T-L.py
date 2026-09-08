# -*- coding: utf-8 -*-
"""
Created on Mon Dec  1 14:49:17 2025

@author: apoll
"""

from matplotlib import pyplot as plt
import numpy as np
from PIL import Image

T = [];
L = [];

with open("Resultats_T-L.txt", "r", encoding="utf-8") as R:
    for ligne in R:
        colonnes = ligne.split()  # découpe par espace ou tabulation
        if len(colonnes) < 5:
            continue
        xT = float(colonnes[1])      # 2e colonne (index 1)
        yT = float(colonnes[2])     # 3e colonne (index 2)
        xL = float(colonnes[3])   
        yL = float(colonnes[4])  
        T.append([xT, yT])
        L.append([xL, yL])

T = np.array(T)
L = np.array(L)

# Séparer X et Y
xT_vals = T[:, 0]
yT_vals = T[:, 1]
xL_vals = L[:, 0]
yL_vals = L[:, 1]

n = np.shape(xT_vals)[0];
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
    
    ax.set_xlim(-4*1e8, 4*1e8)
    ax.set_ylim(-4*1e8, 4*1e8)
    
    plt.plot(xT_vals[i*5],yT_vals[i*5], 'o', color='#7BC8F6', markersize=12, label="Terre")
    plt.plot(xL_vals[i*5],yL_vals[i*5], 'o', color='#808080', markersize=5, label="Lune")

    plt.legend(("Terre", "Lune"), loc='upper left')
    plt.xlabel("x")
    plt.ylabel("y")
    plt.title('Terre-Lune',color='white')
    #plt.grid(color='#808080')
    #plt.savefig("fig{:09d}_T-L.png".format(i));
    plt.show()
    
    i=i+10;