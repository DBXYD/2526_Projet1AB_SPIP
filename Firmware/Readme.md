# 💻 Firmware de Spip

Ce dossier contient le projet STM32CubeIDE. Le code est structuré pour gérer l'asservissement des moteurs et la communication avec le XL320.

## 📌 Configuration des Pins (STM32G431CBU6)

| Fonction | Pin | Config / Timer |
| :--- | :--- | :--- |
| **Moteur 1 (PWM)** | PA6 / PA7 | TIM3_CH1 / CH2 |
| **Moteur 2 (PWM)** | PA2 / PA3 | TIM15_CH1 / CH2 |
| **Encodeur 1** | PB4 / PB5 | TIM3 (Mode Encoder) |
| **Encodeur 2** | PB6 / PB7 | TIM4 (Mode Encoder) |
| **Queue (XL320)** | PA9 / PA10 | USART1 (Half-Duplex) |
| **Suiveur Ligne** | PC0, PC1, PC2 | GPIO Input / ADC |
| **Ultrason (Trigger)** | PA0 | GPIO Output |
| **Ultrason (Echo)** | PA1 | GPIO Input / TIM |
| **Debug SWD** | PA13 / PA14 | SWDIO / SWCLK |
