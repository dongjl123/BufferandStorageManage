#include "Hash.hpp"

Hash::Hash(void)
{
    init_Hash();
    cout<<"Hash has been created."<<endl;
}

Hash::~Hash()
{
    cout<<"Hash has been dropped."<<endl;
}

/*计算hash的值*/
int Hash::hash(int pageID)
{
    return pageID%BufSize;
}

/*Hash的初始化*/
void Hash::init_Hash()
{
    for(int i=0; i<BufSize; i++)
    {
        BCB *head = new BCB;
        BCB *tail = new BCB;

        head->isHead = true;
        head->isTail = false;
        head->front = nullptr;
        head->next = tail;

        tail->isHead = false;
        tail->isTail = true;
        tail->front = head;
        tail->next = nullptr;

        HashTable[i] = head;
    }
}

/*加入哈希桶*/
void Hash::insert_BCB(int frame_ID, int page_ID, bool is_Write)
{
    BCB *new_BCB = new BCB;
    new_BCB->frameID = frame_ID;
    new_BCB->pageID = page_ID;
    new_BCB->isWrite = is_Write;
    new_BCB->isHead = false;
    new_BCB->isTail = false;

    int BCB_hash = hash(page_ID);
    new_BCB->front = HashTable[BCB_hash];
    new_BCB->next = HashTable[BCB_hash]->next;
    HashTable[BCB_hash]->next->front = new_BCB;
    HashTable[BCB_hash]->next = new_BCB;
}

/*删除哈希桶中的一个节点*/
void Hash::drop_BCB(BCB *victim_BCB)
{
    victim_BCB->front->next = victim_BCB->next;
    victim_BCB->next->front = victim_BCB->front;
}

/*判断该page_ID是否在已经buffer中*/
bool Hash::has_page(int page_ID)
{
    int BCB_hash = hash(page_ID);
    BCB *node = HashTable[BCB_hash];
    while(!node->next->isTail)
    {
        if(node->next->pageID==page_ID)
        {
            return true;
        }
        node = node->next;
    }
    return false;
}

/*找到该page_ID所对应的哈希桶中的节点*/
BCB *Hash::find_BCB(int page_ID)
{
    int BCB_hash = hash(page_ID);
    BCB *node = HashTable[BCB_hash];
    while(!node->next->isTail)
    {
        if(node->next->pageID==page_ID)
        {
            return node->next;
        }
        node = node->next;
    }
}