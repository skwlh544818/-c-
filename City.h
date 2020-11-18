#ifndef CITY_H_INCLUDED
#define CITY_H_INCLUDED
#include<iostream>
#include<cstring>
#include<vector>
#include"AQIRecSet.h"
class City
{
protected:
   string szName;
   string szCode;
   string szfile1;
   AQIRecSet m_strDataSet;
public:
    vector<AQIRecord> getMonthData(int nmon){return m_strDataSet.getMonthData(nmon);}
    City(string &n,string &c,string &f)
    {
        szName=n;
        szCode=c;
        szfile1=f;
    }
    string GetName(){return szName;}
    string GetCode(){return szCode;}
    string GetFile(){return szfile1;}
    AQIRecSet GetDataSet(){return m_strDataSet;}
};


#endif // CITY_H_INCLUDED
