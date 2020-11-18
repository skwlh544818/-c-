#include <iostream>
#include<vector>
#include<cstring>
#include<stdio.h>
#include<string>
#include<fstream>
#include<map>
#include"AQIFileIO.h"
#include"AQIRecord.h"
#include"AQIRecSet.h"
#include"City.h"
#include"CityManager.h"
#include"Date.h"
using namespace std;
map<string,int>grade={{"优",0},{"良",1},{"轻度污染",2},{"中度污染",3},{"重度污染",4},{"严重污染",5}};
string grada[6] = { "优","良","轻度污染","中度污染","重度污染","严重污染" };
ifstream in;
vector<City> Vc;

void menu()
{

}

void Read();

int main()
{
    string c,code,file2;
    in.open("city.txt");
    while(!in.eof())
    {
        in>>c>>code>>file2;
        City Ci(c,code,file2);
        Vc.push_back(Ci);
    }
    in.clear();
    in.close();
    Read();
    return 0;
}

void Read()
{
    string city1;
    bool flag=false;
    CityManager CM;
    CM.SetVecCity(Vc);
    int y,m,d,index;
    cout<<"请输入想要读入的城市：";
    cin>>city1;
    vector<City>C=CM.GetVecCity();
    for(int i=0;i<C.size();++i)
    {
        if(C[i].GetName()==city1)
        {
            flag=true;
            index=i;
        }
    }
    if(flag==false){cout<<"你输入的城市不存在，请重新输入！";menu();}else{
    cout<<endl;
    cout<<"请输入起始日期（格式为xxxx:xx:xx）：";
    cin>>y;getchar();cin>>m;getchar();cin>>d;
    Date b(y,m,d);
    cout<<"请输入结束日期（格式为xxxx:xx:xx）：";
    cin>>y;getchar();cin>>m;getchar();cin>>d;
    Date e(y,m,d);
    AQIRecSet AQS=C[index].GetDataSet();
    AQS.setBEDate(b,e);
    int id;
    float aqi;
    string pollute;
    string gra;
    string city;
    string da;
    ifstream fin;
    string filec=C[index].GetFile();
    cout<<filec;
    fin.open(filec);
    while(!fin.eof())
    {
        fin>>id>>city>>aqi>>pollute>>da>>gra;
        cout<<id<<city<<aqi<<pollute<<da<<gra;
        /*sscanf(da.c_str(),"%d-%d-%d",&y,&m,&d);
        cout<<y<<m<<d;
        Date temp(y,m,d);
        if(temp>AQS.GetBegDate()||temp==AQS.GetBegDate()&&temp<AQS.GetEndDate())
        {
            cout << "编号" << "  " << "城市" << "    " << "AQI指数" << "    " << "主要污染物" << "    " << "检测日期" << "    " << "等级" << "    " << endl;
            cout << endl;
            cout << id << "   " << city << "    " << aqi << "    " << pollute << "    " << da << "    " << gra << "    " << endl;
        }*/
    }
    }
}
