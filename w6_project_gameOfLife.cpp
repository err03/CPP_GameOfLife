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

//#include "Graph.h"
#include "DetermineFunctions.h"
//#include "Cell.h"
using namespace std;

void generateCell();
void drawGraph();

const int ROL = 8,COL = 8;
char lives[ROL][COL];
char cell = '*';	//change cell's appearance

int main() {
	generateCell();
	drawGraph();
	return 0;
}//main
//------------------------------ Graph Functions -------------------------------------------------------
void drawGraph(){
	for(int i=0;i<ROL;i++){		//print out the graph
		for(int c=0;c<COL;c++){
			if(c == (COL-1)){
				cout << " " << lives[i][c] << " "<<endl;
				continue;
			}//if
			cout << " "<<lives[i][c]<<" |";
		}//for
		if(i != (ROL-1)){
			cout <<setw(4*COL)<<setfill('-')<< "" <<endl;	//set the separate line by COL length
		}//if
	}//for
}//draw graph

//------------------------------ Cell Functions -------------------------------------------------------
void generateCell(){
	for(int i=0;i<ROL;i++){
		for(int c=0;c<COL;c++){
			lives[i][c] = ' ';
		}//for
	}//for

	int numOfCell = 25;		//how many cell you want?
	srand(time(NULL));
	for(int i=0;i<numOfCell;i++){
		int rol = rand() % ROL;
		int col = rand() % COL;
		if(lives[rol][col] != cell){
			lives[rol][col] = cell;
		}else{
			numOfCell++;	//if index already hand cell, than add one more cell.
			continue;
		}
//		cout << "[" << col << "]" << "[" << rol << "]"<< endl;
	}//for
}//generation cell







