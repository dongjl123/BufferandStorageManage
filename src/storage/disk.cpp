#include "disk.hpp"

Disk::Disk(void)
{
    init_disk();
    cout<<"disk has been created."<<endl;
}

Disk::~Disk()
{
    input.close();
    output.close();
    cout<<"disk has been dropped."<<endl;
}

void Disk::init_disk()
{
    ofstream disk_file;
    disk_file.open(DBF_FILE_NAME);
    /* save the data in .dbf, max line:500000，max data size:4096 */
    char *data = (char *)malloc(DataNum*FrameSize);
    disk_file.write(data, DataNum*FrameSize);
    disk_file.close();
  
    input.open(DBF_FILE_NAME, ios::binary);
    output.open(DBF_FILE_NAME, ios::binary);

    cout<<"init disk done"<<endl;
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
