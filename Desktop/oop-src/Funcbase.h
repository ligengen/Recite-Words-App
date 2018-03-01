/*******************************
 名称：Funcbase.h
 作者：计62 李根 2016011250
 日期：2017-5-3
 功能描述：作为功能类的虚基类，含有纯虚函数：初始化、浏览词典。基类的函数有退出系统、打印几行空行。
 版权：这是我自行完成的程序，没有用其他代码。
 *******************************/

#ifndef FUNCBASE_H_
#define FUNCBASE_H_

#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include"Database.h"
#include"WordNode.h"

using namespace std;

class Funcbase 
{
public:
    //初始化界面，即出现不同功能要求的主菜单页面
    virtual void initialize()=0;
    //浏览词典功能，满足不同要求的查单词功能
    virtual void browseDic()=0;
    //退出系统
    void exitSystem();
    //打印几行空行
    void printBlankLines(int n);
    DataBase dataBase;
    DataBase dataBase2;
};

#endif //FUNCBASE_H_
