#include <iostream>
#include <fstream>
#include <LRU.hpp>
#include <Hash.hpp>
#include <disk.hpp>
#include <data.hpp>
#include <string>

// using namespace std;

int main()
{
    /* 初始化 */
    LRU LRU_list = LRU();
    Hash hash = Hash();
    Disk *disk_str = new Disk();
    cout<<"main"<<endl;
    // LRU *LRU_list = new LRU();
    // Hash *hash = new Hash();
    // Disk *disk_str = new Disk();

    // delete LRU_list;
    // delete hash;
    // delete disk_str;
    
    /* 读取文件 */
    // ifstream data_file("data-5w-50w-zipf.txt");
    // int num = 0;        //起始数据从0开始计数
    // while(num < TestNum)
    // {
    //     string data, rw, page_num;
    //     data = "1,1000";
    //     int data_len;
    //     getline(data_file, data);       //从data_file中逐行往下读取数据
    //     data_len = data.length();
    //     rw = data.substr(0,1);
    //     cout<<rw<<endl;
    //     page_num = data.substr(2,data_len-2);
    //     cout<<page_num<<endl;
    //     num ++;
    // }
}