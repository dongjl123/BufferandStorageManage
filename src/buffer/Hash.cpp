#include "Hash.hpp"
#include <ui.hpp>

/* create Hash */
Hash::Hash(void)
{
    init_Hash();
    IUI::print("Hash has been created.");
}

/* drop Hash */
Hash::~Hash()
{
    IUI::print("Hash has been dropped.");
}

/* calculate hash */
int Hash::hash(int pageID)
{
    return pageID%BufSize;
}

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
#ifdef DEBUG
    IUI::debug("init hash done.");
#endif
}

/* insert new BCB to HashTable */
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

/* drop the first node in BCB */
void Hash::drop_BCB(BCB *victim_BCB)
{
    victim_BCB->front->next = victim_BCB->next;
    victim_BCB->next->front = victim_BCB->front;
}

/* whether the pageID is in buffer */
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

/* find the BCB node with that pageID */
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
    IUI::error("error in find BCB!");
}