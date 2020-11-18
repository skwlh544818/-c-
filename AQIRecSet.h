#ifndef AQIRECSET_H_INCLUDED
#define AQIRECSET_H_INCLUDED
#include<iostream>
#include<cstring>
#include<vector>
#include"Date.h"
#include"AQIRecord.h"
using namespace std;
class AQIRecSet
{
protected:
    Date m_strBegDate;
    Date m_strEndDate;
    vector<AQIRecord> m_vecData;
    //AQIRecord* m_pData;

public:
    AQIRecSet(){};
    virtual ~AQIRecSet(){};
    void initRecordSet();
    void setBEDate(Date &beg,Date& end1);
    void setData(vector<AQIRecord>& obj);
    vector<AQIRecord> getMonthData(int n);
    Date GetBegDate(){return m_strBegDate;}
    Date GetEndDate(){return m_strEndDate;}
};


#endif // AQIRECSET_H_INCLUDED
