#include <iostream>
#include <fstream>
#include <data.hpp>

#define DBF_FILE_NAME "data.dbf"
#define DBF_LOG_NAME "data.log"

using namespace std;

class Disk
{
public:
    // Disk();
    // ~Disk();
    void init_disk();
    void disk_input(int pageID);
    void disk_output(int pageID);
private:
    ifstream input;
    ofstream output;
    ofstream log;
    char *frame_data;
};
