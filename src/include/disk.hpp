#include <iostream>
#include <fstream>

#define DBF_FILE_NAME "data.dbf"
#define DBF_LOG_NAME "data.log"

using namespace std;

class disk
{
public:
    disk();
    ~disk();
    void init_disk();
    void disk_input(int pageID);
    void disk_output(int pageID);
private:
    ifstream input;
    ofstream output;
    ofstream log;
    char *frame_data;
};