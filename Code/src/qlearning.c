#include "qlearning.h"

/*Données*/
float alpha=0.8; //facteur d'apprentissage
float mazegamma=1; //facteur d'actualisation
float epsilon=0.1; //chance de choisir aléatoirement une direction dans la politique epsilon-greedy
/*Récompenses*/
int arrivée = 100;
int mur = -1000;
int deplacement=-1;
int piege = -5;

/*Initialisation de la matrice Q*/
void matriceQ(float*** pQ) {
    *pQ=malloc(rows*cols*sizeof(float*));
    /*On note les cases dans le sens de lecture*/
    for (int i=0;i<rows*cols;i++) {
        (*pQ)[i]=malloc(4*sizeof(float));
        for (int j=0;j<4;j++) {
            (*pQ)[i][j]=0;
        }
    }
}

/*Algorithme d'entrainement*/
void iterationQ(float** Q) {
    int current_row=start_row;
    int current_col=start_col;
    /*On explore jusqu'à trouver l'arrivée*/
    while (current_row!=goal_row || current_col!=goal_col) {
        int test=1;
        int a;
        int new_row;
        int new_col;
        /*Choix de l'action suivant politique epsilon-greedy*/
        while (test==1) {
        float p = rand()/RAND_MAX;
        if (p>epsilon){
            a = argmaxQ(current_col, current_row, Q);
        }
        else {
            a = rand()%4;
        }
        new_row=newrow(a, current_row);
        new_col=newcol(a, current_col);
        /*Si on n'est pas sortis du labyrinthe on peut continuer l'exploration*/
        if (new_row != -1 && new_row != rows && new_col != -1 && new_col != cols) {
            test = 0;
        } 
        }
        Q[(current_row)*cols+current_col][a]=(1-alpha)*Q[(current_row)*cols+current_col][a]+alpha*(recompense(new_row, new_col)+mazegamma*maxQ(new_row, new_col, Q));
        current_row=new_row;
        current_col=new_col;
    }
}

/*Constitution du chemin grâce à la matrice Q*/
void solutionQ(float** Q) {
    int current_row=start_row;
    int current_col=start_col;
    int a;
    /*Q étant construite il suffit de chercher la récompense maximale pour savoir où aller*/
    while (current_row!=goal_row || current_col!=goal_col) {
        a = argmaxQ(current_row, current_col, Q);
        current_row=newrow(a,current_row);
        current_col=newcol(a,current_col);
        mazeEnv[current_row][current_col]='.';
    }
    mazeEnv[current_row][current_col]='g';
}

/*Trouve la meilleure récompense disponible autour de la case donnée*/
int maxQ(int row,int col,float** Q) {
    int maximum=Q[(row)*cols+col][0];
    for (int i=1;i<4;i++) {
        maximum=max(maximum,Q[(row)*cols+col][i]);
    }
    return maximum;
}

/*Idem mais en renvoyant l'action correspondante*/
int argmaxQ(int row,int col,float** Q) {
    int maximum=Q[(row)*cols+col][0];
    int arg=0;
    for (int i=1;i<4;i++) {
        if (Q[(row)*cols+col][i]>=maximum) {
            arg=i;
            maximum = Q[(row)*cols+col][i];
        }
    }
    return arg;
}

/*Permet de donner la nouvelle colonne après une action
  haut,droite,bas,gauche <=> 0,1,2,3 pour a */
int newcol(int a, int col) {
    if (a==1) {
        return col+1;
    }
    if (a==3) {
        return col-1;
    }
    return col;
}

/*Idem pour les lignes*/
int newrow(int a, int row) {
    if (a==2) {
        return row+1;
    }
    if (a==0) {
        return row-1;
    }
    return row;
}

/*Renvoie la récompense associée à une case*/
int recompense(int row,int col) {
    if (mazeEnv[row][col] == '+') {
        return mur;
    }
    if (mazeEnv[row][col] == 'g') {
        return arrivée;
    }
    if (mazeEnv[row][col] == '-') {
        return piege;
    }
    return deplacement;
}

int main() {
    char mot[20]; // Déclaration d'une variable pour stocker le mot (20 est la taille maximale du mot)
    char nomLabyrinthe[100]; // Déclaration d'une variable pour stocker le chemin vers le labyrinthe
    printf("Veuillez renseigner le labyrinthe : ");
    scanf("%s", mot);
    sprintf(nomLabyrinthe, "../data/%s.txt", mot);

    mazeEnv_make(nomLabyrinthe);
    mazeEnv_render();
    float** Q;
    matriceQ(&Q);
    for (int iteration = 0;iteration<100;iteration++) {
        iterationQ(Q); 
    }
    
    solutionQ(Q);
    
    /*
    int current_row=start_row;
    int current_col=start_col;
    int a;
    int nbtests = 20;
    int numerotest = 0;
    while ((current_row!=goal_row || current_col!=goal_col) && (numerotest<nbtests)) {
        printf("%d (%d,%d)\n",numerotest,current_row,current_col);
        printf("%g\n",Q[(current_row)*cols+current_col][0]);
        printf("%g\n",Q[(current_row)*cols+current_col][1]);
        printf("%g\n",Q[(current_row)*cols+current_col][2]);
        printf("%g\n",Q[(current_row)*cols+current_col][3]);
        a = argmaxQ(current_row, current_col, Q);
        printf("action %d\n",a);
        current_row=newrow(a,current_row);
        current_col=newcol(a,current_col);
        mazeEnv[current_row][current_col]='.';
        numerotest++;
    }
    */

    mazeEnv_render();

    for (int i=0;i<rows*cols;i++) {
        free(Q[i]);
    }
    free(Q);
    
    return 0;
}
