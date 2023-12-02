#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>


using namespace std;
std::map<char, int> dict{
    {'r', 12}, {'g', 13}, {'b', 14}};

std::pair<int, int> get_game_id(string line)
{
    int index = 0;
    int game_id = 0;
    while (line[index] != ':')
    {
        if (isdigit(line[index]))
        {
            game_id = 10 * game_id + (line[index] - '0');
        }
        index++;
    }
    return {game_id, index};
}

int main()
{
    int sum = 0;
    string line;
    ifstream myfile("day2data.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            std::pair<int, int> id_index = get_game_id(line);
            int game_id = id_index.first;
            int index = id_index.second;

            while (index < line.length())
            {
                int number = 0;
                char color;
                if (isdigit(line[index]) && !isdigit(line[index + 1]))
                {
                    number = line[index] - '0';
                    color = line[index + 2];
                    if (number > dict[color])
                    {
                        break;
                    }
                    index += 3;
                }
                else if (isdigit(line[index]) && isdigit(line[index + 1]))
                {
                    number = 10 * (line[index] - '0') + (line[index + 1] - '0');
                    color = line[index + 3];
                    if (number > dict[color])
                    {
                        break;
                    }
                    index += 4;
                }
                else
                {
                    index++;
                }
            }
            if (index == line.length())
            {
                sum += game_id;
            }
        }
        myfile.close();
    }
    cout << sum << endl;
    return 0;
}