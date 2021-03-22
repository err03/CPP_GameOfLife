/*
 * Graph.cpp
 *
 *  Created on: 2021Äê3ÔÂ19ÈÕ
 *      Author: error
 */
//#include "Cell.h"
#include "Graph.h"
//#include "DetermineFunctions.h"

#include <iostream>
#include <iomanip>

using namespace std;

extern char lives[ROW][COL];//extern the lives from cell.cpp, ROW and COL is in graph.h

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

