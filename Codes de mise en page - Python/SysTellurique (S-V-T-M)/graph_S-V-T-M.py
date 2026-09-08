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
XV = [];
YV = [];
XT = [];
YT = [];
XM = [];
YM = [];

with open("Resultats_S-V-T-M_LONG.txt", "r", encoding="utf-8") as R:
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

plt.plot(XS,YS, 'o', color='#FFD700',markersize=8, label="Soleil")
plt.plot(XV,YV, color="#B8860B", linewidth=0.11, label="Venus")
plt.plot(XT,YT, color='#7BC8F6', linewidth=0.2, label="Terre")
plt.plot(XM,YM, color='#FC5A50', linewidth=0.3, label="Mars")

# zoom Venus
ax.set_xlim(0.7625*1e11, 0.7638*1e11)
ax.set_ylim(0.7625*1e11, 0.7638*1e11)

# zoom Terre
#ax.set_xlim(1.0575*1e11, 1.0585*1e11)
#ax.set_ylim(1.0575*1e11, 1.0585*1e11)

# zoom Mars
#ax.set_xlim(1.6094*1e11, 1.610*1e11)
#ax.set_ylim(1.6094*1e11, 1.610*1e11)


plt.legend(("Soleil", "Venus", "Terre", "Mars"))
plt.xlabel("x")
plt.ylabel("y")
plt.title('Planètes Telluriques',color='white')
plt.grid(color='#808080')
plt.show()