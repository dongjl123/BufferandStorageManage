/*===============================frame_LRU===============================*/
#include"LRU.hpp"

frame_LRU::frame_LRU(void)
{
    init_LRU();
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
        LRU_element *node = new LRU_element();
        node->frameID = i;
        insert_node(node);
    }
}

/* return the first node in frame_LRU */
LRU_element* frame_LRU::victim_node()
{
    LRU_element *node = return_head();
    return node;
}