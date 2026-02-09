# 📚 Centre de Documentation Technique - SPIP

Ce répertoire centralise toutes les fiches techniques (datasheets) des composants utilisés sur le robot Spip. **Consultation obligatoire** avant toute manipulation électronique ou modification du code bas niveau.

## 🧠 Microcontrôleur (Cerveau)
- **STM32G431CBU6** : [Lien vers le PDF local](./STM32G431CBU6_Datasheet.pdf)
  - *Points clés* : Tension 3.3V, 128KB Flash, Pins FT (5V tolerant) à vérifier sur le Pinout.

## ⚙️ Actionneurs (Moteurs & Servos)
- **Moteurs DC + Encodeurs** : [Spécifications Moteurs](./actuators/moteurs_propulsion.pdf)
  - *Infos* : Rapport de réduction, résolution des encodeurs (ticks/tour).
- **Dynamixel XL320** : [Manuel Utilisateur](./XL-320.pdf)
  - *Infos* : Protocole Dynamixel 2.0, Couple 0.39 N.m, Tension 7.4V.

## 🛰️ Capteurs
- **Capteur Ultrason (HC-SR04)** : [Datasheet](./HC-SR04.pdf)
  - *Attention* : Sortie Echo en 5V (nécessite un pont diviseur pour le STM32).
- **Capteurs de ligne (IR)** : [Datasheet](./sensors/ir_line_sensor.pdf)

## ⚡ Alimentation & Drivers
- **Driver Moteur (Xl320)** : [Documentation](./Driver_DATASHEET.pdf)
- **Régulateur de tension** : [Step-down 5V/3.3V](./power/regulator.pdf)

---
> **Note aux développeurs** : Si vous ajoutez un composant sur le robot, merci d'ajouter sa datasheet ici et de mettre à jour ce fichier.