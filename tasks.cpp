#include "actions.hpp"
#include <string>
#include <iostream>

int main(int argc,const char *argv[])
{
    if (argc > 1)
    {
        char*args[20];
        for (int i = 0; i < argc; i++)
        {
            args[i] = const_cast<char *>(argv[i]);
        }
        std::string action{};
        config(argc,args,&action);

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