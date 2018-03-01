/*******************************
 名称：Funcbase.h
 作者：计62 李根 2016011250
 日期：2017-5-14
 功能描述：查词典的具体实现，调用ReferDic新建一个ReferDic的对象实现查单词的界面初始化等具体功能，是功能虚基类Funcbase的具体实现之一
 版权：这是我自行完成的程序，没有用其他代码。
 *******************************/


#ifndef VIEWFUNC_H
#define VIEWFUNC_H

#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include "Database.h"
#include "WordNode.h"
#include"Funcbase.h"
#include"Referdic.h"

using namespace std;

class Viewfunc:public Funcbase{
public:
    Viewfunc();
    //初始化整个界面
    void initialize();
    //浏览词典
    void browseDic();
private:
    Referdic referdic;
    static int order;

};

#endif
