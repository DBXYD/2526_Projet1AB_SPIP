# 🗓️ Tableau de Bord - Projet SPIP (PAMI - Coupe de France de Robotique)

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

## 📅 Séance du Jeudi 12 Mars 2026
**Objectif :** Validation finale du PCB, commande et initiation de la CAO.

### ✅ Réalisations
- **Électronique (KiCad)** : Vérification finale des règles de routage (DRC) et génération des fichiers Gerber. Lancement officiel de la commande du PCB.
- **Mécanique** : Début de la modélisation 3D sur logiciel de CAO. Conception de la première version de la structure globale du PAMI (Modélisation n°1) en prenant en compte l'encombrement des moteurs et des batteries.

---

## 📅 Séance du Jeudi 19 Mars 2026
**Objectif :** Préparation des composants et optimisation mécanique.

### ✅ Réalisations
- **Logistique** : Session d'inventaire et recherche de l'intégralité des composants électroniques physiques au FabLab pour préparer l'assemblage dès réception du PCB.
- **Mécanique** : Analyse critique de la modélisation n°1. Ajustements des points de fixation et optimisation de l'espace pour le servomoteur XL320. Création de la Modélisation n°2.

---

## 📅 Séance du Jeudi 26 Mars 2026
**Objectif :** Réception du PCB, soudage et câblage.

### ✅ Réalisations
- **Électronique** : Réception des cartes nues au FabLab de l'ENSEA. Séance complète de soudage des composants (STM32, connecteurs, résistances de protection des LED).
- **Câblage** : Début des opérations de sertissage et de soudure des câbles d'alimentation, des moteurs et des capteurs pour garantir des connexions robustes.

---

## 📅 Vacances & Séance du Jeudi 02 Avril 2026
**Objectif :** Développement intensif du code de bas niveau (moteurs et capteurs).

### ✅ Réalisations
- **Code (Moteurs & Encodeurs)** : Travail majeur sur l'asservissement des moteurs et la lecture des encodeurs (étape chronophage pour obtenir un comportement stable).
- **Code (Capteurs)** : Implémentation logicielle du capteur ultrason (détection des obstacles) et du suiveur de ligne.
- **Intégration** : Premiers tests de l'électronique soudée sur le châssis issu de la modélisation n°2. Identification de premiers bugs électroniques liés aux pistes/liaisons de la carte.

---

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

## 📅 Séance du Jeudi 16 Avril 2026
**Objectif :** Débogage matériel et fiabilisation avant la Coupe.

### ✅ Réalisations
- **Électronique** : Session de débogage intense sur la carte PCB pour régler les problèmes électriques qui perturbaient le comportement global du robot.
- **Gestion de projet** : Ralentissement volontaire du rythme des nouvelles fonctionnalités pour se concentrer sur la robustesse du système existant à l'approche imminente de la Coupe de France de Robotique.

---

## 🚀 Objectifs Séance Suivante
- Mise en place opérationnelle du suiveur de ligne en conditions réelles.
- Correction de la précision : le robot ne roule pas parfaitement droit, ajuster l'asservissement des moteurs pour corriger cette dérive.
- Finaliser les tests d'homologation sur la table officielle (gestion du timing des 100 secondes).