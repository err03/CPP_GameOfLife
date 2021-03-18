/*
 * DetermineFunctions.cpp
 *
 *  Created on: 2021Äê3ÔÂ19ÈÕ
 *      Author: error
 */
//#include "Cell.h"
//#include "Graph.h"
//#include "DetermineFunctions.h"

void determineOutOfRange(int curRol,int curCol,int ROL,int COL){
	/*
	 * determine out of index
	 */
	if((curRol-1) < 0){
		return;
	}else if((curCol-1) < 0){
		return;
	}else if((curRol+1) > ROL){
		return;
	}else if((curCol+1) > COL){
		return;
	}
}//determine out of range
