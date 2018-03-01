/**********************************
 名称：ManageWords.h
 作者：计62 李根 2016011250（负责管理单词本的功能）+金镇书 2016080036（负责近反义词的功能）
 日期：2017-5-20
 功能描述：管理单词本功能，作为Funcbase功能虚基类的具体实现之一
 版权：这是我自己完成的程序，没有使用其余来源的代码
 **********************************/


#ifndef MANAGEWORDS_H
#define MANAGEWORDS_H

#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include "Database.h"
#include "WordNode.h"
#include"Funcbase.h"

using namespace std;

//继承了虚基类的ManageWords用来管理单词本
class ManageWords:public Funcbase
{
public:
    ManageWords();
    void addWord();
    void deleteWord();
    void modifyWord();
    virtual void initialize();
    virtual void browseDic();
};



#endif
