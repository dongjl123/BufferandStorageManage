#include <iostream>

using namespace std;

class IUI
{
public:
    void virtual run() = 0;
    static void print(std::string message);
    static void error(std::string message);
    static void debug(std::string message);
    static void print(char *message, int length);
    static void error(char *message, int length);
    static void debug(char *message, int length);
    virtual ~IUI() = default;
};
