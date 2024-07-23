#include <iostream>
#include <fstream>
#include <string>
//#include <sstream>

void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2)
{
    std::ifstream inputFile(filename.c_str()); // Convert std::string to const char* //Converts std::string to a C-style string (const char*), which is required by the ifstream constructor
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }
    std::ofstream outputFile((filename + ".replace").c_str()); // Convert std::string to const char*
    if (!outputFile.is_open())
    {
        std::cerr << "Error: Unable to create output file " << filename << ".replace" << std::endl;
        return;
    }
    std::string line;
    while (std::getline(inputFile, line))
    {
        std::string::size_type pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.replace(pos, s1.length(), s2);
            pos += s2.length();
        }
        outputFile << line << "\n";
    }
    inputFile.close();
    outputFile.close();
}

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
        return 1;
    }
    replaceInFile(argv[1], argv[2], argv[3]);
    return 0;
}