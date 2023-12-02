// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    long long sum = 0;
    string line;
    ifstream myfile("day1data.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            std::vector<int> numbers;
            for (int i = 0; i < line.length(); i++)
            {
                if (isdigit(line[i]))
                {
                    numbers.push_back(line[i] - '0');
                }
            }
            int value = 10 * numbers.front() + numbers.back();
            sum += value;
        }
        myfile.close();
    }
    cout << sum << endl;
    return 0;
}

// answer is 53386