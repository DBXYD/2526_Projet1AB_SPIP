#  Détails de Conception Électronique

Ce document rassemble les spécifications techniques, les calculs de dimensionnement
des composants passifs et les choix de routage pour le PCB du robot SPIP.

---

## 1. Inventaire des Besoins Matériels

Pour répondre aux exigences du cahier des charges de la Coupe de France de Robotique,
l'architecture matérielle du PAMI intègre les éléments suivants :

- **Motorisation & Puissance :**
  - 2 Moteurs DC avec encodeurs (via 2 connecteurs JST 6 broches).
  - 1 Driver de puissance **DRV8411APWPR** (alimenté en `+3.3V` et `+6V`).
  - 1 Connecteur double pour la batterie principale `+6V`.
- **Contrôle & Programmation :**
  - 1 Microcontrôleur **STM32G431CBU6** (`+3.3V`).
  - 1 Connecteur **STDC14** dédié au flashage et au debug SWD/UART.
- **Interface Utilisateur :**
  - 4 Boutons poussoirs (Reset du STM32 et sélection des stratégies de match).
  - 5 LEDs d'état pour le monitoring visuel.
- **Capteurs & Actionneurs :**
  - 1 Capteur ultrason pour l'évitement d'obstacles (connecteur 4 broches).
  - 1 Module infrarouge pour le suivi de ligne (connecteur 6 broches).
  - 1 Servomoteur intelligent **Dynamixel XL-320** (`+6V`, connecteur 3 broches).
- **Gestion des tensions :**
  - 1 Régulateur abaisseur LDO **AZ1117CH-3.3TRG1** (`6V` → `3.3V`).
  - Des réseaux de résistances, condensateurs de découplage et bobines de protection.

---

## 2. Dimensionnement des Composants Passifs

Les valeurs des composants discrets ont été rigoureusement déterminées à partir
des recommandations des datasheets constructeurs.

### Calcul des résistances de limitation pour les LEDs

Pour assurer un indicateur visuel net sans surconsommation, le courant cible a été
fixé à $I = 1\ \text{mA}$ sous une tension d'alimentation logique de
$U_{\text{cc}} = 3.3\ \text{V}$.

La formule de calcul appliquée est :

$$R = \frac{U_{\text{cc}} - U_{\text{led}}}{I}$$

- **LED Bleue** ($U_{\text{led}} = 2.6\ \text{V}$) :

$$\frac{3.3\ \text{V} - 2.6\ \text{V}}{0.001\ \text{A}} = 700\ \Omega \quad \Rightarrow \quad \text{Valeur normalisée : } \mathbf{680\ \Omega}$$

- **LED Rouge** ($U_{\text{led}} = 1.7\ \text{V}$) :

$$\frac{3.3\ \text{V} - 1.7\ \text{V}}{0.001\ \text{A}} = 1600\ \Omega \quad \Rightarrow \quad \text{Valeur normalisée : } \mathbf{1.6\ \text{k}\Omega}$$

- **LED Verte** ($U_{\text{led}} = 2.3\ \text{V}$) :

$$\frac{3.3\ \text{V} - 2.3\ \text{V}}{0.001\ \text{A}} = 1000\ \Omega \quad \Rightarrow \quad \text{Valeur normalisée : } \mathbf{1\ \text{k}\Omega}$$

### Choix des boîtiers CMS (Composants Montés en Surface)

- **Condensateurs :** Formats **0402, 0603 et 0805**. Ces boîtiers sont parfaitement
  adaptés puisque les tensions sur la carte restent inférieures à `10V`.
- **Résistances :** Formats **0402 et 0805**.
- **Vérification de la puissance dissipée :** Dans le pire des cas, la puissance
  calculée reste très faible :

$$P < 3.3\ \text{V} \times 5\ \text{mA} = 16.5\ \text{mW}$$

Cette valeur est largement inférieure à la puissance maximale admissible par les
boîtiers 0402 ($63\ \text{mW}$) et 0805 ($125\ \text{mW}$).

---

## 3. Stratégie de Routage du PCB (KiCad)

Le routage a fait l'objet de règles strictes pour limiter le bruit thermique,
les chutes de tension et garantir l'intégrité des signaux :

1. **Topologie de la carte :** Circuit imprimé conçu en **4 couches** pour optimiser
   le placement.
2. **Distribution des masses :** Création d'un plan de masse général (`GND`) et d'un
   plan de puissance (`PSU`) distincts.
3. **Largeur des pistes de puissance :** Les pistes transportant les alimentations
   (`GND`, `+6V` et `+3.3V`) ont été élargies pour minimiser l'impédance de ligne.
4. **Lignes Moteurs :** Toutes les liaisons reliant les connecteurs moteurs aux sorties
   du driver **DRV8411** ont été surdimensionnées en largeur pour supporter les pointes
   de courant lors des appels de charge (démarrage et blocage des moteurs).