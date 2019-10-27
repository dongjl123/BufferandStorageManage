#include<iostream>

using namespace std;

/*LRU链表的结构体*/
struct LRU_element
{
    bool isHead;        //是否是链表的第一个指针
    bool isTrail;       //是否是链表的最后一个指针
    int frameID;        //对应的缓冲区帧号
    int pageID;         //缓冲区帧对应的块块号
    LRU_element *front;     //指针指向LRU链表中的前一个成员
    LRU_element *next;      //指针指向LRU链表中的后一个成员
}LRU_E;

class LRU
{
protected:
    LRU_element head;       //定义LRU链表的头指针
    LRU_element trail;      //定义LRU链表的尾指针
    LRU_element *current;       //定义LRU链表中现在指向的指针
    
public:
    LRU();      //LRU构造函数
    ~LRU();     //LRU析构函数
    void init_head();       //初始化head节点
    void init_trail();      //初始化尾节点
    void insert_node(LRU_element *new_node);        //向链表中添加新的节点到尾部
    LRU_element* return_head();     //返回链表的第一个节点
    LRU_element* return_tail();     //返回链表的最后一个节点
    void drop_head();       //drop链表中的第一个节点
    void adjust_LRU(LRU_element *node);     //把node放到链表的trail中去
};

