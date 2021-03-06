//Name : Main.cpp
//Author: Handongchi 2016050023 (主函数之前的部分)
//Date: 2017-06-10
//Description: The purpose of this cpp is to import documents generated by other word memorizing programs.
//Copyright: www.sourceforge.net/projects/tinyxml Original code by Lee Thomason (www.grinninglizard.com)
#include<iostream>
#include<string>
#include<vector>
#include "DataBase.h"
#include "WordNode.h"
#include "NewFrame.h"
#include "Funcbase.h"
#include "Graph.h"
#include "Viewfunc.h"
#include "tinyxml.h"
#include "tinystr.h"
#include<iomanip>
#include<fstream>
#include<cstdlib>
#include "jiyi.h"
#include "ManageWords.h"
#include "Client.h"
using namespace std;

//word -- Storing data imported from the XML file
struct word {
    string dc;            //word
    string meaning;
};

//book -- Storing data imported from the TXT file
struct book {
    char num[6];          //serial number
    char word[20];
    char Phonogram[20];
    char pos[7];          //Word attribute
    char meaning[50];
};

//Summary:importing XMl file generated by other word memorizing programs.
//Parameters:
//    A : Structure array.
//    loadOkay :Used to judge if the XMl file is open.
//    itemElem :A pointer.
//    wordElem :A pointer.
//    transElem:A pointer.
//    count : A int.
//    pElem :A pointer.
//Return :
//    Void.
//Algorithm:
//    iterator.
void XML() {
    word A[500];
    ofstream fout("rword.txt",ios::app);
    if (!fout) {
        cout << "Fail to open the file" << endl;
    }
    system("chcp 65001");
    const char*filepath = "word.xml";
    TiXmlDocument doc(filepath);                                 //open xml file
    bool loadOkay = doc.LoadFile();
    if (!loadOkay) {
        cout << "Fail to open the file" << endl;
    }
    TiXmlHandle hDoc(&doc);                                      //hDoc is the object that &doc pointing to
    TiXmlElement* pElem;                                         //Define a pointer
    pElem = hDoc.FirstChildElement().Element();                  //Point to root node
    TiXmlHandle hRoot(pElem);
    TiXmlElement* itemElem = hRoot.FirstChild("item").Element(); //get the element of
    int count = 0;                                               /*To record moves to which node and records
                                                                   the node's information into the corresponding
                                                                   structure member sequence*/
    for (itemElem; itemElem; itemElem = itemElem->NextSiblingElement()) {  //iterator
        TiXmlHandle item(itemElem);
        TiXmlElement* wordElem = item.FirstChild("word").Element();
        TiXmlElement* transElem = item.FirstChild("trans").Element();
        A[count].dc = wordElem->GetText();                        //get word
        A[count].meaning = transElem->GetText();                  //get meaning
        count++;
    }
    for (int i=0; i < 500; i++) {
        fout << A[i].dc <<endl<< A[i].meaning << endl<<endl;
    }
    cout<<"导入文件成功！"<<endl;
}

//Summary:importing TXT file generated by other word memorizing programs.
//Parameters:
//    A : Structure member.
//Return :
//    Void.
void TXT() {
    ifstream fin("word.txt");
    if (!fin) {
        cout << "Fail to open the file\n";

    }
    ofstream fout("rword.txt", ios::app);
    if (!fout) {
        cout << "文件打开失败\n";

    }

    system("chcp 65001");
    book A;
    while (fin >> A.num >> A.word >> A.Phonogram >> A.pos >> A.meaning)
    {
        fout << A.num << "  "
        << A.word << "  "
        << A.pos << "  "
        << A.meaning << endl;
    }

    fin.close();
    fout.close();
    cout<<"导入文件成功！"<<endl;
}

//Summary: Require users to provide attributes that need to import files
//Parameters:
//    g: A int.
//Return :
//    Void.
void import()
{
    int g = 0;
    cout << "请问您想导入什么类型的文件（XML类型文件请输入1；TXT文件请输入2;）"<<endl;
    cin >> g;
    if(g==0){
    }
    else if (g==1) {
        XML();
    }
    else if (g==2) {
        TXT();
    }
}

//主函数
int main(){
    while(1)
    {
        int choice, div, num;
        Client * client = new Client();
        for(int i=0;i<5;i++)
        {
            cout<<endl;
        }
        cout<<"********************************轻松背单词************************************"<<endl;
        for(int i = 0; i < 5; i++)
            cout << endl;
        cout<<"                              1.管理单词本                                  "<<endl;
        cout<<"                              2.轻松背单词                                  "<<endl;
        cout<<"                              3.查词典                                     "<<endl;
        cout<<"                              4.生成单词亲缘图                               "<<endl;
        cout<<"                              5.导入其他词典生成的词库         "<<endl;
        cout<<"                              6.艾宾浩斯遗忘曲线助记                 "<<endl;
        cout<<"                              7.退出系统                                    "<<endl;
        for(int i=0;i<3;i++)
            cout<<endl;
        cout<<"请输入你的选择 (1~7) ：";
        cin >> choice;
        if(choice < 1 || choice > 7)
        {
            cout<<"请重新输入..."<<endl;
            cin>>choice;
        }
        
        if(choice == 1)
        {
            Funcbase * managewords = new ManageWords();
            client->setStrategy(managewords);
            client->Menu();
        }else if(choice == 2){
            Funcbase * newframe = new NewFrame();
            client->setStrategy(newframe);
            client->Menu();
        }else if(choice == 3){
            Funcbase * viewfunc = new Viewfunc();
            client->setStrategy(viewfunc);
            client->Menu();
        }else if(choice == 4){
            Graph graph;
            graph.Cin();
            graph.realize();
        }else if(choice == 5){
            import();
        }else if(choice == 6){
            jiyi Jiyi;
            Jiyi.initialize(div, num);
        }else{
            exit(0);
        }
    }
    

    return 0;
}
