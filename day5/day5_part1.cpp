#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<string> lines;
vector<long long> seeds;
string currline;
vector<vector<long long>> seed_to_soil;
vector<vector<long long>> soil_to_fertilizer;
vector<vector<long long>> fertilizer_to_water;
vector<vector<long long>> water_to_light;
vector<vector<long long>> light_to_temperature;
vector<vector<long long>> temperature_to_humidity;
vector<vector<long long>> humidity_to_location;

int main() {

    int sum = 0;

    ifstream myfile("day5data.txt");

    if (myfile.is_open()) {
        while (getline(myfile, currline)) {
            lines.push_back(currline);
        }
        myfile.close();
    }

    long long seed = 0;
    for (int i = 0; i < lines[0].size(); i++) {
        if (isdigit(lines[0][i])) {
            seed = 10 * seed + (lines[0][i] - '0');
            // edge case
            if (i = lines[0].size() - 1) {
                seeds.push_back(seed);
            }
        } else if (seed) {
            seeds.push_back(seed);
            seed = 0;
        }
    }

    int index = 3;
    long long mapping = 0;
    
    while (!lines[index].empty()) {
        currline = lines[index];
        for (int i = 0; i < currline.size(); i++) {
            if (isdigit(currline[i])) {
                mapping = 10 * mapping + (currline[i] - '0');
                if (i = currline.size() - 1) {
                    seed_to_soil.push_back(mapping);
                    mapping = 0;
                }
            } else if (mapping) {
                seed_to_soil.push_back(mapping);
                mapping = 0;
            }
        }
        if (currline[])
        seed = 10 * seed + (lines[0][i] - '0');
        index++;
    }

    //     currline = lines[j];

    //     // number at the end of the line (spent 20 min on this edge case)
    //     if (number) {
    //         if (find(winners.begin(), winners.end(), number) !=
    //         winners.end()) {
    //             points = points ? points * 2 : 1;
    //         }
    //     }
    //     sum += points
    // cout << sum << endl;
    return 0;
}
