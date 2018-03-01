#include<iostream>
#include<iomanip>
#include<fstream>
#include "jiyi.h"
using namespace std;
static int S_outnum = 0;



void jiyi:: print(int num,int div)              //connect with the user to provide the information
{
    int count =1;
    for(int i=1;i<=num+30;i++)
    {
        count++;
        cout<<"第"<<count-1<<"天 ";
        
        jiyi::newPrint(i,num,div);             //print the information that the user should learn each day
        jiyi::rowPrint(i,num,div);			   //print the information that the user should review	each day
        
        cout<<endl;
        
        if(count>=num/div+30+1)					//limit the size of the words
        {
            S_outnum = 0 ;
            break;
        }
    }
}



bool jiyi:: isDividedEvenly(int static_num,int div)	                          //num means the total units;the div is setted by the user
{
    if(static_num % div == 0)												//promote the what the user	print is true
        return true;
    
    else
        return false;
}



void jiyi:: newPrint(int num,int static_num,int div)                       //the fuction is preparing the information that should be learned
{
    int sum = num+1;
    S_outnum++;
    
    if( S_outnum<(static_num)/div+1)                                       
        cout<<(S_outnum-1)*div+1<<"->"<<(S_outnum)*div<<" ";
    
    if(!isDividedEvenly(static_num,div) && S_outnum==(static_num)/div+1)
        cout<<(S_outnum-1)*div+1<<"->"<<static_num<<" ";
    
}

void jiyi:: rowPrint(int num,int static_num,int div)					//the function is modelled by the forgetting curve put by Ebbinghaus,divided by some period
{
    int sum = num+1;
    int outnum=0;
    
    while(num>0 )
    {
        outnum++;
        if(sum==1+outnum||sum==2+outnum||sum==4+outnum||sum==8+outnum||sum==15+outnum||sum==30+outnum)
        {
            if( outnum<(static_num)/div+1)
                cout<<"*"<<(outnum-1)*div+1<<"->"<<(outnum)*div<<" ";
            
            if(!isDividedEvenly(static_num,div) && outnum==(static_num)/div+1)
                cout<<"*"<<(outnum-1)*div+1<<"->"<<static_num<<" ";
        }
        if(outnum>=static_num/div+1)
            break;
    }
}

void jiyi::initialize(int div,int num)										//the operation remind
{
    bool isTrue = true;
    
    cout<<"你输入你要背诵的单元数目"<<endl;
    cout<<"***********************************************************"<<endl;
    cout<<"*没有带<*>号的表示当天的任务，带星号的表示当天复习的内容***"<<endl;
    cout<<"***********************************************************"<<endl;
leaphead: cout<<"Please input the number of all units<请输入要复习的单元总数> "<<endl;
    
    cin>>num;
    while(isTrue == true)
    {
        if(num<1 )
        {
            cout<<"请重新输入单元数"<<endl;
            cin>>num;
        }
        
        else
            isTrue = false;
    }
    
    cout<<"Please input units for once time<请输入一次复习的单元个数>"<<endl;
    cin>>div;
    cout<<endl;
    
    
    jiyi::print(num,div);
    
    ifstream myfile("Word List");									//a dictionary is prepared for the user if needed
    ofstream outfile("Word List");
    
    
}

