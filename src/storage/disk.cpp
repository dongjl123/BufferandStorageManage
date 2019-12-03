#include "disk.hpp"
#include <ui.hpp>

/* create disk */
Disk::Disk(void)
{
    init_disk();
    IUI::print("disk has been created.");
}

/* drop disk */
Disk::~Disk()
{
    input.close();
    output.close();
    IUI::print("disk has been dropped.");
}

void Disk::init_disk()
{
    ofstream disk_file;
    disk_file.open(DBF_FILE_NAME);
    /* save the data in .dbf, max line:500000，max data size:4096 */
    char *data = (char *)malloc(DataNum*FrameSize);
    disk_file.write(data, DataNum*FrameSize);
    disk_file.close();

#ifdef DEBUG
    IUI::debug("data has been read.");
#endif
  
    input.open(DBF_FILE_NAME, ios::binary);
    output.open(DBF_FILE_NAME, ios::binary);

#ifdef DEBUG
    IUI::debug("init disk done");
#endif
}

void Disk::disk_input(int pageID)
{
    input.seekg((pageID * FrameSize), ios::beg);
    input.read(frame_data, FrameSize);
}

void Disk::disk_output(int pageID)
{
    output.seekp((pageID * FrameSize), ios::beg);
    output.write(frame_data, FrameSize);
}
