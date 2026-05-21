# Rapport de travail Rayan - Projet SPIP


Dans le cadre du projet SPIP, j’ai participé à plusieurs parties du développement du robot, à la fois sur l’électronique, la configuration matérielle et le code embarqué. Mon travail a porté sur la recherche des composants, leur sélection, la préparation hardware du robot, la configuration du microcontrôleur et l’intégration d’une correction de trajectoire à partir du suiveur de ligne infrarouge.

## Recherche des composants

Au début du projet, j’ai réalisé les recherches de datasheets des différents composants électroniques utilisés. Cette étape m’a permis d’identifier les caractéristiques techniques importantes de chaque composant, comme les tensions d’alimentation, le rôle des broches, les interfaces de communication, les contraintes de câblage et les conditions d’utilisation.

Ces recherches étaient nécessaires pour vérifier que les composants choisis étaient compatibles avec le microcontrôleur, les capteurs, les moteurs et l’alimentation du robot.

## Choix et commande du matériel

J’ai également pris en charge le choix des composants électroniques nécessaires au projet ainsi que la commande du matériel. Pour cela, j’ai tenu compte des caractéristiques techniques des composants, de leur compatibilité avec le reste du système, de leur disponibilité et de leur utilité dans l’architecture globale du robot.

Cette étape a permis de préparer la partie matérielle du projet avant l’assemblage et les tests.

## Configuration du projet dans le fichier `.ioc`

J’ai travaillé sur la configuration du projet dans le fichier `.ioc` de STM32CubeIDE. Ce fichier permet d’associer les broches du microcontrôleur aux différents périphériques utilisés dans le robot.

J’ai identifié à quoi correspondait chaque broche et je les ai associées aux éléments matériels du robot, notamment :

- les moteurs ;
- les encodeurs ;
- les capteurs infrarouges du suiveur de ligne ;
- le capteur ultrason ;
- les timers ;
- les interfaces de communication ;
- les autres entrées/sorties nécessaires au fonctionnement du robot.

Cette étape était importante pour assurer une cohérence entre le câblage réel du robot, la configuration du microcontrôleur et le code généré par STM32CubeIDE.

## Soudure du PCB

J’ai participé à la partie électronique du projet en réalisant la soudure du PCB permettant l'intégration de celui-ci dans le robot.

La soudure du PCB a permis de rendre la carte exploitable pour les tests matériels et pour la connexion avec les différents éléments du robot.

## Mesures du plateau de jeu

J’ai également réalisé les mesures de distances du plateau de jeu utilisé pour la Coupe de France de Robotique. Ces mesures ont permis de mieux connaître les dimensions du terrain et les contraintes liées aux déplacements du robot.

Ces informations sont utiles pour adapter la stratégie, les trajectoires, les distances de déplacement et le positionnement du robot pendant les phases de jeu.

## Intégration du suiveur de ligne infrarouge

J’ai travaillé sur l’intégration du suiveur de ligne infrarouge dans la gestion du mouvement du robot. L’objectif était que le robot puisse adapter automatiquement sa trajectoire en fonction de la position détectée par les capteurs infrarouges.

Le suiveur de ligne lit l’état de plusieurs capteurs infrarouges et calcule une position. Cette position indique si la ligne est centrée sous le robot, décalée à gauche ou décalée à droite.

## Modification de la fonction `move_update`

La fonction principale modifiée est `move_update`. Cette fonction est appelée régulièrement pendant le fonctionnement du robot. Elle gère déjà l’arrêt en cas d’obstacle, l’avancement, la rotation et l’arrêt du robot.

J’ai ajouté un nouveau paramètre à cette fonction afin qu’elle puisse recevoir les informations du suiveur de ligne.

## Rédaction du rapport 

Enfin, j'ai pris en charge la rédaction du rapport global du projet. Ce rapport explique l'ensemble du travail réalisé par le groupe, les choix techniques effectués, le rôle des composants utilisés, les liens vers les datasheets, ainsi que l'explication du schéma KiCad, du PCB, du fichier .ioc et du code embarqué. L'objectif était de produire un document complet permettant de comprendre ce qui à été fait dans le projet et pourquoi chaque choix à été realisé.


