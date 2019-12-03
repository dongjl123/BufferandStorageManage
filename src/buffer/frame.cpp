/*===============================frame_LRU===============================*/
#include"LRU.hpp"
#include <ui.hpp>

frame_LRU::frame_LRU(void)
{
    init_LRU();
    init_frame();
    IUI::print("Frame LRU has been created");
}

frame_LRU::~frame_LRU()
{
    IUI::print("Frame LRU has been dropped");
}

void frame_LRU::init_frame()
{
    for(int i=0; i<BufSize; i++)
    {
        LRU_element *node = new LRU_element();
        node->frameID = i;
        insert_node(node);
    }
#ifdef DEBUG
    IUI::debug("init frame done.");
#endif
}

/* return the first node in frame_LRU */
LRU_element* frame_LRU::victim_node()
{
    LRU_element *node = return_head();
    return node;
}