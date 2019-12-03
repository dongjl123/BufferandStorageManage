#include <iostream>
#include <fstream>
#include <LRU.hpp>
#include <Hash.hpp>
#include <disk.hpp>
#include <data.hpp>
#include <test_data.hpp>
#include <ui.hpp>
#include <string>

int main()
{
    /* init */
    IUI::rule("begin to init");
    LRU LRU_list = LRU();
    frame_LRU frame = frame_LRU();
    Hash hash = Hash();
    Disk *disk_str = new Disk();
    
    /* read file */
    IUI::rule("begin to read file");
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

    /* handle data request */
    IUI::rule("handle data request");
    for(num=0; num<TestNum; num++)
    {
        bool iswrite = test[num].iswrite;
        int page_num = test[num].page_num;

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
                LRU_element *new_node = new LRU_element();
                new_node->pageID = page_num;
                new_node->frameID = frame_ID;
                new_node->isHead = false;
                new_node->isTail = false;
                LRU_list.drop_node(victim_node);
                LRU_list.insert_node(new_node);
                if(!LRU_list.isfull())
                    cout<<"LRU insert error"<<endl;
            }
            /* LRU is not full and still have free frame */
            else                 
            {
                /* updtae frame LRU */
                LRU_element *frame_node = frame.return_head();
                int frame_num = frame_node->frameID;
                if(!frame.drop_head())
                    IUI::error("error in drop head!");

                /* update LRU */
                LRU_element *new_node = new LRU_element();
                new_node->pageID = page_num;
                new_node->frameID = frame_num;
                new_node->isHead = false;
                new_node->isTail = false;
                LRU_list.insert_node(new_node);

                /* update HashTable */
                hash.insert_BCB(frame_num, page_num, iswrite);
            }
            
        }
        
    }

    IUI::rule("begin to print result");
    IUI::result("Buffer_Hit is: ", Buffer_Hit);
    IUI::result("IO_Hit is: ", IO_Hit);
    IUI::rule("end");
}