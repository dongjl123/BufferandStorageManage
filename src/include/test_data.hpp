#include <data.hpp>

struct Test_Data
{
    bool iswrite;
    int page_num;
};

Test_Data test[DataNum];    
int Buffer_Hit = 0;     
int IO_Hit = 0;         