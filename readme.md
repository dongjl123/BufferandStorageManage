### 数据结构
- 缓冲区LRU链表：用于buffer存放数据
- 缓冲区控制块BCB
- 哈希桶：用于判断是否命中(是否在LRU链表中)
- 文件索引块：用于查找文件存放的位置
- 文件数据块：用于存储数据

---
### 函数功能
#### LRU缓冲区
1. FrameSize = 4096，DefBufferSize = 1024
2. isEmpty()：链表为空
3. isFull()：链表满