/*
 designer:Zhang Handi
 class:62
 Student Number:2016011252
 designed on ourselves to provide
 The Ebbinghaus Forgetting Curve
 to help remember words
 */

#ifndef  JIYI_H
#define  JIYI_H

#include<iostream>
using namespace std;


class jiyi																//provide a class to satisfy the whole project
{
	public:
		void print(int num,int div);									 		
		void rowPrint(int num,int static_num,int div );                  //the information shoule be reviewed
		void newPrint(int ,int ,int);                                    //the information should be learned
		bool isDividedEvenly(int ,int);
		void initialize(int ,int );
    private:
		int num;														//the number of total units
		int div;                                    					//the unit the user want to learn every day
};


#endif
