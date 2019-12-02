#include<iostream>
#include<data.hpp>

using namespace std;

/*LRU链表的结构体*/
struct LRU_element
{
    bool isHead;
    bool isTail;
    int frameID;
    int pageID;
    LRU_element *front;
    LRU_element *next;
};

class LRU
{
protected:
    
    

public:

    LRU_element head;       //head with no information
    LRU_element tail;      //tail with no information
    LRU_element *current;
    int LRU_len;    
    LRU();      //create LRU
    ~LRU();     //drop LRU
    void init_head();
    void init_trail();
    void init_LRU();        //include init_head and init_trail
    int return_len();
    bool isfull();
    LRU_element* return_head();     //return the node after head
    LRU_element* return_tail();     //return the node before tail
    void insert_node(LRU_element *new_node);        //insert a new node before tail
    void drop_node(LRU_element *node);
    void drop_head();       //drop the node after head
    /* adjust the LRU */
    void adjust_LRU(LRU_element *node);
    void adjust_page(int page_num);
    
};

/* 用于存储剩余可用的frame_ID */
class frame_LRU:public LRU
{
public:
    frame_LRU();        //构造函数
    ~frame_LRU();       //析构函数
    void init_frame();
    bool isempty();     //是否为空
    void drop_frame();
    LRU_element* victim_node();
};



