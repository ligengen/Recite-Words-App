#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include"Database.h"
#include"WordNode.h"
#include"Funcbase.h"

using namespace std;
//打印几行空行
void Funcbase:: printBlankLines(int n)
    {
        for(int i=0;i<n;i++)
            cout<<endl;
        return;
    }
//退出系统
void Funcbase:: exitSystem()
    {
        exit(0);
    }
