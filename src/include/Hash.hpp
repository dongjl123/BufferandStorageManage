#include <iostream>
#include <data.hpp>

using namespace std;

/*BCB的结构体*/
struct BCB
{
    bool isHead;        //判断是否是第一个指针
    bool isTail;       //判断是否是最后一个指针
    int frameID;
    int pageID;
    bool isWrite;       //数据是否被修改
    BCB *front;         //前一位指针
    BCB *next;          //后一位指针
};

class Hash
{
public:
    Hash();         //Hash的构造函数
    ~Hash();        //Hash的析构函数
    void init_Hash();       //Hash的初始化
    void insert_BCB(int frame_ID, int page_ID, bool is_Write);      //加入哈希桶
    void drop_BCB(BCB *victim_BCB);     //删除哈希桶中的一个节点
    bool has_page(int page_ID);     //判断该page_ID是否在已经buffer中
    BCB *find_BCB(int page_ID);     //找到该page_ID所对应的哈希桶中的节点
protected:
    BCB *HashTable[BufSize];        //基于BCB的哈希表
    int hash(int pageID);           //计算hash的值
};
