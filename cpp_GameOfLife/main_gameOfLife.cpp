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

void determineTop(int&,int,int);
void determineLeft(int&,int,int);
void determineRight(int&,int,int);
void determineDown(int&,int,int);
void determineTop_Left(int&,int,int);
void detemineTop_Right(int&,int,int);
void determineDown_Left(int&,int,int);
void determineDown_Right(int&,int,int);

const int ROL = 8,COL = 8;
char lives[ROL][COL];
char cell = '*';	//change cell's appearance

int main() {
	generateCell();
	drawGraph();
	int i = 1;
	int c = 1;
	for(int i=0;i<ROL;i++){
		for(int c=0;c<COL;c++){
			if(lives[i][c] == cell){
//				cout << "yes cell"<< endl;
				if(determineDeath(i,c)){
					lives[i][c] = ' ';
//					cout << "cell death"<< endl;
				}else{
					lives[i][c] = cell;
//					cout << "cell birth"<< endl;
				}
			}else{
//				cout << "no cell"<< endl;
				if(determineBirth(i,c)){
					lives[i][c] = cell;
//					cout << "yes birth"<< endl;
				}else{
//					cout << "no birth"<< endl;
				}
			}//if else
		}//for
	}//for
	cout << "-----------------------------------------" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "-----------------------------------------" << endl;

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

//------------------------------ determine function -------------------------------------------------------
bool determineDeath(int rol,int col){
	int death = 0;
	determineNearCell(death,rol,col);

	if(death > 3 || death < 2){
		return true;
	}
	return false;
}//determine death

bool determineBirth(int rol,int col){
	int birth = 0;
	determineNearCell(birth,rol,col);

	if(birth == 3){
		return true;
	}
	return false;
}//determine birth

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
	if(down > ROL){
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
	if(down > ROL){
		return;
	}
	if(lives[down][right] == cell){
//		cout << "down right +" << endl;
		count++;
	}//if
} //determineDown_Right
