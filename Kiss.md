# Kiss of Chess
> warning: the rest of this document is in French

## Déroulement général

### Les echecs

Les échecs sont un jeu de stratégie combinatoire abstrait pour deux joueurs. Le but du jeu est de mettre le roi adverse en échec et mat, c'est-à-dire de menacer son roi d'une attaque imparable. Le jeu se déroule sur un plateau de 64 cases, alternativement claires et sombres, nommées les cases blanches et les cases noires. Les joueurs disposent chacun de seize pièces au début de la partie : un roi, une dame, deux tours, deux fous, deux cavaliers et huit pions. Les pièces sont de deux couleurs, ou camps : les pièces blanches et les pièces noires. Les joueurs déplacent leurs pièces à tour de rôle sur une case voisine selon des règles bien précises.

#### découpage du déroulement

- tour blanc
    - déplacement des pièces blanches
    - vérification de l'échec et mat du roi noir
- tour noir
    - déplacement des pièces noires
    - vérification de l'échec et mat du roi blanc

##### si le roi est en échec et mat
- fin de la partie

#### le plateau de jeu

modélisation du plateau par une matrice de 8x8 cases.

#### les pièces

Chaque pièce a un object dérivé de la classe `Piece` et qui contient la couleur de la pièce.

### les modes de jeu

#### le mode classique

Le mode classique est le mode de jeu le plus connu. Il se joue à deux joueurs, chacun ayant un camp de 16 pièces. Le but du jeu est de mettre le roi adverse en échec et mat, c'est-à-dire de menacer son roi d'une attaque imparable. Le jeu se déroule sur un plateau de 64 cases, alternativement claires et sombres, nommées les cases blanches et les cases noires. Les joueurs disposent chacun de seize pièces au début de la partie : un roi, une dame, deux tours, deux fous, deux cavaliers et huit pions. Les pièces sont de deux couleurs, ou camps : les pièces blanches et les pièces noires. Les joueurs déplacent leurs pièces à tour de rôle sur une case voisine selon des règles bien précises. 

en mode PvP en local , et en mode PvIA 

#### le mode replay

le mode replay permet de rejouer une partie d'échecs enregistrée. il ne se joue pas, il permet de rejouer une partie d'échecs enregistrée.

## Les fonctionnalités

### le menu principal

Le menu principal permet de choisir entre les différents modes de jeu , accéder aux options et permet aussi de quitter le jeu. 

- Play : permet de choisir entre les différents modes de jeu
    - PvP : permet de jouer en local contre un autre joueur
    - PvIA : permet de jouer contre une IA
    - Replay : permet de rejouer une partie d'échecs enregistrée
- Quit : permet de quitter le jeu

### Partie PvP en local

La partie PvP en local permet de jouer à deux joueurs sur le même ordinateur.

Chaqu'un son tour, les joueurs doivent pouvoir déplacer leurs pièces en cliquant dessus puis en cliquant sur la case où ils veulent la déplacer en respectant les règles du jeu.
Puis à la fin de chaque tour, le jeu doit vérifier si le roi du joueur adverse est en échec ou non, si c'est le cas, le jeu doit rendre la case du roi adverse rouge. Si le roi est en échec et mat, le jeu doit change vers l'écran de fin de partie.

### Partie PvIA

La partie PvIA permet de jouer contre une IA.

Le joueur doit pouvoir déplacer ses pièces en cliquant dessus puis en cliquant sur la case où il veut la déplacer en respectant les règles du jeu.

L'IA doit pouvoir déplacer ses pièces en respectant les règles du jeu.

Puis à la fin de chaque tour, le jeu doit vérifier si le roi du joueur adverse est en échec ou non, si c'est le cas, le jeu doit rendre la case du roi adverse rouge. Si le roi est en échec et mat, le jeu doit change vers l'écran de fin de partie.

### l'écran de fin de partie

l'ecran de fin de partie permet de voir le résultat de la partie.
enregistrer la partie si c'est une partie PvP en local ou PvIA.
revenir au menu principal.

### le replay

le replay permet de rejouer une partie d'échecs enregistrée.
avec un fichier de partie enregistrée, le jeu doit pouvoir la rejouer.


