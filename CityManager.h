#ifndef CITYMANAGER_H_INCLUDED
#define CITYMANAGER_H_INCLUDED
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
class CityManager
{
protected:
    vector<City> m_vecCity;
public:
    CityManager(){};
    virtual ~CityManager(){};
    void SetVecCity(vector<City> &obj){m_vecCity=obj;}
    vector<City> GetVecCity(){return m_vecCity;}
};


#endif // CITYMANAGER_H_INCLUDED
