#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include<cstring>
#include<iostream>
class Date
{
protected:
    int m_nYear;
    int m_nMon;
    int m_nDay;
public:
    Date(){};
    Date(int& y,int& m,int& d){m_nYear=y;m_nMon=m;m_nDay=d;};
    virtual ~Date(){};
    bool operator>(const Date& obj);
    bool operator<(const Date& obj);
    void operator=(const Date& obj);
    bool operator==(const Date& obj);
    int GetMon(){return m_nMon;}
    int GetDay(){return m_nDay;}
    int GetYear(){return m_nYear;}
};


#endif // DATE_H_INCLUDED
