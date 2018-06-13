#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

struct st
{
    string name;
    string sex;
    string score;
}s[32];

int p2(const st &x)
{
    int n;
    char num[10] ;
    strcpy(num,x.name.c_str());
    for(int j=0;j<10;j++)
{
    if((num[j]>='0')&&(num[j]<='9'))
      n=num[j];
}
    return n;
}
bool p1(const st &x, const st &y)
{
    double a=stof(x.score);
    double b=stof(y.score);
    int c=p2(x);
    int d=p2(y);
    if(a==b)
    return d>c;
    else
    return a>b;
}//排序

int main()
{
    ifstream fin("score.csv");
    string line;
    getline(fin,line);//先读首行不进行操作
    int i=0;
    double t;
    double m=0,g=0,m1=0,g1=0;
    while(getline(fin,line))
{
    istringstream sin(line);
    vector<string> fields;
    string field;
    while (getline(sin,field,','))
    {
        fields.push_back(field);
    }   
    s[i].name = fields[0];
    s[i].sex = fields[1];
    s[i].score = fields[2];
    if(s[i].sex==" Male")
    {
     m++;
     t=stof(s[i].score);
     m1+=t;
    }
    else
    {
    g++;
    t=stof(s[i].score);
    g1+=t;
    }
    i++;
}
    double m2=m1/m,g2=g1/g;
    cout<<"男生平均分为:"<<m2<<endl;;
    cout<<"女生平均分为:"<<g2<<endl;
    for(int k=0;k<32;k++)
{
    sort(s,s+32,p1);
}
    for(int k=0;k<32;k++)
{
    cout<<s[k].name<<","<<s[k].sex<<","<<s[k].score<<endl;
}
    return 0;
}

