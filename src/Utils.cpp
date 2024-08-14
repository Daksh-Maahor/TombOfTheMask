#include "../include/Include.hpp"

std::string& Utils::LoadFileAsString(std::string& path)
{
    std::string text;

    std::string temp;

    std::ifstream file(path);

    while (std::getline(file, temp))
    {
        text += temp + '\n';
    }

    file.close();

    return text;
}

int Utils::ParseInt(std::string num)
{
    std::stringstream stream(num);

    int x = 0;

    stream >> x;

    return x;
}
