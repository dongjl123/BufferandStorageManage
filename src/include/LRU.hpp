#include<iostream>
#include<data.hpp>

using namespace std;

/*LRU struct*/
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
    LRU_element head;       //head with no information
    LRU_element tail;      //tail with no information
    LRU_element *current;
    int LRU_len; 
    void init_head();
    void init_tail();

public:      
    LRU();      //create LRU
    ~LRU();     //drop LRU
    
    void init_LRU();        //include init_head and init_tail
    int return_len();
    bool isfull();
    bool isempty();
    LRU_element* return_head();     //return the node after head
    LRU_element* return_tail();     //return the node before tail
    void insert_node(LRU_element *new_node);        //insert a new node before tail
    void drop_node(LRU_element *node);
    void drop_head();       //drop the node after head
    /* adjust the LRU */
    void adjust_LRU(LRU_element *node);
    void adjust_page(int page_num);
    
};

/* used to storage the rest frameID */
class frame_LRU:public LRU
{
public:
    frame_LRU();        
    ~frame_LRU();
    void init_frame();
    LRU_element* victim_node();     //return the first node
};



