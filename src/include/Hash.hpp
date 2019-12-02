#include <iostream>
#include <data.hpp>

using namespace std;

/*BCB的结构体*/
struct BCB
{
    bool isHead;
    bool isTail;
    int frameID;
    int pageID;
    bool isWrite;       //whether data need to write to the disk
    BCB *front;
    BCB *next;
};

class Hash
{
protected:
    BCB *HashTable[BufSize];
    int hash(int pageID);           //calculate hash
    void init_Hash();

public:
    Hash();         //create Hash
    ~Hash();        //drop Hash
    void insert_BCB(int frame_ID, int page_ID, bool is_Write);
    void drop_BCB(BCB *victim_BCB);     //drop the first node in BCB
    bool has_page(int page_ID);     //whether the pageID is in buffer
    BCB *find_BCB(int page_ID);     //find the BCB node with that pageID

};
