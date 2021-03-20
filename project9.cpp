//============================================================================
// Name        : project9.cpp
// Author      : w
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>

//#include "Graph.h"

//#include "Cell.h"
using namespace std;


const int ROL = 8,COL = 8;
char lives[ROL][COL];
char cell = '*';	//change cell's appearance

int main() {


	                     int death=0;
	                     int newcell[ROL][COL]=0;
	                       for(int i=0;i<ROL;i++){
	                           for(int j=0;j<COL;j++){
	                               if(i-1>=0) if(lives[i-1][j]=='*') death++;
	                               if(j-1>=0) if(lives[i][j-1]=='*')death++;
	                               if(i+1<=COL) if(lives[i+1][j]=='*') death++;
	                               if(j+1<=COL) if(lives[i][j+1]=='*') death++;
	                               if((i-1>=0)&&(j-1>=0)) if(lives[i-1][j-1]=='*') death++;
	                               if((i-1>=0)&&(j+1<=COL)) if(lives[i-1][j+1]=='*') death++;
	                               if((i+1<=COL)&&(j-1>=0)) if(lives[i+1][j-1]=='*') death++;
	                               if((i+1<=COL)&&(j+1<=COL)) if(lives[i+1][j+1]=='*')death++;
	                               if(lives[i][j]=="*"){
	                                   if(death<2) newcell[i][j] = ' ';
	                                   else if(death>3) newcell[i][j] =' ';
	                                   else if((death==2)||(death==3)) newcell[i][j] = '*';
	                               }
	                               else if(death==3) newcell[i][j] = '*';
	                               death = 0;
	                           }
	                       }
	                       for(long i=0;i<ROL;i++){
	                                   for(long j=0;j<COL;j++){
	                                     lives[i][j] = newcell[i][j];

}}
}








