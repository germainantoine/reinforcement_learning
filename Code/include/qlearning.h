#ifndef QLEARNING_H
#define QLEARNING_H

#include "mazeEnv.h"
#include "functions.h"

void matriceQ(float*** pQ);
void iterationQ(float** Q);
int maxQ(int row,int col,float** Q);
int argmaxQ(int row,int col,float** Q);
int newcol(int a, int col);
int newrow(int a, int row);
int recompense(int row,int col);
void solutionQ(float** Q);

#endif