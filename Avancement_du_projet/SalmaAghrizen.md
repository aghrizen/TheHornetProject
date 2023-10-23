## Semaine 1: 20/09/23
Dans la première semaine du travail dans le projet, 
nous avons commencé par comprendre ce que l'ancien groupe a fait.


  Tout d'abord, nous avons essayé de tester le code qui permet 
  de manipuler la caméra qui prends les photos des frelons:                                                                                       
- Il s'agit d'un code sur Arduino. Nous avons pu le compilé sans problème.

- Puis, nous l'avons testé sur les deux cartes en notre possession : une fonctionne parfaitement mais l'autre nous sort une erreur avec le lecteur de carte SD (les 2 cartes ont été testées avec la même carte sd).                                                                                                                                                                            
-  Nous avons essayé de refaire le soudage de quelques fils de la 
 carte défectueuse sans succés.


  Par la suite, avec la carte fonctionnelle, nous avons testé le code "testmoteur" qui permet de manipuler le moteur:                                                                           
-  Problèmes observés :
    - Voltage 3.3V (max uc) au lieu de 4.8V - 6V. Toutefois, le moteur fonctionne même à ce voltage. Le seul problème est que les valeurs données par le constructeur, comme par ex la vitesse de rotation en °/s ont été mesuré à ces valeurs. Nous devrons donc le recalculer avec 3.3V. Deplus, le code fournit utilise des pwn avec des fréquences incorrectes pour faire tourner le moteur. Résultat le moteur bloqué à 180° force pour continuer. 
    Pour le fonctionnement voulu, nous n'avons pas besoin de PWN car la rotation est un événément inopiné et variable donc nous devrions avoir la possibilité de controler sa durée à l'état haut à tout moment. Remplacement par une simple pin DigitalOut. Nous calculerons la durée d'attente entre l'état haut et l'état bas en fonction de la distance avec la cible.

    Le défaut de cette méthode est que nous "bloquons le proccess" pendant la rotation. Mais ce temps est négligeage car il s'agit de 0.1 - 0.3s. Les frelons volent en stationnaire, nous n'avons pas besoin d'une réponse rapide mais bien d'une réponse précise.


## Semaine 2: 17/10/2023
Dans la deuxième semaine, nous avons tester une nouvelle carte qui prend les photos des frelons. 

-  En fait, celle-ci est mieux que l'autre que nous avons tester la dernière fois, car, elle permet de détecter les mouvements grace à un capteur intégré: en fonction des mouvements, elle prend les photos. Pour faire fonctionner le code, nous avons installer la bibliothèque EloquentSurveillance de Arduino, version 13, pour éviter toute erreur de la compilation.

-  Deuxième chose que nous avons fait, c'était d'essayer de résoudre le problème que nous avons observé la dernière fois dans le code du moteur.
-  Après avoir corriger le code avec les valeurs correctes et les instructions valides, nous avons trouver un autre problème qui empêche le bon fonctionnement du moteur et qui le bloque: le courant était insuffisant pour alimenter le moteur, il refait chaque fois la fonction setup() sans entrer dans la boucle. Donc, il faut utiliser une alimentation pour lui alimenter et éviter son bloquage.

Objectifs pour la semaine prochaine: 
- Utiliser une alimentation pour alimenter le moteur et le faire fonctionner avec les bonnes valeurs des angles.
- Fixer la carte caméra de détection dans la boite.
