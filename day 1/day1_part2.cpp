// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    std::map<string, int> dict;
    dict["one"] = 1;
    dict["two"] = 2;
    dict["three"] = 3;
    dict["four"] = 4;
    dict["five"] = 5;
    dict["six"] = 6;
    dict["seven"] = 7;
    dict["eight"] = 8;
    dict["nine"] = 9;

    long long sum = 0;
    string line;
    ifstream myfile("day1data.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            std::map<int, int, less<int>> numbers;

            for (auto word : dict)
            {
                if (line.find(word.first) != std::string::npos)
                {
                    numbers.insert({line.find(word.first), word.second});
                }
                if (line.rfind(word.first) != std::string::npos)
                {
                    numbers.insert({line.rfind(word.first), word.second});
                }
            }
            for (int i = 0; i < line.length(); i++)
            {
                if (isdigit(line[i]))
                {
                    numbers.insert({i, line[i] - '0'});
                }
            }
            //cout << numbers.begin()->second << " " << numbers.rbegin()->second << endl;
            int value = 10 * numbers.begin()->second + numbers.rbegin()->second;
            sum += value;
        }
        myfile.close();
    }
    cout << sum << endl;
    return 0;
}

// answer is 53312