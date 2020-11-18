#ifndef AQIFILEIO_H
#define AQIFILEIO_H
#include<cstring>
#include<iostream>
using namespace std;
class AQIFileIO
{
    public:
        AQIFileIO();
        virtual ~AQIFileIO();

        void setReadFile(string szfile){m_szFileName = szfile;}
        //读取文件
        bool readFile();
        //写重新计算后的数据
        bool writeFile(string szfile);

    protected:
        string m_szFileName;

    private:
};

#endif // AQIFILEIO_H
