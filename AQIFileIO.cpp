#include "AQIFileIO.h"
#include<cstring>
#include<iostream>
#include<fstream>
using namespace std;
AQIFileIO::AQIFileIO()
{
    //ctor
}

AQIFileIO::~AQIFileIO()
{
    //dtor
}

//读取文件
bool AQIFileIO::readFile()
{
    if (m_szFileName.empty()){return false;}

    ifstream infile;
    //string -->char *
    infile.open(m_szFileName.c_str(),ios::in);
    char buf[512];
    infile.getline(buf,512);
    string s1,s2,s3,s4;
    int nIndex = 0;
    int nAQI = 0;
    while( !infile.eof() )
    {
        //infile>>nIndex>>s1>>nAQI>>s2>>s3>>s4;
    }

    infile.close();
    return true;
}

//写重新计算后的数据
bool AQIFileIO::writeFile(string szfile)
{
    if (szfile.empty()){return false;}
    ofstream outfile;
    outfile.open(szfile.c_str(),ios::out);
    //outfile<<
}
