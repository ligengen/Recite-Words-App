/************************************
 名称：Database.h
 作者：计62 李根 2016011250（负责除了近反义词之外的功能）+金镇书 2016080036（负责近反义词功能）
 日期：2017-5-1
 内容描述：将单词的中文内容、近义词、反义词等信息加入到WordNode当中储存
 版权：代码来源于网络m.blog.csdn.net/lwfcgz/article/details/8449237
 ************************************/
#ifndef WORDNODE_H
#define WORDNODE_H

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class WordNode{
public:
    //默认空构造函数
    WordNode();
    //给出英文单词和中文解释的构造函数
    WordNode(string english, string chinese,string synonyms,string antonyms);
    //获取英文内容
    string getEnglish();
    //获取中文内容
    string getChinese();
    //获取近义词
    string getSynonyms();
    //获取反义词
    string getAntonyms();
    //重新设置英文内容
    void setEnglish(string english);
    //重新设置中文内容
    void setChinese(string chinese);
    //重新设置近义词
    void setSynonyms(string synonyms);
    //重新设置反义词
    void setAntonyms(string antonyms);
private:
    //英文单词
    string english;
    //对应的中文语义
    string chinese;
    //近义词
    string synonyms;
    //反义词
    string antonyms;
    
    
};

#endif
