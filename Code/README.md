# Projet d'IN104 : Apprentissage par renforcement : Antoine GERMAIN et Alexandre NOURY

        ORGANISATION DU DOSSIER

Le dossier ApprentissageRenforcement est composé de 3 dossiers :
        - data : dossier contenant des fichiers texte contenant la représentation de labyrinthes ainsi que leurs dimensions ;
        - include : dossier contenant l'ensemble des fichiers .h relatifs aux fichiers .c du dossier src ;
        - src : dossier contenant tous les fichiers .c permettant la résolution d'un labyrinthe quelconque décrit au format des fichiers présents dans le dossier data à l'aide de fonctions d'apprentissage par renforcement ;

et de 2 fichiers :
        - Makefile : fichier Makefile permettant l'exécution du programme appliquant l'apprentissage par renforcement à la résolution du labyrinthe ; 
        - README.md : fichier détaillant l'organisation du dossier ApprentissageRenforcement et son utilisation.

Le dossier data est composé de :
        - maze.txt : fichier texte représentant un labyrinthe de dimensions 12x20.

Le dossier include est composé de :
        - dfs.h : fichier .h relatif au fichier dfs.c du dossier src ;
        - functions.h : fichier .h relatif au fichier functions.c du dossier src ;
        - mazeEnv.h : fichier .h relatif au fichier mazeEnv.c du dossier src ;
        - qlearning.h : fichier .h relatif au fichier qlearning.c du dossier src.

Le dossier src est composé de :
        - dfs.c : fichier .c mettant en place une résolution récursive du labyrinthe, permettant la comparaison avec la solution obtenue par apprentissage par renforcement ;
        - functions.c : fichier .c contenant différentes fonctions annexes, communes quelque soit le type de résolution ;
        - mazeEnv.c : fichier .c contenant les fonctions décrivant l'environnement d'un labyrinthe, communes quelque soit le type de résolution ;
        - qlearning.c : fichier .c mettant en place une résolution par apprentissage par renforcement du labyrinthe à l'aide de plusieurs fonctions.

        UTILISATION DU DOSSIER

Exécuter dans l'ordre en étant dans le dossier ApprentissageRenforcement/ : 
        - make clean (clean le dossier )
        - make (créer les exécutables)
        - cd src (se déplacer dans le dossier src)
        - ./qlearning (exécuter le fichier qlearning pour résoudre un labyrinthe)
        - nomLabyrinthe (renseigner le nom du labyrinthe qu'on souhaite résoudre dans le scanf)