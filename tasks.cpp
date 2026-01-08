#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include <vector>
#include <string>
using std::string, std::cin, std::cout;

int main(int argc, const char* argv[])
{
    if (argc > 2) {
        string action{string(argv[1])};
        std::vector<string> content;
        const char* home{std::getenv("HOME")};
        string path;
        if (!home) {
            home = std::getenv("USERPROFILE");
            path = string(home) + "/tasks.txt";
        }

        if (home) {
            path = string(home) + "/tasks.txt";
        } else {
            cout << "ERROR!";
            return 1;
        }

        std::fstream file;
        if (std::filesystem::exists(path)) {
            file.open(path, std::ios::in | std::ios::app);
        } else {
            file.open(path, std::ios::in | std::ios::out | std::ios::app);
        }

        if (action == "add") {
            string task = string(argv[2]);
            file << task <<'\n';
        } else if (action == "remove") {
            string temporary;
            while(std::getline(file, temporary)) {
                content.push_back(temporary);
            }
            int taskPosition{std::stoi(string(argv[2]))};
            content.erase(content.begin()+taskPosition);
            file.close();
            std::fstream file(path, std::ios::out);
        }
    }
}