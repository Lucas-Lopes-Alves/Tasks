#include "actions.hpp"
#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        std::string action{};
        config(argc,(const char**)argv,&action);

        if (action == "add")
        {
            return add();
        }
        else if (action == "remove")
        {
            return remove();
        }
        else if (action == "change")
        {
            return change();
        }
        else if (action == "list")
        {
            list();
            return 0;
        } else if(action == "--help")
        {
            std::cout  << "use: tasks [COMMAND] [..OPTIONS] \n \n"
                  << "add                     adds a new task to the task file \n"
                  << "change                     changes the task to another \n"
                  << "remove                     removes a task \n \n";
            return 0;
        }
    }
    else
    {
        std::cerr << "Error: missing arguments\n"
                  << "use: tasks [COMMAND] [..OPTIONS] \n \n"
                  << "add                     adds a new task to the task file \n"
                  << "change                     changes the task to another \n"
                  << "remove                     removes a task \n \n";
        return 1;
    }
    return 0;
}