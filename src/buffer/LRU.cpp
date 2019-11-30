#include"LRU.hpp"

/*构造函数*/
LRU::LRU(void)
{
    init_LRU();
    cout<<"LRU has been created."<<endl;
}

/*析构函数*/
LRU::~LRU()
{
    cout<<"LRU had been dropped."<<endl;
}

/*LRU链表头节点初始化*/
void LRU::init_head()
{
    head.isHead = true;
    head.isTrail = false;
    head.front = nullptr;
    head.next = &trail;
}

/*LRU尾节点初始化*/
void LRU::init_trail()
{
    trail.isHead = false;
    trail.isTrail = true;
    trail.front = &head;
    trail.next = nullptr;
}

void LRU::init_LRU()
{
    init_head();
    init_trail();
    LRU_len = 0;
}

/*向链表中添加新的节点到尾部*/
void LRU::insert_node(LRU_element *new_node)
{
    new_node->next = &trail;
    new_node->front = trail.front;
    new_node->front->next = new_node;
    new_node->isHead = false;
    new_node->isTrail = false;
    trail.front = new_node;
    LRU_len++;
}

/*返回链表的第一个节点*/
LRU_element* LRU::return_head()
{
    LRU_element *true_head = head.next;
    return true_head;
}

/*返回链表的最后一个节点*/
LRU_element* LRU::return_tail()
{
    LRU_element *true_trail = trail.front;
    return true_trail;
}

/*drop链表的第一个节点*/
void LRU::drop_head()
{
    LRU_element *true_head = head.next;
    head.next = true_head->next;
    true_head->next->front = &head;
    LRU_len--;
}

void LRU::adjust_LRU(LRU_element *node)
{
    node->front->next = node->next;
    node->next->front = node->front;
    trail.front->next = node;
    trail.front = node;
    node->front = trail.front;
    node->next = &trail;
}

void LRU::adjust_page(int page_num)
{
    current = &head;
    while(current->next->frameID!=page_num)
    {
        current = current->next;
    }
    adjust_LRU(current);
}

/*返回LRU链表的长度*/
int LRU::return_len()
{
    return LRU_len;
}

/*判断LRU链表是否已满，满返回1，否则为0*/
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


/*===============================frame_LRU================================*/

frame_LRU::frame_LRU(void)
{
    init_frame();
    cout<<"Frame LRU has been created"<<endl;
}

frame_LRU::~frame_LRU()
{
    cout<<"Frame LRU has been dropped"<<endl;
}

void frame_LRU::init_frame()
{
    for(int i=0; i<BufSize; i++)
    {
        LRU_element node;
        node.frameID = i;
        insert_node(&node);
    }
}

bool frame_LRU::isempty()
{
    if(return_len()==0)
        return true;
    else
        return false;
}

void frame_LRU::drop_frame()
{
    drop_head();
}

LRU_element* frame_LRU::victim_node()
{
    LRU_element *node = return_head();
    return node;
}