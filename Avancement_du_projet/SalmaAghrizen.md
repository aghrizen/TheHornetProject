## Semaine 1: 20/09/23
Dans la première semaine du travail dans le projet, 
nous avons commencé par comprendre ce que l'ancient groupe a fait.
nous avons commencé par comprendre ce que l'ancien groupe a fait.

  Tout d'abord, nous avons essayé de tester le code qui sert 
  a manipuler la caméra qui prends les photos des frelons:                                                                                       
- Il s'agit d'un code sur Arduino. Nous avons le compilé, il n'y avait aucune erreure.
  Tout d'abord, nous avons essayé de tester le code qui permet 
  de manipuler la caméra qui prends les photos des frelons:                                                                                       
- Il s'agit d'un code sur Arduino. Nous avons pu le compilé sans problème.


- Puis, pour voir s'il marche avec la carte, nous avons 
    utilisé les deux cartes que nous aviez: une fonctionne bien mais l'autre non.                                                                                                                                                                            
-  Nous avons essayé de refaire le soudage de quelques fils de l'autre
 carte qui n'a pas fonctionné, mais nous avons pas réussir.
- Puis, nous l'avons testé sur les deux cartes en notre possession : une fonctionne parfaitement mais l'autre nous sort une erreur avec le lecteur de carte SD (les 2 cartes ont été testées avec la même carte sd).                                                                                                                                                                            
-  Nous avons essayé de refaire le soudage de quelques fils de la 
 carte défectueuse sans succés.

  La deuxième chose c'était de faire un test sur le code qui manipule le moteur:                                                                           
-  Il n'a pas fonctionné puisuq'il y avait des problèmes de 
    positionnement du moteur et de voltage (le nombre de volte de la carte et du moteur).
  Par la suite, avec la carte fonctionnelle, nous avons testé le code "testmoteur" qui permet de manipuler le moteur:                                                                           
-  Problèmes observés :
    - Voltage 3.3V (max uc) au lieu de 4.8V - 6V. Toutefois, le moteur fonctionne même à ce voltage. Le seul problème est que les valeurs données par le constructeur, comme par ex la vitesse de rotation en °/s ont été mesuré à ces valeurs. Nous devrons donc le recalculer avec 3.3V. Deplus, le code fournit utilise des pwn avec des fréquences incorrectes pour faire tourner le moteur. Résultat le moteur bloqué à 60° force pour continuer. 
    Pour le fonctionnement voulu, nous n'avons pas besoin de PWN car la rotation est un événément inopiné et variable donc nous devrions avoir la possibilité de controler sa durée à l'état haut à tout moment. Remplacement par une simple pin DigitalOut. Nous calculerons la durée d'attente entre l'état haut et l'état bas en fonction de la distance avec la cible.
    Le défaut de cette méthode est que nous "bloquons le proccess" pendant la rotation. Mais ce temps est négligeage car il s'agit de 0.1 - 0.3s. Les frelons volent en stationnaire, nous n'avons pas besoin d'une réponse rapide mais bien d'une réponse précise.
