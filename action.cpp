#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include <vector>
#include <string>
#include "actions.hpp"
using std::string, std::cout, std::cin;

string action;
std::vector<string> content;
const char *home{std::getenv("HOME")};
string path;
std::fstream file;

void config(const char* argv[])
{
    string action = string(argv[1]);
    if (!home)
    {
        home = std::getenv("USERPROFILE");
        path = string(home) + R"(\tasks.tks)";
    }

    if (home)
    {
        path = string(home) + "/tasks.tks";
    }
    else
    {
        cout << "ERROR!";
        return;
    }
    
    if (std::filesystem::exists(path))
    {
        file.open(path, std::ios::in | std::ios::app);
    }
    else
    {
        file.open(path, std::ios::in | std::ios::out | std::ios::app);
    }
}
void list();
void add();
void change();
void remove();
