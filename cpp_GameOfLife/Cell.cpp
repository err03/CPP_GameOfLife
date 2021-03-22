/*
 * Cell.cpp
 *
 *  Created on: 2021Äê3ÔÂ19ÈÕ
 *      Author: error
 */

#include "Graph.h"
#include "Cell.h"

//#include "DetermineFunctions.h"

#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>

using namespace std;

int numOfCell = 25;//how many cell you want?
char cell = '*';	//change cell's appearance
char lives[ROW][COL];	//lives' array
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
