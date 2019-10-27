#define FrameSize 4096      //定义buffer中每个frame的大小为4096
#define BufSize 1024        //定义buffer的大小为1024

/*定义frame的结构体*/
struct frame
{
    char field[FrameSize];
};

/*定义buffer的结构体*/
struct buffer
{
    frame buf[BufSize];
};