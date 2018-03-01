#include<iostream>
#include"Funcbase.h"
#include<string>
#include<vector>
#include<algorithm>
#include"WordNode.h"
#include"Database.h"
#include<cstring>
#include<fstream>
#include"Graph.h"

using namespace std;

char* Graph:: firstStr = new char[1000];


/*功能：从begin位开始，从stringsrc中截取长度为length的字符串
 *参数：
 *     stringsrc：一个常量字符串
 *     begin:一个整数
 *     length：一个整数
 *返回值：一个字符串，为子串
 *算法：直接截取
*/
char* Graph:: getSubstr( char const* stringsrc, int begin, int length )
{
    if( !stringsrc || begin <  0 )
        return NULL;
    int iStrLen = strlen( stringsrc );
    char* str3 = NULL;
    if( length >= iStrLen - begin )
    {
        str3 = (char*)malloc( iStrLen - begin + 1 );
        if( !str3 )
            return NULL;
        memset( str3, 0,  iStrLen - begin + 1 );
        strncpy( str3, stringsrc + begin, iStrLen  - begin );
        return str3;
    }
    else
    {
        str3 = (char*)malloc( length + 1 );
        if( !str3 )
            return NULL;
        memset( str3, 0, length + 1 );
        strncpy( str3, stringsrc + begin, length );
        return str3;
    }
}


/*功能：得到字符串firstStr与secondStr的最长的公共子串的长度
 *参数：两个字符串
 *返回值：一个整数，也即最长公共子串的长度
 *算法：逐位暴力搜索
 */
int Graph:: maxCommon( char* firstStr, char* secondStr )
{
    if( !firstStr || !secondStr )
    {
        return 0;
    }
    char* str1 = NULL;
    char* str2 = NULL;
    char* str3= NULL;
    int l = strlen( firstStr );
    int r = strlen( secondStr );
    int less = ( l <= r ) ? l : r;
    int i,j;
    if( l <= r )
    {
        str1 = firstStr;
        str2 = secondStr;
    }
    else
    {
        str1 = secondStr;
        str2 = firstStr;
    }
    for( i = less; i > 0; i-- )
    {
        for( j = 0; j <= less - i; j++ )
        {
            str3 = getSubstr( str1, j, i );
            if( strstr( str2, str3 ) )
                return strlen(str3);
            free( str3 );
            str3 = NULL;
        }
    }
    return 0;
}
//功能实现的主体部分
void Graph:: realize()
{
    ifstream fin("dictionary.txt");
    string b;
    string English = "NULL";
    bool xx = 0;
    //把文件一行一行读入
    while(getline(fin,b,'\r'))
    {
        int ans=0;
        //判断读入的这一行是否符合要求处理的对象的特征
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
            //从读入的字符串中得到英文单词
            English = b.substr(i,j-i);
            char* mmm = (char*)English.c_str();
            ans = maxCommon( firstStr, mmm );
            
            //我认为，公共子串的长度大于等于3就认为他们在拼写上具有亲缘关系
            if(ans>=3)
            {
                xx=1;        //如果有亲缘关系，就将flag xx设为1
                cout << English << "--->";
            }
        }
    }
    if(xx)
    {
        cout << " 是单词 " << firstStr << " 的亲缘图" <<endl;
    }
    else
    {
        cout<<" 未找到与单词 "<< firstStr << " 拼写上相近的单词"<<endl;
    }
    
    
    fin.close();
    
}

void Graph::Cin()
{
    cout<<"请输入要生成关系图的单词："<<endl;
    cin >> firstStr;
}
