#include <iostream>
#include <fstream>
#include <data.hpp>
#include <cstring>

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