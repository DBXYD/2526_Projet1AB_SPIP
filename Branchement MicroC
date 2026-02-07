# Cablage STM32G431CBU6 (UFQFPN48)   (non fini)

## 1. Alimentation & debug

### Alimentation STM32
- **VDD (toutes les broches VDD)** → +3,3 V
- **VDDA** → +3,3 V (via petit filtre RC si possible)
- **VSS / VSSA** → GND
- **Découplage** : 100 nF entre chaque VDD/VDDA et GND, au plus près des pins

### Programmation / Debug (SWD)
- **PA13** → SWDIO (vers SWDIO du ST-Link)
- **PA14** → SWCLK (vers SWCLK du ST-Link)
- **NRST** → NRST du ST-Link  
  - Pull-up 10 kΩ vers 3,3 V  
  - Bouton poussoir vers GND (optionnel)
- **GND** → GND du programmateur
- **VDD** → pin de référence tension du programmateur (3,3 V sense)

---

## 2. Moteur 1

### PWM Moteur 1 
- **PA6** → TIM3_CH1 → Entrée PWM_A du driver moteur 1
- **PA7** → TIM3_CH2 → Entrée PWM_B / Direction du driver moteur 1

### Encodeur Moteur 1
- **PB4** → TIM3_CH1 → Canal A encodeur moteur 1
- **PB5** → TIM3_CH2 → Canal B encodeur moteur 1

Remarques :
- Configurer **TIM3** en mode **PWM** sur CH1/CH2 pour la commande.
- Configurer **TIM3** en mode **encodeur**.

---

## 3. Moteur 2

### PWM Moteur 2 (commande driver)
- **PA2** → TIM15_CH1 → Entrée PWM_A du driver moteur 2
- **PA3** → TIM15_CH2 → Entrée PWM_B / Direction du driver moteur 2

### Encodeur Moteur 2
- **PB6** → TIM4_CH1 → Canal A encodeur moteur 2
- **PB7** → TIM4_CH2 → Canal B encodeur moteur 2

Remarques :
- Configurer **TIM15** en **PWM** (CH1/CH2).
- Configurer **TIM4** en **mode encodeur** pour le moteur 2.

---

## 4. Dynamixel XL-320 (queue rotative)

Le Dynamixel XL-320 utilise un bus série **TTL half-duplex**.

### UART côté STM32
- **PA9** → USART1_TX
- **PA10** → USART1_RX

### Liaison avec le bus Dynamixel
- **PA9 (TX)** → driver half-duplex → ligne **DATA** du XL-320
- **PA10 (RX)** ← driver half-duplex ← ligne **DATA** du XL-320
- **GND STM32** ↔ **GND XL-320**
- **Alimentation XL-320** : tension recommandée (ex : 7,4 V) selon la doc Dynamixel

> Le driver half-duplex est un petit montage électronique (transistor / circuits logiques) qui permet d’utiliser TX/RX sur un **seul fil DATA** compatible Dynamixel.

---

## 5. Capteur ultrason (type HC-SR04)

### Câblage
- **PA0** → TRIG (sortie STM32 vers entrée TRIG du module)
- **PA1** → ECHO (entrée STM32 depuis la sortie ECHO du module)

Remarque importante :
- Si **ECHO** est en **5 V**, utiliser :
  - un **diviseur de tension** (par ex. 10 kΩ / 15 kΩ)
  - ou un **convertisseur de niveau logique**
- PA1 peut être associée à un **timer input capture** pour mesurer précisément la durée de l’impulsion.

---

## 6. Capteur suiveur de ligne

(On suppose 3 capteurs, adaptable à plus si besoin.)

### Câblage proposé
- **PC0** → Sortie capteur ligne 1
- **PC1** → Sortie capteur ligne 2
- **PC2** → Sortie capteur ligne 3

Remarques :
- Si les capteurs sortent un **signal numérique (0/1)** :
  - Configurer PC0, PC1, PC2 en **entrée avec pull-up** (ou utiliser les pull-up internes).
- Si les capteurs sortent un **signal analogique** :
  - Configurer PC0, PC1, PC2 en **entrées ADC** (selon les canaux disponibles sur le STM32G431).

Pour 5 capteurs :
- Capteur 4 → **PC3**
- Capteur 5 → **PC4**

---

## 7. Résumé rapide des pins utilisés

### Alimentation / Debug
- VDD, VDDA → 3,3 V
- VSS, VSSA → GND
- PA13 → SWDIO
- PA14 → SWCLK
- NRST → Reset + pull-up + bouton (optionnel)

### Moteur 1
- PA6 → PWM M1 (TIM3_CH1)
- PA7 → PWM M1 (TIM3_CH2)
- PB4 → Encodeur M1 A (TIM3_CH1)
- PB5 → Encodeur M1 B (TIM3_CH2)

### Moteur 2
- PA2 → PWM M2 (TIM15_CH1)
- PA3 → PWM M2 (TIM15_CH2)
- PB6 → Encodeur M2 A (TIM4_CH1)
- PB7 → Encodeur M2 B (TIM4_CH2)

### Dynamixel XL-320
- PA9 → USART1_TX → driver half-duplex → DATA XL-320
- PA10 → USART1_RX ← driver half-duplex ← DATA XL-320
- GND commun entre STM32 et XL-320
- Alim XL-320 (ex : 7,4 V)

### Capteur ultrason
- PA0 → TRIG
- PA1 → ECHO (avec adaptation de niveau si 5 V)

### Suiveur de ligne
- PC0 → Capteur 1
- PC1 → Capteur 2
- PC2 → Capteur 3
(+ éventuellement PC3, PC4 pour capteurs 4 et 5)
