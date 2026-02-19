# 💻 Firmware de Spip

Ce dossier contient le projet STM32CubeIDE. Le code est structuré pour gérer l'asservissement des moteurs, la lecture des capteurs et la communication avec le servomoteur XL320.

## 📌 Configuration des Pins (STM32G431CBUx)

| Catégorie | Fonction | Pin | Label / Utilisation |
| :--- | :--- | :--- | :--- |
| **Moteurs (PWM)** | Moteur A (Fwd/Rev) | PA15 / PB3 | MotorA_PWM_Forward / Reverse |
| | Moteur B (Fwd/Rev) | PA9 / PA10 | MotorB_PWM_Forward / Reverse |
| **Encodeurs** | Encodeur Moteur A | PB4 / PB5 | MotorA_ENC_A / ENC_B |
| | Encodeur Moteur B | PB6 / PB7 | MotorB_ENC_A / ENC_B |
| **Com. & Debug** | Queue (XL320) | PC4 | UART_XL320 (Half-Duplex) |
| | Debug SWD | PA13 / PA14 | SWDIO / SWCLK |
| | UART Debug | PA2 / PA3 | UART_STLINK_TX / RX |
| **Capteurs** | Ultrason | PA0 / PA1 | US_TRIG / US_ECHO_INT |
| | Interruptions Ext. | PA4, PA5, PA6, PA7 | X1_INT, X2_INT, X3_INT, X4_INT |
| **I/O Utilisateur**| Boutons | PB12, PB13, PB14 | USR_BTN_1, 2, 3 |
| | LEDs | PA8, PC6, PB15 | USR_LED_1, 2, 3 |
| **Sécurité** | Fault Moteur | PB10 | MotorFault Input |

---

## 🛠️ État d'avancement du Code

- [x] Initialisation du projet CubeIDE (STM32G431CBUx).
- [x] Mapping complet des Pins (IOC).
- [x] Définition de la structure des commandes.
- [ ] Implémentation du driver PWM pour les moteurs.
- [ ] Implémentation du driver pour le suiveur de ligne .
- [ ] Implémentation du driver pour le capteur Ultra-Son.
- [ ] Communication UART avec le XL320.

---

## 🚀 Prochaine étape
Développer les fonctions de base pour faire avancer le robot et tester la remontée des encodeurs sur le terminal série via le ST-Link.