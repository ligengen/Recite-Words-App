/**********************************
 名称：Myless.cpp
 作者：计62 李根 2016011250
 日期：2017-5-20
 功能描述：重载运算符按照字典序排列
 版权：代码来源于网络m.blog.csdn.net/lwfcgz/article/details/8449237
 **********************************/

#include<iostream>
#include<string>
#include "WordNode.h"

using namespace std;

//用来辅助排序
class myless
{
public:
    //重载运算符，为排序做准备
    bool operator()(WordNode a, WordNode b) {
        //按照字典序排列
        return a.getEnglish() < b.getEnglish();
    }
};
