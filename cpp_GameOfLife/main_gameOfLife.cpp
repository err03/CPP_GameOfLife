//============================================================================
// Name        : w6_project_gameOfLife.cpp
// Author      : Yang,WeiBin ; Zhou,XuanMing
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>

#include "Graph.h"
#include "DetermineFunctions.h"
#include "Cell.h"
using namespace std;

extern char cell;		//extern the cell from cell.cpp
extern char lives[ROW][COL];	//extern the lives from cell.cpp, ROW and COL is in graph.h

int generationTime = 99;	//how many generation time you want?
int main() {
	int generation = 0;
	generateCell();
	cout << "Generation:" << generation<< endl;
	drawGraph();
//	int i=1,c=2;
	for(int g=0;g<generationTime ;g++){

		for(int i=0;i<ROW;i++){
			for(int c=0;c<COL;c++){
				if(lives[i][c] == cell){	//if this index have cell
					if(determineDeath(i,c)){	//determine the death
						lives[i][c] = ' ';
					}else{
						lives[i][c] = cell;		//if near cell have 2, keep it
					}//if else
				}else{						//else this index have no cell
					if(determineBirth(i,c)){	//determine the birth
						lives[i][c] = cell;
					}//if
				}//if else -current index have cell or not
			}//for_loop the Column
		}//for_loop the Row

		generation++;

		cout << "Generation:" << generation<< endl;
		drawGraph();

		if(determineNoMoreCell()){
			exit(0);
		}//if the no more cell
	}//for_loop the generation
	return 0;
}//main
