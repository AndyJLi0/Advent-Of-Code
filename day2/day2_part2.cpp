#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main()
{
    int sum = 0;
    string line;
    ifstream myfile("day2data.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            std::map<char, int> dict{
                {'r', 0}, {'g', 0}, {'b', 0}};
            int index = 0;
            while (line[index] != ':')
            {
                index++;
            }

            // index is past game id

            while (index < line.length())
            {
                int number = 0;
                char color;
                if (isdigit(line[index]) && !isdigit(line[index + 1]))
                {
                    number = line[index] - '0';
                    color = line[index + 2];
                    dict[color] = max(dict[color], number);
                    index += 3;
                }
                else if (isdigit(line[index]) && isdigit(line[index + 1]))
                {
                    number = 10 * (line[index] - '0') + (line[index + 1] - '0');
                    color = line[index + 3];
                    dict[color] = max(dict[color], number);
                    index += 4;
                }
                else
                {
                    index++;
                }
            }
            sum += dict['r'] * dict['g'] * dict['b'];
        }
        myfile.close();
    }
    cout << sum << endl;
    return 0;
}

// answer is 86036