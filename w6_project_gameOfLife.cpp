//============================================================================
// Name        : w6_project_gameOfLife.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void determineValidPosition(int,int);

const int ROL = 8,COL = 8;
int main() {

	int lives[ROL][COL];
	for(int i=0;i<ROL;i++){
		for(int c=0;c<COL;c++){
			cout << "["<<i<<"]["<<c<<"]  ";
		}
		cout << endl;
	}


	return 0;
}

void determineValidPosition(int rol,int cow){
	if((rol-1) < 0){
		return;
	}else if((cow-1) < 0){
		return;
	}else if((rol+1) > 8){
		return;
	}else if((cow+1) > 8){
		return;
	}


}
