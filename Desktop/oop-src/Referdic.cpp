#include<iostream>
#include<string>
#include<vector>
#include"Database.h"
#include"WordNode.h"
//#include"MyFrame.h"
#include"Referdic.h"
#include<fstream>
using namespace std;

Referdic::Referdic()
{
    
}
Referdic::Referdic(string s)
{
    ifstream file(s);
    
    char a;
    string b;
    
    string english = "NULL";
    string details = "NULL";
    string sentence = "NULL";
    
    //从词典当中一行一行读入单词，并比较输入的单词是否与词典中的一致，若一致，则输出该单词的具体信息
    while(getline(file,b,'\r'))
    {
        //比对是否读入信息合法
        if(b[0]>='0'&&b[0]<='9')
        {
            int i,j;
            for(i=0;i<b.size();i++)
            {
                if(b[i]>='a'&&b[i]<='z')
                    break;
            }
            for(j=i;j<b.size();j++)
            {
                if(!(b[j]>='a'&&b[j]<='z'))
                    break;
            }
            
            //读入单词为english
            english = b.substr(i,j-i);
            //读入单词的具体细节，包括单词的音标、词性、释义
            details = b.substr(j+1,b.size()-1-j);
            
        }
        //判断该行是否为例句所在的一行
        for(int o=0;o<10;o++)
        {
            if(b[o]=='*')//是例句所在的一行
            {
                sentence = b.substr(o+4,b.size()-o-4);
                //将例句添加到词典当中
                this->addWordNode(WordNode(english,details, sentence, "NULL"));
                english="NULL";
                details="NULL";
                sentence="NULL";
            }
        }
        
    }
    file.close();
}
