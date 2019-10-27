#include"LRU.hpp"

/*构造函数*/
LRU::LRU(void)
{
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

/*向链表中添加新的节点到尾部*/
void LRU::insert_node(LRU_element *new_node)
{
    new_node->next = &trail;
    new_node->front = trail.front;
    new_node->front->next = new_node;
    trail.front = new_node;
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