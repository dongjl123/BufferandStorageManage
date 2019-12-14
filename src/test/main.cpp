#include <iostream>
#include <fstream>
#include <LRU.hpp>
#include <Hash.hpp>
#include <disk.hpp>
#include <data.hpp>
#include <test_data.hpp>
#include <ui.hpp>
#include <time.h>
#include <string>

int main()
{
    /* print time */
    string time = getTime();
    cout << time << endl;

    /* init */
    IUI::rule("init system");
    IUI::print("Buffer Size is :", BufSize);
    LRU LRU_list = LRU();
    frame_LRU frame = frame_LRU();
    Hash hash = Hash();
    Disk *disk_str = new Disk();
    
    /* read file */
    IUI::rule("read file data");
    ifstream data_file(TestFile);
    int num = 0;
    while(num < TestNum)
    {
        string data, rw, page_num;
        int data_len;
        getline(data_file, data);       //read data from data_file
        data_len = data.length();
        rw = data.substr(0,1);      //read or write
        if(rw=="1")
            test[num].iswrite = true;
        else
            test[num].iswrite = false;
        page_num = data.substr(2,data_len-2);       //save pageID
        int page = atoi(page_num.c_str());
        test[num].page_num = page;
        num ++;
    }
    IUI::print("read the file done.");

    /* handle data request */
    IUI::rule("handle data request");

    clock_t start,finish;
    double totaltime;
    start=clock();

    bool LRUfull = false;
    IUI::print_rate("begin to handle data.", 0);

    for(num=0; num<TestNum; num++)
    {
        bool iswrite = test[num].iswrite;
        int page_num = test[num].page_num;
        if(num==TestNum/2)
             IUI::print_rate("handling data...", 50);

        /* whether is in buffer */
        if(hash.has_page(page_num))
        {    
            Buffer_Hit++;
            LRU_list.adjust_page(page_num);
        }
        else
        {
            IO_Hit++;
            disk_str->disk_input(page_num);
            /* whether LRU is full and frame is empty */
            if(frame.isempty())       
            {
                if(!LRUfull)
                {
                    double rate = (double)num/(double)TestNum*100+(double)(TestNum-num)/(double)TestNum*5;
                    int p = (int )rate;
                    IUI::print_rate("LRU is full now.", rate);
                    LRUfull = true;
                }
                
                /* victim node in LRU */
                LRU_element *victim_node = new LRU_element();
                victim_node = LRU_list.return_head();
                int victim_frameID = victim_node->frameID;
                int victim_pageID = victim_node->pageID;

                /* update HashTable */
                BCB *victim_BCB = hash.find_BCB(victim_pageID);     //find the BCB node in Hash with victim pageID
                if(victim_BCB->isWrite == true)     //whether need to write to the disk(data has been changed)
                    disk_str->disk_output(victim_pageID);
                int frame_ID = victim_BCB->frameID;
                hash.drop_BCB(victim_BCB);
                hash.insert_BCB(frame_ID, page_num, iswrite);       //insert noew BCB node
                delete victim_BCB;
                
                /* update LRU */
                LRU_list.insert_new_node(page_num, frame_ID);
                LRU_list.drop_node(victim_node);
                if(!LRU_list.isfull())
                    IUI::error("LRU insert error!");
                delete victim_node;
            }
            /* LRU is not full and still have free frame */
            else                 
            {
                /* updtae frame LRU */
                LRU_element *frame_head = frame.return_head();
                int frame_num = frame_head->frameID;
                if(!frame.drop_head())
                    IUI::error("error in drop head!");
                delete frame_head;

                /* update LRU */
                LRU_list.insert_new_node(page_num, frame_num);

                /* update HashTable */
                hash.insert_BCB(frame_num, page_num, iswrite);
            }
            
        }
        
    }
    IUI::print_rate("handle data done.", 100);

    IUI::rule("print result");
    IUI::result("Buffer_Hit is: ", Buffer_Hit);
    IUI::result("IO_Hit is: ", IO_Hit);

    IUI::rule("end");

    finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    IUI::time_result("time is: ", totaltime);

}