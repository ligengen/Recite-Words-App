/*******************************
 名称：ReferDic.h
 作者：计62 李根 2016011250
 日期：2017-5-17
 功能描述：查词典功能，输入要查询的单词，从词典当中查询到单词的词性、音标、例句等具体细节信息并输出。
 版权：这是我自行完成的程序，没有用其他代码。
 *******************************/


#ifndef REFERDIC_H
#define REFERDIC_H

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
#include"Database.h"
#include"WordNode.h"

class Funcbase;

class Referdic:public DataBase
{
public:
    /*
    string english;
    string details;
    string sentence;
    */
    Referdic();
    Referdic(string);
private:
    
};

#endif
