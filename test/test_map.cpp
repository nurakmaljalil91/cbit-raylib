#include <iostream>
#include <map>
#include <string>

int main(int argc, char const *argv[])
{
    std::map<std::string, int> tests;

    tests.emplace("number 10", 10);

    std::cout << tests.find("number 10")->second; 
    return 0;
}
