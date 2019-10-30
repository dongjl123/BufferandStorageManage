### 数据结构
- 缓冲区LRU链表：用于buffer存放数据，LRU的数据结构
```c
struct LRU_element
{
    bool isHead;
    bool isTrail;
    int frameID;
    int pageID;
    LRU_element *front;
    LRU_element *next;     
};
```
- 缓冲区控制块BCB
- 哈希桶：用于判断是否命中(是否在LRU链表中)
- 文件索引块：用于查找文件存放的位置
- 文件数据块：用于存储数据

---
### 函数功能
#### LRU缓冲区
1. FrameSize = 4096，DefBufferSize = 1024
2. `init_LRU()`和用于LRU链表的初始化
3. `LRU_element* return_head()`和`LRU_element* return_tail()`用于返回链表的头节点和尾节点
4. `void insert_node(LRU_element *new_node)`用于向链表尾部添加新的节点
5. `void drop_head()`用于drop链表中的第一个节点
6. `void adjust_LRU(LRU_element *node)`用于LRU算法中节点的位置变更(把该节点放到链表的末尾) 
7. `int return_len()`用于返回LRU链表的长度
8. `bool FULL_LRU()`用于判断LRU链表是否已满