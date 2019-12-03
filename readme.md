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
### 基本数据

- FrameSize：frame的大小，为4096
- BufSize：buffer的大小，为1024
- DataNum：测试的最大数据大小，为500000
- TestNum：测试数据的大小，500000
- TestFile：用于测试的文件，"../../data-5w-50w-zipf.txt" 
- DBF_FILE_NAME：用于保存数据库的文件，"data.dbf"

---
### 输出结果形式

Buffer Hit的次数以及IO Hit的次数

---
### 数据结构
1. 用于保存测试数据的结构
```c
struct Test_Data
{
    bool iswrite;
    int page_num;
};
```

2. 缓冲区LRU链表：用于buffer存放数据，LRU的数据结构
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

3. 缓冲区控制块BCB
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
4. 哈希桶：用于判断是否命中(是否在LRU链表中)

`BCB *HashTable[buffersize]`

基本思想是通过`hash(pageID) = pageID % buffersize`找到在哈希桶的哪一个位置，然后采用链表的方法存入。


---
### 主要的类
#### LRU缓冲区

1. `void init_LRU()`用于LRU链表的初始化
2. `bool isfull()`和`bool isempty()`用于链表长度的判断
3. `LRU_element* return_head()`和`LRU_element* return_tail()`用于返回链表的头节点和尾节点
4. `void insert_node(LRU_element *new_node)`和`void insert_new_node(int pageID, int frameID)`用于向链表尾部添加新的节点
5. `void drop_head()`和`void drop_node(LRU_element *node)`用于drop链表中节点
6. `int return_len()`用于返回LRU链表的长度
7. `bool FULL_LRU()`用于判断LRU链表是否已满
8. `void adjust_LRU(LRU_element *node)`和`void adjust_page(int page_num)`用于链表节点位置的调整

#### frame_LRU

继承了LRU的类，用于存储可使用的frame的值。

1. `void init_frame()`用于frame_LRU链表的初始化
2. `LRU_element* victim_node()`用于找出第一个可用的frame

#### Hash哈希桶

1. `init_Hash()`用于Hash的初始化
2. `int hash`用于计算hash值，为`pageID % buffersize`
3. `insert_BCB`和`drop_BCB`用于插入和删除节点
4. `has_page`用于判断是否在表中，为bool型
5. `find_BCB`用于在`has_page`为真的时候返回该pageID所对应的节点

#### Disk存储类
1. `void init_disk()`用于Disk类的初始化
2. `void disk_input(int pageID)`和`void disk_output(int pageID)`用于向磁盘写入或从磁盘读出数据

#### IUI界面类
1. `print`用于正常输出界面
2. `error`用于报错界面
3. `debug`用于调试界面
4. `rule`用于分割界面
5. `print_rate`用于进度界面的显示