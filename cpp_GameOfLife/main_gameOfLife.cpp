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
//#include "DetermineFunctions.h"
//#include "Cell.h"
using namespace std;

void generateCell();
void drawGraph();

bool determineDeath(int,int);
bool determineBirth(int,int);
void determineNearCell(int&,int,int);
bool determineNoMoreCell();

void determineTop(int&,int,int);
void determineLeft(int&,int,int);
void determineRight(int&,int,int);
void determineDown(int&,int,int);
void determineTop_Left(int&,int,int);
void detemineTop_Right(int&,int,int);
void determineDown_Left(int&,int,int);
void determineDown_Right(int&,int,int);

const int ROW = 8,COL = 8;
char lives[ROW][COL];
char cell = '*';	//change cell's appearance
int numOfCell = 10;//how many cell you want?
int generationTime = 20;	//how many generation time you want?
int main() {
	int generation = 0;
	generateCell();
	cout << "Generation:" << generation<< endl;
	drawGraph();
//	int i=1,c=2;
	for(int g=0;g<generationTime;g++){

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
//------------------------------ Graph Functions -------------------------------------------------------
void drawGraph(){
	for(int i=0;i<ROW;i++){		//print out the graph
		for(int c=0;c<COL;c++){
			if(c == (COL-1)){
				cout << " " << lives[i][c] << " "<<endl;
				continue;
			}//if
			cout << " "<<lives[i][c]<<" |";
		}//for
		if(i != (ROW-1)){
			cout <<setw(4*COL)<<setfill('-')<< "" <<endl;	//set the separate line by COL length
		}//if
	}//for
}//draw graph

//------------------------------ Cell Functions -------------------------------------------------------
void generateCell(){
	for(int i=0;i<ROW;i++){
		for(int c=0;c<COL;c++){
			lives[i][c] = ' ';
		}//for
	}//for

	srand(time(NULL));
	for(int i=0;i<numOfCell;i++){
		int rol = rand() % ROW;
		int col = rand() % COL;
		if(lives[rol][col] != cell){
			lives[rol][col] = cell;
		}else{
			numOfCell++;	//if index already hand cell, than add one more cell.
			continue;
		}
//		cout << "[" << col << "]" << "[" << ROW << "]"<< endl;
	}//for
}//generation cell

//------------------------------ determine function -------------------------------------------------------
bool determineDeath(int rol,int col){
	int death = 0;
	determineNearCell(death,rol,col);

	if(death > 3 || death < 2){		//rule: if near cells is more than 3, or less than 2
		return true;
	}
	return false;
}//determine death

bool determineBirth(int rol,int col){
	int birth = 0;
	determineNearCell(birth,rol,col);

	if(birth == 3){		//rule: if near cells is exactly 3
		return true;
	}
	return false;
}//determine birth

/*
 * determine the position about 8 positions
 */
void determineNearCell(int& count,int rol,int col){
	determineTop(count,rol,col);
	determineLeft(count,rol,col);
	determineRight(count,rol,col);
	determineDown(count,rol,col);
	determineTop_Left(count,rol,col);
	detemineTop_Right(count,rol,col);
	determineDown_Left(count,rol,col);
	determineDown_Right(count,rol,col);
}//determine near cell

bool determineNoMoreCell(){
	int cellCount = 0;
	for(int i=0;i<ROW;i++){
		for(int c=0;c<COL;c++){
			if(lives[i][c] == cell){
				cellCount++;
			}//if
		}//for
	}//for
	if(cellCount == 0){
		return true;
	}//if
	return false;
}//determine no more cell
//--------------------------Determine cell's index position
void determineTop(int& count,int rol,int col){
	int top = rol - 1;
	if(top < 0){
		return;
	}
	if(lives[top][col] == cell){
//		cout << "top +" << endl;
		count++;
	}//if
} //determineTop
void determineLeft(int& count,int rol,int col){
	int left = col - 1;
	if(left < 0){
		return;
	}
	if(lives[rol][left] == cell){
//		cout << "left +" << endl;
		count++;
	}//if
} //determineLeft
void determineRight(int& count,int rol,int col){
	int right = col + 1;
	if(right > COL){
		return;
	}
	if(lives[rol][right] == cell){
//		cout << "right +" << endl;
		count++;
	}//if
} //determineRight
void determineDown(int& count,int rol,int col){
	int down = rol + 1;
	if(down > ROW){
		return;
	}
	if(lives[down][col] == cell){
//		cout << "down +" << endl;
		count++;
	}//if
} //detemineDown

//--------------------------
void determineTop_Left(int& count,int rol,int col){
	int top = rol - 1;
	int left = col - 1;
	if(left < 0){
		return;
	}
	if(lives[top][left] == cell){
//		cout << "top left +" << endl;
		count++;
	}//if
} //detemineTop_Left
void detemineTop_Right(int& count,int rol,int col){
	int top = rol - 1;
	int right = col + 1;
	if(top < 0){
		return;
	}
	if(lives[top][right] == cell){
//		cout << "top right +" << endl;
		count++;
	}//if
} //detemineTop_Right
void determineDown_Left(int& count,int rol,int col){
	int down = rol + 1;
	int left = col - 1;
	if(left < 0){
		return;
	}
	if(lives[down][left] == cell){
//		cout << "down left +" << endl;
		count++;
	}//if
} //determineDown_Left
void determineDown_Right(int& count,int rol,int col){
	int down = rol + 1;
	int right = col + 1;
	if(down > ROW){
		return;
	}
	if(lives[down][right] == cell){
//		cout << "down right +" << endl;
		count++;
	}//if
} //determineDown_Right
