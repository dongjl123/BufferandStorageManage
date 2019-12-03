#include"LRU.hpp"
#include <ui.hpp>

/* create LRU */
LRU::LRU(void)
{
    init_LRU();
    IUI::print("LRU has been created.");
}

/* drop LRU */
LRU::~LRU()
{
    IUI::print("LRU has been dropped.");
}

void LRU::init_head()
{
    head.isHead = true;
    head.isTail = false;
    head.front = nullptr;
    head.next = &tail;
}

void LRU::init_tail()
{
    tail.isHead = false;
    tail.isTail = true;
    tail.front = &head;
    tail.next = nullptr;  
}

/* init a LRU list include a head and a tail */
void LRU::init_LRU()
{
    init_head();
    init_tail();
    LRU_len = 0;
}

int LRU::return_len()
{
    if(LRU_len<=BufSize)
        return LRU_len;
    else
    {
        IUI::error("LRU len is error: ", LRU_len);
        return -1;
    }
    
}

bool LRU::isfull()
{
    int len = return_len();
    if(len < BufSize)
    {
        return false;
    }
    else if(len == BufSize)
    {
        return true;
    }
    else
    {
        cout<<"The length of the LRU is wrong"<<endl;
        return 0;
    }
}

bool LRU::isempty()
{
    if(return_len()==0)
        return true;
    else
        return false;
}

/* return the true head */
LRU_element* LRU::return_head()
{
    LRU_element *true_head = head.next;
    return true_head;
}

/* return the true tail */
LRU_element* LRU::return_tail()
{
    LRU_element *true_tail = tail.front;
    return true_tail;
}

/* inset a new node bufore trail */
void LRU::insert_node(LRU_element *new_node)
{
    new_node->next = &tail;
    new_node->front = tail.front;
    new_node->front->next = new_node;
    new_node->isHead = false;
    new_node->isTail = false;
    tail.front = new_node;
    LRU_len++;
}

void LRU::insert_new_node(int pageID, int frameID)
{
    LRU_element *new_node = new LRU_element();
    new_node->pageID = pageID;
    new_node->frameID = frameID;
    new_node->isHead = false;
    new_node->isTail = false;
    insert_node(new_node);
}

void LRU::drop_node(LRU_element *node)
{
    node->front->next = node->next;
    node->next->front = node->front;
    LRU_len--;
}

/* drop the true head */
int LRU::drop_head()
{
    int rnt = 0;
    LRU_element *true_head = head.next;
    if(!true_head->isTail)
    {
        head.next = true_head->next;
        true_head->next->front = &head;
        LRU_len--;
        rnt = 1;
    }
    else
        goto end;

end:
    return rnt;   
}

void LRU::adjust_LRU(LRU_element *node)
{
    node->front->next = node->next;
    node->next->front = node->front;
    tail.front->next = node;
    tail.front = node;
    node->front = tail.front;
    node->next = &tail;
}

void LRU::adjust_page(int page_num)
{
    LRU_element *node = new LRU_element();
    node = &tail;
    while(!node->front->isHead)
    {
        node = node->front;
        if(node->pageID==page_num)
        {
            drop_node(node);
            insert_node(node);
            return;
        }        
    }
    IUI::error("error in adjust page!"); 
}


