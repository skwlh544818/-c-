#include"AQIRecSet.h"
#include"AQIRecord.h"
#include"Date.h"
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
void AQIRecSet::setData(vector<AQIRecord>& obj)
{
    m_vecData=obj;
}
void AQIRecSet::setBEDate(Date& beg,Date& end1)
{

    if(beg>end1)
    {
        Date D=beg;
        beg=end1;
        end1=D;
    }
    m_strBegDate=beg;
    m_strEndDate=end1;
}
void AQIRecSet::initRecordSet()
{
    vector<AQIRecord> temp;
    for(int i=0;i<m_vecData.size();++i)
    {
        if(m_vecData[i].GetDate()>m_strBegDate||m_vecData[i].GetDate()==m_strBegDate&&m_vecData[i].GetDate()<m_strEndDate)
        {
            temp.push_back(m_vecData[i]);
        }
    }
    m_vecData=temp;
}
vector<AQIRecord> AQIRecSet::getMonthData(int n)
{
    vector<AQIRecord> temp;
    for(int i=0;i<m_vecData.size();++i)
    {
        if(m_vecData[i].GetDate().GetMon()==n)
        {
            temp.push_back(m_vecData[i]);
        }
    }
    return temp;
}
