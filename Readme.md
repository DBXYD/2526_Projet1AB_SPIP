# 🐿️ Projet PAMI - Spip  (Coupe de France de Robotique)


##  Présentation de la Coupe
La **Coupe de France de Robotique** (Eurobot Open France) est une compétition annuelle organisée par **Planète Sciences**.  
Elle réunit des équipes étudiantes, associatives ou indépendantes, qui conçoivent des **robots autonomes** capables de relever des défis techniques en lien avec un thème annuel.
Depuis **plus de 10 ans**, l’association **ARES (Association de Robotique de l’ENSEA)** participe chaque année à cette compétition.  
En **2026**, la compétition se déroulera dans le cadre de la **33ᵉ édition des Rencontres de Robotique**.  
Le thème choisi est :  
> **« Winter is coming »**
Les robots auront 100 secondes pour réaliser un maximum d’actions sur une aire de jeu commune de 3 m x 2 m.
## Règlement
Le règlement complet est disponible sur le site officiel ([coupederobotique.fr](https://www.coupederobotique.fr/)), mais voici un résumé des grandes lignes :
### Aire du jeu 
Voici l’aire du jeu officielle de la Coupe de France de Robotique 2026 :
![Aire du jeu ](Strategie/airejeu.png)
Légende :
1. Nid des écureuils  
2. Aires de départ PAMI dans le grenier  
3. Frigo  
4. Zone de chargement  
5. Zone de ramassage  
6. Garde-manger  
7. Thermomètre  
8. Curseur
### 🔹 Objectifs du thème
Les robots doivent aider les écureuils à stocker et protéger leurs noisettes en réalisant différentes actions :

1. **Gardons les noisettes au chaud !**  
   Ramasser les caisses de noisettes et les déposer dans un **garde-manger** ou dans le **nid**.  
   
2. **Trouver, c’est garder !**  
   Utiliser un petit actionneur mobile (PAMI) pour vider les **frigos** du grenier et les remplir avec des **caisses pourries**.  
   
3. **Pas trop chaud, ni trop froid.**  
   Déplacer le **curseur du thermomètre** pour régler la température au plus près du centre.  
   
4. **On est mieux dans son nid.**  
   Finir le match avec le **robot principal dans le nid**.  
   
5. **À table !**  
   Les petits écureuils (PAMIs) doivent rejoindre les **garde-mangers** et « manger » les noisettes.

Voici l'organisation principale du projet :

* 📁 **[Firmware](./Firmware/)** : Contient le code embarqué pour les microcontrôleurs, incluant l'asservissement.
* 📁 **[Hardware](./Hardware/)** : Regroupe les conceptions électroniques (PCB) et les modélisations mécaniques (3D).
* 📁 **[Datasheets](./Datasheets/)** : Contient l’ensemble des datasheets des différents composants utilisés.
* 📁 **[Strategie](./Strategie/)** : Documents et algorithmes définissant le comportement du robot pendant les matchs.
* 📁 **[Tableau de bord](./Tableau%20de%20bord/)** : Outils de monitoring et suivi des indicateurs de l'équipe.
  
  
# Rapport de projet - SPIP

## 1. Introduction

Le projet SPIP consiste a concevoir un robot PAMI pour la Coupe de France de Robotique. Le robot doit être autonome, compact, capable de se déplacer de manière controlée, d'intéragir avec le terrain, d'éviter les obstacles et de réaliser des actions simples pendant le match.

Notre travail a donc porte sur trois grands axes :

- le choix et l'integration des composants;
- la conception electronique du robot avec KiCad;
- le developpement du firmware embarque sur STM32.

Le robot est organisé autour d'une carte électronique principale. Cette carte relie le microcontroleur, les moteurs, les encodeurs, les capteurs, les boutons, les LEDs, le connecteur de programmation et l'actionneur XL-320.

## 2. Objectif global du robot

Le robot doit pouvoir se deplacer de facon autonome sur l'aire de jeu de la Coupe de France de Robotique. Pour cela, nous avons besoin :

- d'un cerveau capable de piloter tous les peripheriques ;
- de deux moteurs ;
- d'encodeurs pour connaitre le deplacement réel ;
- d'un capteur ultrason pour détecter les obstacles ;
- d'un suiveur de ligne infrarouge pour corriger la trajectoire ;
- d'un servomoteur XL-320 pour actionner une partie mobile ;
- d'une carte electronique pour relier tous les élements.

L'architecture generale est la suivante :

```mermaid
flowchart TD
    Batterie["+6 V batterie"] --> Regulateur["Regulateur 3.3 V"]
    Batterie --> Driver["DRV8411 - Driver moteurs"]
    Batterie --> XL320["Dynamixel XL-320"]
    Regulateur --> STM32["STM32G431CBU6"]
    Regulateur --> Capteurs["Capteurs IR / ultrason / boutons / LEDs"]
    STM32 --> Driver
    Driver --> Moteurs["2 moteurs DC"]
    Moteurs --> Encodeurs["Encodeurs"]
    Encodeurs --> STM32
    Capteurs --> STM32
    STM32 --> XL320
    STLINK["Connecteur STDC14 / ST-Link"] --> STM32
```
## 3. Choix des composants

### 3.1 Microcontroleur STM32G431CBU6

Nous avons choisi le **STM32G431CBU6** comme microcontroleur principal du robot.

Datasheet : [Datasheet officielle STMicroelectronics](https://www.st.com/resource/en/datasheet/stm32g431cb.pdf)

Ce composant à été choisi car il correspond bien aux besoins du robot :

- il fonctionne en logique **3.3 V**, ce qui est adapté à notre circuit ;
- il dispose de nombreux GPIO pour connecter les capteurs, boutons, LEDs et signaux moteurs ;
- il intègre plusieurs timers, indispensables pour générer des signaux PWM et lire les encodeurs ;
- il possède des interfaces UART, utiles pour communiquer avec le XL-320 et avec le ST-Link ;
- son coeur ARM Cortex-M4 a 170 MHz offre assez de puissance pour faire tourner l'asservissement, la strategie et les capteurs en parallele.

Dans notre projet, le STM32 sert donc de centre de decision. Il lit les capteurs, calcule les consignes de mouvement, pilote les moteurs et exécute la stratégie de match.

### 3.2 Driver moteur DRV8411APWPR

Pour piloter les deux moteurs DC, nous avons utilise un **DRV8411APWPR**.

Datasheets : [Datasheet Texas Instruments DRV8411](https://www.ti.com/lit/ds/symlink/drv8411.pdf)

Le STM32 ne peut pas alimenter directement les moteurs, car ses broches ne fournissent pas assez de courant. Le DRV8411 joue donc le role d'interface de puissance entre le microcontroleur et les moteurs.

Nous l'avons choisi car :

- il permet de piloter deux moteurs DC avec un seul circuit ;
- il fonctionne avec des signaux logiques compatibles avec le STM32 ;
- il accepte une alimentation moteur separée, ici le rail **+6 V** ;
- il possède une sortie de defaut, notee `FAULT`, permettant au microcontroleur de détecter un probleme ;
- il peut être commandé par des signaux PWM pour régler la vitesse.

Dans le schema KiCad, les signaux importants sont :

- `AIN1` et `AIN2` pour le moteur A ;
- `BIN1` et `BIN2` pour le moteur B ;
- `AOUT1`, `AOUT2`, `BOUT1`, `BOUT2` vers les connecteurs moteurs ;
- `FAULT` vers le STM32 ;
- `AIPROPI` et `BIPROPI` avec des resistances pour la partie mesure/protection du driver.

### 3.3 Moteurs DC avec encodeurs

Le robot utilise deux moteurs DC avec encodeurs intégrés.

Dans le schema KiCad, les connecteurs moteurs sont des connecteurs JST 6 broches :

- `J6` pour un moteur ;
- `J7` pour l'autre moteur.

Chaque connecteur transporte :

- les deux sorties moteur venant du driver ;
- l'alimentation de l'encodeur ;
- la masse ;
- les deux signaux encodeur A et B.

Nous avons choisi des moteurs avec encodeurs car un simple moteur DC ne permet pas de connaitre la distance réelle parcourue. Avec les encodeurs, le STM32 peut compter les impulsions et en déduire :

- la distance parcourue ;
- la vitesse réelle ;
- le sens de rotation ;
- l'erreur entre la consigne et le mouvement reel.

Cela permet de faire un asservissement et d'obtenir des deplacements plus précis.

### 3.4 Servomoteur Dynamixel XL-320

Le robot utilise un **Dynamixel XL-320** comme actionneur pour une partie mobile, notamment la queue.

Datasheet : [Documentation ROBOTIS officielle](https://emanual.robotis.com/docs/en/dxl/x/xl320/)

Nous avons choisi le XL-320 car c'est un servomoteur intelligent. Contrairement a un servo simple, il integre déjà :

- un moteur ;
- un contrôleur ;
- une electronique de puissance ;
- un protocole de communication ;
- un retour d'état.

Il se commande avec une liaison serie half-duplex. Dans KiCad, il est relie par le connecteur `J3`, avec :

- `+6V` pour l'alimentation ;
- `GND` ;
- `DATA` pour la communication.

Dans le `.ioc`, la broche `PC4` est configuree en `USART1` half-duplex pour communiquer avec le XL-320.

### 3.5 Capteur ultrason HC-SR04

Le capteur ultrason est utilisé pour détecter les obstacles devant le robot.

Datasheets : [Datasheet HC-SR04 via DigiKey](https://www.digikey.com/en/htmldatasheets/production/3822706/0/0/1/hc-sr04.html)

Nous l'avons ajouté pour que le robot puisse s'arrêter lorsqu'un objet ou un autre robot se trouve trop près. Le principe est simple :

- le STM32 envoie une impulsion sur `TRIG` ;
- le capteur émet une onde ultrasonore ;
- le signal `ECHO` reste actif pendant une duree proportionnelle a la distance ;
- le STM32 mesure cette duree et calcule la distance.

Dans KiCad, le capteur est relie au connecteur `J4` :

- `+3.3V` ;
- `TRIGG` ;
- `ECHO` ;
- `GND`.

Dans le code, si la distance mesuree est inferieure a 10 cm, le robot met les deux vitesses moteur a zero. Cela permet d'eviter une collision.

### 3.6 Suiveur de ligne infrarouge

Le suiveur de ligne infrarouge est utilise pour detecter la position du robot par rapport a une ligne au sol.

Dans KiCad, le connecteur `J5` relie le module infrarouge au STM32 :

- `+3.3V` ;
- `X1` ;
- `X2` ;
- `X3` ;
- `X4` ;
- `GND`.

Nous avons choisi un suiveur de ligne a plusieurs sorties car il donne plus d'information qu'un seul capteur. Avec quatre signaux, le robot peut savoir si la ligne est :

- centrée ;
- decalée à gauche (légèrement ou fortement);
- decalée à droite (légèrement ou fortement);
- perdue ou detectée partiellement.

Dans le firmware, les valeurs des quatre capteurs sont combinées dans une variable `position`. Cette position est ensuite utilisée dans `move_update` pour corriger la vitesse des roues.

### 3.7 Regulateur AZ1117-3.3

Le régulateur **AZ1117-3.3** permet de creer le rail d'alimentation 3.3 V à partir de l'alimentation principale.

Datasheet : [Datasheet officielle AZ1117](https://www.diodes.com/assets/Datasheets/AZ1117.pdf)

Nous l'avons ajouté car le STM32 et plusieurs signaux logiques doivent etre alimentés en 3.3 V, alors que la partie puissance du robot fonctionne avec une tension plus elevée, notamment le rail +6 V.

Dans KiCad, le regulateur est accompagné de condensateurs de decouplage et de stabilisation. Ces condensateurs servent à limiter les variations de tension et à rendre l'alimentation plus stable.

### 3.8 Condensateurs de découplage

Le schéma KiCad contient plusieurs condensateurs :

- `100nF` près des circuits intégrés ;
- `1uF`, `10uF` et `22uF` pour stabiliser les rails d'alimentation ;
- des condensateurs autour du driver moteur et du régulateur.

Datasheets :

- [Wurth 100 nF 885012205085](https://www.we-online.com/components/products/datasheet/885012205085.pdf)
- [Wurth 10 nF 885012205067](https://www.we-online.com/components/products/datasheet/885012205067.pdf)
- [Wurth 1 uF 885012206076](https://www.we-online.com/components/products/datasheet/885012206076.pdf)
- [Wurth 22 uF 885012107019](https://www.we-online.com/components/products/datasheet/885012107019.pdf)

Ces condensateurs sont nécessaires car les moteurs et les circuits numériques peuvent créer des variations rapides de courant. Sans découplage, ces variations pourraient provoquer des resets du microcontroleur ou des comportements instables.

### 3.9 Résistances

Le PCB utilise plusieurs resistances :

- resistances de tirage pour les boutons ;
- resistances en serie avec les LEDs ;
- resistances liees au driver moteur ;
- resistance de `BOOT0` ;
- resistances de valeurs particulieres comme `82k5`.

Datasheets :

- [Yageo RC0805 general purpose](https://www.yageo.com/upload/media/product/productsearch/datasheet/rchip/PYu-RC_Group_51_RoHS_L_12.pdf)
- [RS Pro 1 kOhm](https://docs.rs-online.com/21eb/0900766b8157cb45.pdf)

Les resistances de LEDs sont dimensionnees pour limiter le courant. Les annotations du schema indiquent les tensions directes des LEDs, par exemple `1.7V @ 1mA`, `2.3V @ 1mA` ou `2.6V @ 1mA`. Le but est d'avoir des voyants visibles sans consommer trop de courant ni endommager les LEDs.

### 3.10 LEDs utilisateur

Le PCB contient plusieurs LEDs, reliées à des signaux comme :

- `LEDR` ;
- `LEDG` ;
- `LEDB`.

Datasheets :

- [LED rouge Wurth 150060RS55040](https://www.we-online.com/components/products/datasheet/150060RS55040.pdf)
- [LED verte Wurth 150060GS55040](https://www.we-online.com/components/products/datasheet/150060GS55040.pdf)
- [LED bleue Wurth 150060BS55040](https://www.we-online.com/components/products/datasheet/150060BS55040.pdf)

Nous les avons ajoutées pour faciliter les tests. Elles peuvent indiquer un état du robot, un mode de fonctionnement, une erreur ou une étape de stratégie.

### 3.11 Boutons utilisateur

Le PCB contient plusieurs boutons, associés aux signaux :

- `Button1` ;
- `Button2` ;
- `Button3`.

Ils permettent de déclencher manuellement des actions, de changer d'état ou de lancer une séquence de test. Dans le `.ioc`, ces boutons sont configurés en interruptions externes, ce qui permet au STM32 de réagir immédiatement a un appui.


### 3.12 Connecteur de programmation STDC14

Le connecteur `J2` est un connecteur **STDC14**. Il sert a programmer et déboguer le STM32 avec un ST-Link.

Documentation :

- [Documentation STDC14 / STLINK-V3](https://www.st.com/content/ccc/resource/technical/document/user_manual/group1/99/49/91/b6/b2/3a/46/e5/DM00526767/files/DM00526767.pdf/jcr:content/translations/en.DM00526767.pdf)

Il relie notamment :

- `SWDIO` ;
- `SWCLK` ;
- `NRST` ;
- `STLINK_TX` ;
- `STLINK_RX` ;
- `3.3V` ;
- `GND`.

Nous l'avons mis pour pouvoir flasher le programme, deboguer le code et utiliser une liaison UART avec l'ordinateur.

## 4. Explication du projet KiCad

Le projet KiCad se trouve dans :

- [Schema KiCad](./Hardware/Kicad_SPIP/Kicad_SPIP.kicad_sch)
- [PCB KiCad](./Hardware/Kicad_SPIP/Kicad_SPIP.kicad_pcb)

Le schéma est organisé en blocs fonctionnels :

- alimentation générale ;
- STM32G431CBU6 ;
- driver + moteurs ;
- servo XL-320 ;
- ultrason ;
- infrarouge ;
- boutons ;
- LEDs ;
- programmateur ;
- trous de fixation.

Cette organisation permet de comprendre rapidement le rôle de chaque partie.

### 4.1 Bloc alimentation

Le bloc alimentation sépare deux niveaux de tension :

- `+6V` pour les éléments de puissance, comme les moteurs et le XL-320 ;
- `+3.3V` pour le STM32 et les signaux logiques.

Le régulateur transforme la tension principale en 3.3 V. Des condensateurs sont placés autour des rails d'alimentation pour éviter les chutes de tension lors des appels de courant.

### 4.2 Bloc STM32

Le STM32 est au centre du schéma. Les pins sont nommées selon leur rôle logiciel :

- `PA0-US_TRIG` ;
- `PA1-US_ECHO_INT` ;
- `PA4-X1_INT` a `PA7-X4_INT` ;
- `PC4-UART_XL320` ;
- `PB10-MotorFault` ;
- `PB4/PB5` pour l'encodeur du moteur A ;
- `PB6/PB7` pour l'encodeur du moteur B ;
- `PA15/PB3/PA9/PA10` pour les PWM moteur ;
- `PA13/PA14` pour le debug SWD.

Le fait de nommer les signaux directement dans KiCad rend le schéma plus lisible et facilite la correspondance avec le fichier `.ioc`.

### 4.3 Bloc driver moteur

Le bloc moteur contient le DRV8411 et les connecteurs moteurs. Le STM32 envoie des signaux PWM au driver, et le driver fournit le courant aux moteurs.

Nous avons séparé la partie commande et la partie puissance :

- le STM32 commande avec des signaux logiques ;
- le driver gère le courant moteur ;
- les encodeurs renvoient l'information de mouvement au STM32.

Cette séparation est indispensable, car elle protège le microcontroleur et permet un pilotage plus précis.

### 4.4 Bloc capteurs

Le bloc capteurs regroupe l'ultrason et les capteurs infrarouges.

L'ultrason est utilisé pour l'évitement d'obstacles. Les capteurs infrarouges servent à suivre une ligne ou à detecter un décalage lateral.

Dans le PCB, ces capteurs sont connectés par des JST. Cela permet de démonter ou remplacer facilement un capteur sans ressouder la carte.

### 4.5 Bloc interface utilisateur

Les boutons et les LEDs permettent de tester le robot sans avoir besoin de modifier le code à chaque fois. Les boutons peuvent lancer des actions, et les LEDs peuvent afficher l'état du robot.

Ce bloc est utile pendant les phases de debug, car il donne un retour visuel immédiat.

### 4.6 Routage du PCB

Dans le PCB, les composants principaux sont placés de manière à limiter les longueurs de pistes :

- le STM32 est proche des signaux logiques ;
- le driver moteur est proche des connecteurs moteurs ;
- les connecteurs capteurs sont en bord de carte pour faciliter le cablage ;
- les trous de fixation permettent une integration propre dans le chassis.

Les rails `GND`, `+3.3V` et `+6V` sont clairement séparés dans les nets KiCad. Cela permet de distinguer la puissance moteur de la logique microcontroleur.

## 5. Configuration STM32CubeIDE et fichier `.ioc`

Le fichier de configuration est :

- [Firware_SPIP.ioc](./Firmware/Firware_SPIP/Firware_SPIP.ioc)

Ce fichier relie la conception electronique au code embarqué. Il indique quel pin du microcontroleur correspond à chaque fonction.

### 5.1 Horloge

Le STM32 est configuré avec une fréquence système de **170 MHz**. Cette frequence permet d'avoir assez de precision pour :

- les PWM moteurs ;
- la mesure ultrason ;
- les timers d'interruption ;
- l'asservissement.

### 5.2 TIM2 pour les PWM moteurs

Le timer `TIM2` est utilisé avec quatre canaux PWM :

- `TIM2_CH1` : `MotorA_PWM_Forward` ;
- `TIM2_CH2` : `MotorA_PWM_Reverse` ;
- `TIM2_CH3` : `MotorB_PWM_Forward` ;
- `TIM2_CH4` : `MotorB_PWM_Reverse`.

Ce choix permet de gérer le sens et la vitesse des deux moteurs. Chaque moteur à deux commandes, une pour le sens avant et une pour le sens arrière.

### 5.3 TIM3 et TIM4 pour les encodeurs

Les timers `TIM3` et `TIM4` sont configurés en mode encodeur :

- `TIM3` lit l'encodeur du moteur A ;
- `TIM4` lit l'encodeur du moteur B.

Le mode encodeur permet au microcontroleur de compter automatiquement les impulsions A/B des encodeurs, ce qui donne une mesure fiable du mouvement.

### 5.4 TIM1 pour l'ultrason

Le timer `TIM1` est utilisé pour mesurer la durée du signal `ECHO` du capteur ultrason. Son prescaler permet d'obtenir une base de temps adaptée a la mesure en microsecondes.

Cette mesure est ensuite convertie en distance.

### 5.5 TIM6 comme ordonnanceur periodique

Le timer `TIM6` déclenche regulierement une interruption. Dans cette interruption, le programme :

- déclenche l'ultrason ;
- met à jour le suiveur de ligne ;
- met à jour les encodeurs ;
- met à jour l'asservissement ;
- met à jour le mouvement ;
- remet periodiquement à zero l'erreur cumulée du correcteur.

Cela permet de faire fonctionner plusieurs sous-systemes en parallèle.

### 5.6 USART1 pour le XL-320

`USART1` est configuré en half-duplex sur `PC4`. Cela correspond au fonctionnement du XL-320, qui utilise une seule ligne de données pour envoyer et recevoir.

### 5.7 USART2 pour le ST-Link

`USART2` utilise `PA2` et `PA3`. Cette liaison peut servir au debug avec le ST-Link, par exemple pour afficher des informations sur un terminal serie.

### 5.8 Interruptions externes

Plusieurs pins sont configurées en interruptions :

- `US_ECHO_INT` pour détecter les fronts du signal ultrason ;
- `MotorFault` pour détecter un problème driver ;
- les boutons utilisateur.

Les interruptions permettent de reagir rapidement à des évenèments sans attendre la boucle principale.

## 6. Explication du firmware

Le code embarqué se trouve dans :

- [Core/Src](./Firmware/Firware_SPIP/Core/Src)
- [Core/Inc](./Firmware/Firware_SPIP/Core/Inc)

Le firmware est séparé en modules. Chaque module gère une partie précise du robot.

### 6.1 `motor.c` et `motor.h`

Le module moteur gère le PWM applique aux moteurs. Il transforme une consigne de vitesse finale en rapport cyclique PWM.

Nous avons séparé ce module car le pilotage bas niveau des moteurs doit être indépendant de la stratégie. La stratégie dit au robot quoi faire, tandis que `motor.c` applique physiquement la puissance aux moteurs.

### 6.2 `encoder.c` et `encoder.h`

Le module encodeur lit les compteurs des timers en mode encodeur. Il calcule les variations de ticks entre deux appels.

Ces ticks sont essentiels pour connaitre le mouvement réel. Sans encodeur, le robot pourrait dériver à cause des différences entre les moteurs, du frottement ou de la batterie.

### 6.3 `control.c` et `control.h`

Le module d'asservissement compare la vitesse demandée avec la vitesse mesurée par les encodeurs.

Le code calcule une erreur :

```c
error = control->ref_speed - 1000 * encoder->delta_ticks;
```

Puis il applique une correction proportionnelle et integrale :

```c
motor->speed_final = control->ref_speed
                   + (control->Kp * error)
                   + (control->Ki * control->error_cumul);
```

Nous avons utilisé ce principe car les deux moteurs ne tournent jamais exactement pareil. L'asservissement permet de corriger les écarts et d'obtenir un mouvement plus régulier.

### 6.4 `move.c` et `move.h`

Le module mouvement gère les ordres de haut niveau :

- avancer d'une certaine distance ;
- tourner d'un certain angle ;
- s'arreter ;
- adapter la vitesse en fonction du suiveur de ligne ;
- s'arreter en cas d'obstacle ultrason.

La fonction `move_forward` convertit une distance en centimetres en ticks encodeur. Pour cela, on utilise le périmetre de la roue :

```c
float perimeter_cm = 2.0f * M_PI * move->radius;
float K = encoder->cnt_tr / perimeter_cm;
move->d_target_cnt = d_target_cm * K;
```

Cette conversion permet de donner des ordres simples en centimetres tout en utilisant les encodeurs en interne.


### 6.5 Correction par suiveur de ligne

Nous avons ajout" une correction de trajectoire dans `move_update`. Le principe est de lire la position donnée par le suiveur de ligne infrarouge et d'adapter les vitesses des deux roues.

Si la ligne est detectée a gauche, on ralentit la roue gauche et on accelère la roue droite. Si la ligne est détectée a droite, on fait l'inverse. Quand la ligne revient au centre, on remet la vitesse initiale.


Cette partie a ete ajoutée car le robot ne roule pas toujours parfaitement droit. Les petites differences mécaniques entre les moteurs ou les roues peuvent créer une dérive. Le suiveur infrarouge permet donc de corriger cette dérive en temps réel.

### 6.6 `Line_Follower.c` et `Line_Follower.h`

Le module suiveur de ligne lit les quatre entrees infrarouges :

```c
lf->position = lf->sensor_values[0] * 1000
             + lf->sensor_values[1] * 100
             + lf->sensor_values[2] * 10
             + lf->sensor_values[3];
```

Cette methode permet de transformer quatre lectures digitales en une seule valeur facile à comparer. Par exemple :

- `0110` devient `110`, consideré comme centre ;
- `1000` indique une detection a gauche ;
- `0001` indique une detection a droite.

### 6.7 `Ultrasound.c` et `Ultrasound.h`

Le module ultrason gère le capteur HC-SR04. Il déclenche le capteur, mesure le temps du signal echo et calcule la distance.

Dans `move_update`, la sécurite obstacle est prioritaire :

```c
if (us_sensor->distance_cm > 0.0f && us_sensor->distance_cm < 10.0f) {
    control_set_speed(control_left, 0);
    control_set_speed(control_right, 0);
    return;
}
```

Nous avons fait cela pour que le robot s'arrete immediatement si un obstacle est trop proche.

### 6.8 `xl320.c` et `xl320.h`

Le module XL-320 initialise et commande le servomoteur Dynamixel.

Dans `main.c`, le XL-320 est initialisé avec l'UART puis configure :

```c
XL320_Init(&huart1);
XL320_Config_LowPower(254);
XL320_SetSpeed(254, 300);
```

L'identifiant `254` correspond a un broadcast, ce qui permet d'envoyer une commande a tous les servos connectes.

### 6.9 `strategy.c` et `strategy.h`

Le module strategie definit une suite d'actions. Par exemple, la strategie `yellow_one` enchaine :

- une phase d'initialisation ;
- un premier déplacement en ligne droite ;
- un virage ;
- un second déplacement ;
- une fin de sequence.


Nous avons choisi une machine à états car elle permet de décrire clairement la séquence de match. Chaque état correspond à une action précise, et le robot passe à l'état suivant lorsque l'action est terminée.

### 6.10 `main.c`

Le fichier `main.c` initialise tous les modules :

- capteur ultrason ;
- suiveur de ligne ;
- moteurs ;
- encodeurs ;
- mouvement ;
- asservissement ;
- strategie ;
- XL-320.

La boucle principale appelle la strategie et le mouvement de la queue :

```c
while (1)
{
    yellow_one(&status);
    move_tail(&status_tail);
}
```

Les mises a jour rapides sont faites dans l'interruption de `TIM6`, ce qui permet de garder un comportement régulier.

## 7. Résumé 

Nous avons séparé le code en modules pour rendre le projet plus lisible et plus facile à tester.

Chaque fichier à une responsabilité :

- `motor` pilote le PWM ;
- `encoder` lit les ticks ;
- `control` fait l'asservissement ;
- `move` gere les distances et les rotations ;
- `Line_Follower` lit les capteurs IR ;
- `Ultrasound` mesure les distances ;
- `xl320` commande le servomoteur ;
- `strategy` decide les actions ;
- `main` initialise et orchestre le systeme.

Ce decoupage évite d'avoir tout le code dans un seul fichier et facilite les corrections.

## 8. Conclusion

Le projet SPIP combine une partie électronique, une partie mécanique et une partie logicielle. La carte KiCad à été concue pour centraliser les connexions du robot autour du STM32G431CBU6. Le choix des composants repond aux besoins principaux : puissance moteur, mesure de position, détection d'obstacle, suivi de ligne, communication avec le servomoteur et debug.

Le firmware transforme cette architecture matérielle en comportement autonome. Les encodeurs permettent de mesurer le mouvement, l'asservissement corrige les erreurs de vitesse, le suiveur infrarouge corrige la trajectoire, l'ultrason évite les obstacles, et la stratégie enchaine les actions du robot.

L'ensemble du travail permet d'obtenir une base de robot autonome capable de se deplacer, se corriger, réagir a son environnement et exécuter une séquence de match.
