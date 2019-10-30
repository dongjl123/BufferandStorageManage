#include <iostream>
#include <buffer.hpp>
#include <LRU.hpp>

using namespace std;

int main()
{
    LRU LRU_list = LRU();
    LRU_list.init_LRU();
    LRU_element L1;
    LRU_list.insert_node(&L1);
    int len = LRU_list.return_len();
}