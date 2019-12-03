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
    static void error(std::string message, int length);
    static void debug(char *message, int length);
    static void result(std::string message, int num);
    static void rule(std::string message);
    virtual ~IUI() = default;
};
