#include <iostream>
#include <fstream>
#include <LRU.hpp>
#include <Hash.hpp>
#include <disk.hpp>
#include <data.hpp>
#include <test_data.hpp>
#include <string>

// using namespace std;

int main()
{
    /* 初始化 */
    LRU LRU_list = LRU();
    frame_LRU frame = frame_LRU();
    Hash hash = Hash();
    Disk *disk_str = new Disk();
    
    /* 读取文件 */
    ifstream data_file("data-5w-50w-zipf.txt");
    int num = 0;        //起始数据从0开始计数
    while(num < TestNum)
    {
        string data, rw, page_num;
        int data_len;
        getline(data_file, data);       //从data_file中逐行往下读取数据
        data_len = data.length();
        rw = data.substr(0,1);      //用于保存时读取还是写入
        if(rw=="1")
            test[num].iswrite = true;
        else
            test[num].iswrite = false;
        page_num = data.substr(2,data_len-2);       //用于保存页号
        int page = atoi(page_num.c_str());
        test[num].page_num = page;
        num ++;
    }

    /* 处理数据请求 */
    for(num=0; num<TestNum; num++)
    {
        bool iswrite = test[num].iswrite;
        int page_num = test[num].page_num;
        // cout<<"num is "<<num<<endl;
        // cout<<page_num<<endl;

        /* 是否在buffer中 */
        if(hash.has_page(page_num))
        {
            // cout<<"Buffer"<<endl;       
            Buffer_Hit++;
            LRU_list.adjust_page(page_num);
        }
        else
        {
            IO_Hit++;
            disk_str->disk_input(page_num);
            /* 判断LRU链表是否已满 */
            if(frame.isempty())       //已满
            {
                /* adjust新的节点到LRU链表中 */
                LRU_element *victim_node = new LRU_element();
                victim_node = LRU_list.return_head();
                int victim_frameID = victim_node->frameID;
                int victim_pageID = victim_node->pageID;

                /* 更新Hash桶 */
                BCB *victim_BCB = hash.find_BCB(victim_pageID);     //找到hash桶中对应的位置
                if(victim_BCB->isWrite == true)     //判断是否有写入
                    disk_str->disk_output(victim_pageID);
                int frame_ID = victim_BCB->frameID;
                hash.drop_BCB(victim_BCB);
                hash.insert_BCB(frame_ID, page_num, iswrite);
                delete victim_BCB;
                
                /* 更新新节点 */
                LRU_element *new_node = new LRU_element();
                new_node->pageID = page_num;
                new_node->frameID = frame_ID;
                new_node->isHead = false;
                new_node->isTrail = false;
                LRU_list.drop_node(victim_node);
                LRU_list.insert_node(new_node);
                if(!LRU_list.isfull())
                    cout<<"LRU insert error"<<endl;
            }
            else                        //链表中还有空闲位置
            {
                /* 更新frame列表 */
                LRU_element *frame_node = frame.return_head();
                int frame_num = frame_node->frameID;
                frame.drop_head();

                /* 更新LRU */
                LRU_element *new_node = new LRU_element();
                new_node->pageID = page_num;
                new_node->frameID = frame_num;
                new_node->isHead = false;
                new_node->isTrail = false;
                LRU_list.insert_node(new_node);

                /* 更新Hash */
                hash.insert_BCB(frame_num, page_num, iswrite);
            }
            
        }
        
    }

    cout<<"Buffer_Hit is "<<Buffer_Hit<<endl;
    cout<<"IO_Hit is "<<IO_Hit<<endl;
}