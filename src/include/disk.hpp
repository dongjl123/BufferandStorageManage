#include <iostream>
#include <fstream>
#include <data.hpp>
#include <cstring>

#define DBF_FILE_NAME "data.dbf"

using namespace std;

class Disk
{

private:
    ifstream input;
    ofstream output;
    char *frame_data;
    void init_disk();

public:
    Disk();
    ~Disk();
    
    void disk_input(int pageID);
    void disk_output(int pageID);

};