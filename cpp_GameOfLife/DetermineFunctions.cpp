/*
 * DetermineFunctions.cpp
 *
 *  Created on: 2021Äê3ÔÂ19ÈÕ
 *      Author: error
 */
#include "Cell.h"
#include "Graph.h"
#include "DetermineFunctions.h"

extern char cell;		//extern the cell from cell.cpp
extern char lives[ROW][COL]; //extern the lives from cell.cpp, ROW and COL is in graph.h
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
