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

/*向链表中添加新的节点*/
void LRU::insert_node(LRU_element *new_node)
{
    new_node->next = &trail;
    new_node->front = trail.front;
    new_node->front->next = new_node;
    trail.front = new_node;
}