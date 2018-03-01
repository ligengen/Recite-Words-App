/****************************
 名称：Graph.h
 作者：计62 李根 2016011250
 日期：2017-5-7
 功能描述：生成与单词在拼写上具有亲缘关系的单词图
 版权：这是我自己写的程序，没有使用其它来源的代码
 ***************************/

#ifndef Graph_H
#define Graph_H

#include<iostream>
#include"Funcbase.h"
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
#include"WordNode.h"
#include"Database.h"

using namespace std;

//Graph类是一个生成单词亲缘图的功能类
class Graph
{
public:
    char* getSubstr( char const* pStrSrc, int iStart, int iLen );
    int maxCommon( char* pStrLeft, char* pStrRight );
    void realize();
    void Cin();
    static char* firstStr;
    
private:
};


#endif
