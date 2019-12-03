### 项目的编译和运行
#### release版本
在主项目文件夹下：
linux命令行：
```shell
$ mkdir Release
$ cd Release
$ cmake ../
$ make
$ cd bin
$ ./main
```
windows命令行：
```shell
mkdir Release
cd Release
cmake -G"MinGW Makefiles" ../
mingw32-make
cd bin
main.exe
```
#### debug版本
linux命令行：
```shell
$ mkdir Debug
$ cd Debug
$ cmake -DCMAKE_BUILD_TYPE=Debug ../
$ cd bin
$ ./main
```

windows命令行：
```shell
mkdir Debug
cd Debug
cmake -G"MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug ../
cd bin
main.exe
```

---
### 数据结构
1. 缓冲区LRU链表：用于buffer存放数据，LRU的数据结构
```c
struct LRU_element
{
    bool isHead;
    bool isTail;
    int frameID;
    int pageID;
    LRU_element *front;
    LRU_element *next;     
};
```
2. 缓冲区控制块BCB
```c
struct BCB
{
    bool isHead;
    bool isTail;
    int frameID;
    int pageID;
    bool isWrite;
    BCB *front;
    BCB *next;
};
```
3. 哈希桶：用于判断是否命中(是否在LRU链表中)

`BCB *HashTable[buffersize]`

基本思想是通过`hash(pageID) = pageID % buffersize`找到在哈希桶的哪一个位置，然后采用链表的方法存入。

4. 文件索引块：用于查找文件存放的位置
5. 文件数据块：用于存储数据
6. FrameSize = 4096，DefBufferSize = 1024

---
### 主要功能
#### LRU缓冲区

1. `init_LRU()`用于LRU链表的初始化
2. `LRU_element* return_head()`和`LRU_element* return_tail()`用于返回链表的头节点和尾节点
3. `void insert_node(LRU_element *new_node)`用于向链表尾部添加新的节点
4. `void drop_head()`用于drop链表中的第一个节点
5. `void adjust_LRU(LRU_element *node)`用于LRU算法中节点的位置变更(把该节点放到链表的末尾) 
6. `int return_len()`用于返回LRU链表的长度
7. `bool FULL_LRU()`用于判断LRU链表是否已满

#### Hash哈希桶

1. `init_Hash()`用于Hash的初始化
2. `int hash`用于计算hash值，为`pageID % buffersize`
3. `insert_BCB`和`drop_BCB`用于插入和删除节点
4. `has_page`用于判断是否在表中，为bool型
5. `find_BCB`用于在`has_page`为真的时候返回该pageID所对应的节点