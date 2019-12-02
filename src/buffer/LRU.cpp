#include"LRU.hpp"

/* create LRU */
LRU::LRU(void)
{
    init_LRU();
    cout<<"LRU has been created."<<endl;
}

/* drop LRU */
LRU::~LRU()
{
    cout<<"LRU had been dropped."<<endl;
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
    return LRU_len;
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

void LRU::drop_node(LRU_element *node)
{
    node->front->next = node->next;
    node->next->front = node->front;
    LRU_len--;
}

/* drop the true head */
void LRU::drop_head()
{
    LRU_element *true_head = head.next;
    if(!true_head->isTail)
    {
        head.next = true_head->next;
        true_head->next->front = &head;
        LRU_len--;
    }
    else
    {
        cout<<"error in drop head!"<<endl;
    }
    
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
        // cout<<node->pageID<<" ";
        if(node->pageID==page_num)
        {
            // cout<<endl;
            drop_node(node);
            insert_node(node);
            return;
        }        
    }
    cout<<"error in adjust page!"<<endl;;
    
}


