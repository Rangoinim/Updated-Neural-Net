#include "openfile.h"

bool dumpToArray(string file, vector<float>* contents)
{
    bool success;
    string line;
    int count = 0;
    ifstream inFile;
    inFile.open(file);
    if (inFile.is_open() && inFile.peek() != ifstream::traits_type::eof())
    {
        while (getline(inFile, line))
        {
            int location = line.find("=");
            std::string strright = line.substr(location+1);
            contents->push_back(stof(strright));
            count++;
        }
        inFile.close();
        success = true;
    }
    else if (inFile.is_open() && inFile.peek() == ifstream::traits_type::eof())
    {
        inFile.close();
        success = false;
    }
    else
    {
        inFile.close();
        success = false;
    }
    return success;
}