# 🗓️ Tableau de Bord - Projet SPIP

Ce fichier recense l'avancée du projet, les décisions prises et les objectifs pour les prochaines séances.


---

## 📅 Séance du Jeudi 05 Février 2026
**Objectif :** Initialisation du projet et définition du hardware.

### ✅ Réalisations
- **Hardware** : Validation de la liste des composants (STM32G431, XL320, encodeurs, capteurs).
- **Outils** : Création du répertoire GitHub et collecte des datasheets.

---

## 📅 Séance du Jeudi 12 Février 2026
**Objectif :** Conception du PCB et organisation.

### ✅ Réalisations
- **Électronique** : Début de la schématique et assignation des pins.
- **Gestion** : Mise en place du planning et structuration du répertoire GitHub.

---

## 📅 Séance du Jeudi 19 Février 2026
**Objectif :** Finalisation de la conception électronique et inventaire.

### ✅ Réalisations
- **Conception PCB (KiCad)** : 
    - Finalisation de la schématique et validation par l'encadrement (Mr. Papazoglou).
    - Calcul des résistances de protection pour les LED.
    - Routage du PCB en cours de finalisation.
- **Décision Structurelle** : 
    - Choix technique : le PCB sera une carte indépendante fixée à la coque par vissage pour plus de fiabilité.
- **Logistique** : 
    - Inventaire du stock et finalisation de la liste des composants à commander.
- **Logiciel** : 
    - Établissement de la liste des commandes de contrôle.

---

## 🚀 Objectifs Séance Suivante
- **Production** : Lancer la fabrication du PCB après vérification finale.
- **Mécanique** : Concevoir les points de fixation du PCB sur la coque du robot.
- **Code** : Débuter l'implémentation de la communication avec les servomoteurs XL320.

Voici le texte corrigé et structuré en **Markdown**, prêt à être copié dans ton fichier :


## 📅 Séance du Jeudi 09 Avril 2026
**Objectif :** Mise en commun des fichiers de code et correction des problèmes existants.

### ✅ Réalisations
- **Corrections** : 
    - Normalisation de la syntaxe du code en **anglais**.
    - Correction de la direction : le robot, qui ne pouvait tourner qu'à gauche, tourne désormais également à droite.
- **Mise en commun** : 
    - Les moteurs, les encodeurs, le capteur ultrason, le suiveur de ligne et le servo moteur xl320 fonctionnent tous en **parallèle** (le robot roule pendant que l'ultrason et le suiveur de ligne renvoient des données et le xl320 fait des va et vient).
    - Le robot s'arrête dans son mouvement lorsqu'il rencontre un obstacle et le reprend quand il ne le détecte plus.
    
- **Tests sur table** :
    - Création d'un `switch case yellowone` afin d'atteindre la première zone du côté jaune.

---

## 🚀 Objectifs Séance Suivante
- Mise en place opérationnelle du suiveur de ligne.
- Correction de la précision : le robot ne roule pas parfaitement droit, il faut donc corriger cette erreur.

