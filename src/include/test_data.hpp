#include <data.hpp>

struct Test_Data
{
    bool iswrite;
    int page_num;
};

Test_Data test[DataNum];     //用于保存输入的测试数据
int Buffer_Hit = 0;     //从buffer中读取的次数
int IO_Hit = 0;         //IO次数