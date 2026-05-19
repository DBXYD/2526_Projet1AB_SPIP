# Bienvenue dans l'espace de travail de Lucas

## Commentaires sur le projet PAMI

Nous avons besoin pour notre PAMI (Petit Automate Mobile Indépendant) de :

- Deux moteurs avec encodeur  
  → Driver DRV8411APWPR (ayant besoin de 3.3V et 6 V) + 2 connecteurs 6 broches
- Notre processeur STM32G431CBU6 (qui a besoin de 3.3 V )
- Programmateur  
  → Connecteur Conn_ST_STDC14
- Boutons pour le reset du STM32 et la sélection de stratégie  
  → 4 boutons
- LEDs pour vérifier les états de la carte  
  → 5 LEDs
- Broche d’alimentation générale  
  → Connecteur double pour la batterie 6 V
- Capteurs et actionneurs :  
  - Ultrason (évitement) → Connecteur 4 broches  
  - Infrarouge (suiveur de ligne) → Connecteur 6 broches  
  - Servomoteur Dynamixel XL320 (qui a besoin de 6 V) → Connecteur 3 broches
- Abaisseur de tension (6 V → 3.3 V), AZ1117CH-3.3TRG1 pour alimenter le processeur
- Résistances, condensateurs et bobines pour protéger les différents éléments


## Choix des résistances, condensateurs et bobines

Les valeurs sont déterminées à partir des datasheets (recommendation donnée).

### Calcul des résistances pour LEDs

Tension d’alimentation : 3.3 V  
Courant visé : 1 mA

- LED bleue :  
  (3.3 - 2.6) / 1 mA = 0.7 kΩ => 680 Ω

- LED rouge :  
  (3.3 - 1.7) / 1 mA = 1.6 kΩ => 1.6 kΩ

- LED verte :  
  (3.3 - 2.3) / 1 mA = 1 kΩ => 1 kΩ


## Choix des tailles des composants CMS

### Condensateurs
- Formats 0402, 0603, 0805  
  → Adaptés car les tensions sont < 10 V

### Résistances
- Formats 0805 et 0402

### Vérification de la puissance

P < 3.3 V x 5 mA = 16.5 mW

→ Compatible avec les boîtiers 0402 et 0805


## Routage du PCB sur KiCad

Pour garantir le bon fonctionnement de la carte, les choix suivants ont été appliqués :

- Circuit imprimé en 4 couches
- Création d'un plan de masse général (GND) et de puissance (PSU)
- Largeur de piste augmentée pour la masse (GND) et les lignes de tension (6 V et 3.3 V)
- Largeur de piste augmentée pour toutes les liaisons reliant les moteurs au driver DRV8411 afin de supporter la puissance 