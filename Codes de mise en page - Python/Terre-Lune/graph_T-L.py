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

T = [];
L = [];

with open("Resultat_T-L.txt", "r", encoding="utf-8") as R:
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

#ax.set_xlim(2.7124*1e8, 2.713*1e8)
#ax.set_ylim(2.7384*1e8, 2.739*1e8)

#ax.set_xlim(2.71*1e8, 2.72*1e8)
#ax.set_ylim(2.73*1e8, 2.74*1e8)

#ax.set_xlim(3.485*1e6, 3.486*1e6)
#ax.set_ylim(1.507*1e6, 1.508*1e6)

plt.plot(xT_vals,yT_vals, color='#7BC8F6', linewidth=1, label="Terre")
plt.plot(xL_vals,yL_vals, color='#929591', linewidth=1, label="Lune")

#plt.legend(("Terre", "Lune"))
plt.xlabel("x")
plt.ylabel("y")
plt.title('Terre-Lune',color='white')
plt.grid(color='#808080')
plt.show()