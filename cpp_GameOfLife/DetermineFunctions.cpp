/*
 * DetermineFunctions.cpp
 *
 *  Created on: 2021��3��19��
 *      Author: error
 */
//#include "Cell.h"
//#include "Graph.h"
//#include "DetermineFunctions.h"

bool determineOutOfRange(int curRol,int curCol,int ROL,int COL){
	/*
	 * determine out of index
	 */
	if((curRol-1) < 0){
		return true;
	}else if((curCol-1) < 0){
		return true;
	}else if((curRol+1) > ROL){
		return true;
	}else if((curCol+1) > COL){
		return true;
	}
	return false;
}//determine out of range

bool determineNearCell(int cell,int rol,int col){

	return false;
}//determine near cell
