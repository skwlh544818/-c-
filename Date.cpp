#include"Date.h"
#include<cstring>
#include<iostream>
bool Date::operator>(const Date& obj)
{
    if(this->m_nYear>obj.m_nYear)return true;
    if(this->m_nYear=obj.m_nYear)
    {
        if(this->m_nMon>obj.m_nMon)return true;
        if(this->m_nMon=obj.m_nMon)
        {
            if(this->m_nDay>obj.m_nDay)return true;
            if(this->m_nDay=obj.m_nDay||this->m_nDay<obj.m_nDay)return false;
        }
        if(this->m_nMon<obj.m_nMon)return false;
    }
    if(this->m_nYear<obj.m_nYear)return false;
}
bool Date::operator<(const Date& obj)
{
    if(this->m_nYear<obj.m_nYear)return true;
    if(this->m_nYear=obj.m_nYear)
    {
        if(this->m_nMon<obj.m_nMon)return true;
        if(this->m_nMon=obj.m_nMon)
        {
            if(this->m_nDay<obj.m_nDay)return true;
            if(this->m_nDay=obj.m_nDay||this->m_nDay>obj.m_nDay)return false;
        }
        if(this->m_nMon>obj.m_nMon)return false;
    }
    if(this->m_nYear>obj.m_nYear)return false;
}
void Date::operator=(const Date& obj)
{
    this->m_nDay=obj.m_nDay;
    this->m_nMon=obj.m_nMon;
    this->m_nYear=obj.m_nYear;
}
bool Date::operator==(const Date& obj)
{
    if(this->m_nDay==obj.m_nDay&&this->m_nMon==obj.m_nMon&&this->m_nYear==obj.m_nYear)
    {
        return true;
    }else{return false;}
}
