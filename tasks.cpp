#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include <vector>
#include <string>
using std::string, std::cin, std::cout;

int main(int argc, const char *argv[])
{
    if (argc > 1)
    {
        string action{string(argv[1])};
        std::vector<string> content;
        const char *home{std::getenv("HOME")};
        string path;
        if (!home)
        {
            home = std::getenv("USERPROFILE");
            path = string(home) + "/tasks.txt";
        }

        if (home)
        {
            path = string(home) + "/tasks.txt";
        }
        else
        {
            cout << "ERROR!";
            return 1;
        }

        std::fstream file;
        if (std::filesystem::exists(path))
        {
            file.open(path, std::ios::in | std::ios::app);
        }
        else
        {
            file.open(path, std::ios::in | std::ios::out | std::ios::app);
        }

        if (action == "add")
        {

            if (argc < 3)
            {
                std::cerr << "Error: missing arguments \n"
                          << R"(Usage: task add "{task description}")" << '\n';
                return 1;
            }
            else
            {
                string task = string(argv[2]);
                file << task << '\n';
            }
            cout << "Successfully added a task" << '\n';
        }
        else if (action == "remove")
        {

            if (argc < 3)
            {
                std::cerr << "Error: missing arguments" << '\n'
                          << R"(Usage: tasks remove {number})" << '\n';
                return 1;
            }
            else
            {
                if (string(argv[2]) == "--all")
                {

                    content.clear();
                    for (string strings : content)
                    {
                        file << strings << '\n';
                    }

                    file.close();
                    std::fstream file(path, std::ios::out);
                    cout << "Successfully removed all the tasks" << '\n';
                }
                else
                {
                    string temporary;
                    while (std::getline(file, temporary))
                    {
                        content.push_back(temporary);
                    }

                    int taskPosition{std::stoi(string(argv[2]))};
                    if (taskPosition - 1 <= -1 || taskPosition > content.size())
                    {
                        std::cerr << "Error: cannot change an inexistent task" << '\n';
                        return 1;
                    }
                    content.erase(content.begin() + (taskPosition));
                    file.close();

                    std::fstream file(path, std::ios::out);
                    for (string temporary : content)
                    {
                        file << temporary << '\n';
                    }
                    content.clear();
                }
            }
        }
        else if (action == "change")
        {

            if (argc < 4)
            {
                std::cerr << "Error: missing arguments \n"
                          << R"(Usage: tasks change {number} "{task}")";
                return 1;
            }
            else
            {
                string temporary;
                while (std::getline(file, temporary))
                {
                    content.push_back(temporary);
                }

                int option{std::stoi(string(argv[2]))};
                if (option - 1 <= -1 || option > content.size())
                {
                    std::cerr << "Error: cannot change an inexistent task" << '\n';
                    return 1;
                }
                string before = content[option - 1];
                content[option - 1] = string(argv[3]);
                file.close();

                file.open(path, std::ios::out);
                for (string vector : content)
                {
                    file << vector << '\n';
                }

                content.clear();
                cout << "Successfully changed "
                     << R"(")" << before << R"(" to ")"
                     << content[option - 1] << R"(")" << '\n';
            }
        }
        else if (action == "list")
        {

            string temporary;
            int taskPosition{};

            while (std::getline(file, temporary))
            {
                cout << taskPosition + 1 << ": " << temporary << '\n';
                taskPosition++;
            }
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