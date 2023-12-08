// SOLUTION: 11567
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

string instruction;
vector<string> lines;
map<string, pair<string, string>> dict;

void save_input() {
    string currline;
    ifstream myfile("day8data.txt");
    if (myfile.is_open()) {
        getline(myfile, instruction);
        while (getline(myfile, currline)) {
            if (currline.size() > 0) {
                lines.push_back(currline);
            }
        }
        myfile.close();
    }
}

void parse_lines(vector<string> input) {
    for (const auto &currline : input) {
        string label = currline.substr(0, 3);
        string left = currline.substr(7, 3);
        string right = currline.substr(12, 3);
        dict[label] = {left, right};
    }
}

int count_steps() {
    int steps = 0;
    int index = 0;
    string curr = "AAA";
    while (curr != "ZZZ") {
        if (index >= instruction.size()) {
            index = 0;
        }
        if (instruction[index] == 'L') {
            curr = dict[curr].first;
        } else {
            curr = dict[curr].second;
        }

        steps++;
        index++;
    }
    return steps;
}

int main() {

    int sum = 0;

    save_input();

    parse_lines(lines);
    int steps = count_steps();
    cout << steps << endl;
    return 0;
}
