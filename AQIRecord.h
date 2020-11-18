#ifndef AQIRECORD_H_INCLUDED
#define AQIRECORD_H_INCLUDED
#include<cstring>
#include<iostream>
#include"Date.h"
using namespace std;
class AQIRecord
{
protected:
    int nIndex;
    float fAQI;
    string szWRW;
    int nLevel;
    Date strDate;
public:
    AQIRecord(){};
    virtual ~AQIRecord(){};
    Date GetDate(){return strDate;}
};

#endif // AQIRECORD_H_INCLUDED
