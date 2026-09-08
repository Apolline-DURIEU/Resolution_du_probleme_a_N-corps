# -*- coding: utf-8 -*-
"""
Created on Mon Dec  1 14:49:17 2025

@author: apoll
"""

from matplotlib import pyplot as plt
import numpy as np

fig, ax = plt.subplots(figsize=(6,6))
ax.set_facecolor("black")       # fond de l'axe en noir
fig.patch.set_facecolor("black") # fond de la figure en noir
ax.set_aspect("equal")
# Couleurs des labels en blanc
ax.tick_params(colors='white')
ax.xaxis.label.set_color(color='white')
ax.yaxis.label.set_color(color='white')

XS = [];
YS = [];
XT = [];
YT = [];
XL = [];
YL = [];

with open("Resultats_S-T-L.txt", "r", encoding="utf-8") as R:
    for ligne in R:
        colonnes = ligne.split()  # découpe par espace ou tabulation
        if len(colonnes) < 7:
            continue
        xS = float(colonnes[1])      # 2e colonne (index 1)
        yS = float(colonnes[2])     # 3e colonne (index 2)
        xT = float(colonnes[3])      # 2e colonne (index 1)
        yT = float(colonnes[4])  
        xL = float(colonnes[5])   
        yL = float(colonnes[6])
        XS.append(xS)
        YS.append(yS)
        XT.append(xT)
        YT.append(yT)
        XL.append(xL)
        YL.append(yL)

XS = np.array(XS)
XT = np.array(XT)
XL = np.array(XL)
YS = np.array(YS)
YT = np.array(YT)
YL = np.array(YL)

# Séparer X et Y

ax.set_xlim(-1.7*1e11, 1.7*1e11)
ax.set_ylim(-1.7*1e11, 1.7*1e11)

plt.plot(XS,YS, 'o', color='#FFD700', markersize=8, label="Soleil")
plt.plot(XT,YT, 'o', color='#069AF3', markersize=5,label="Terre")
plt.plot(XL,YL, 'o', color='#C0C0C0', markersize=1, label="Lune")

plt.legend(("Soleil", "Terre", "Lune"))
plt.xlabel("x")
plt.ylabel("y")
plt.title('Soleil-Terre-Lune', color='white')
plt.grid(color='#808080')
plt.show()