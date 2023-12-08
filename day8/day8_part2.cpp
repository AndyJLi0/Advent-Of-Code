// SOLUTION: 9858474970153
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
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

void increment_step(vector<string> &nodes, char direction) {
    for (int i = 0; i < nodes.size(); i++) {
        if (direction == 'L') {
            nodes[i] = dict[nodes[i]].first;
        } else {
            nodes[i] = dict[nodes[i]].second;
        }
    }
}
int gcd(long a, long b) {
    while (true) {
        if (a == 0)
            return b;
        b %= a;
        if (b == 0)
            return a;
        a %= b;
    }
}

long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

long long find_lcm(vector<long> &steps_taken) {
    long long lcm_result = steps_taken[0];
    for (size_t i = 1; i < steps_taken.size(); ++i) {
        lcm_result = lcm(lcm_result, steps_taken[i]);
    }
    return lcm_result;
}

long count_steps() {
    int index = 0;
    vector<string> nodes;

    for (auto k_v : dict) {
        if (k_v.first[2] == 'A') {
            // cout << k_v.first << endl;
            nodes.push_back(k_v.first);
        }
    }

    vector<long> steps_taken(nodes.size(), 0);
    for (int i = 0; i < nodes.size(); i++) {
        while (nodes[i][2] != 'Z') {
            if (index >= instruction.size()) {
                index = 0;
            }
            if (instruction[index] == 'L') {
                nodes[i] = dict[nodes[i]].first;
            } else {
                nodes[i] = dict[nodes[i]].second;
            }
            steps_taken[i]++;
            index++;
        }
        index = 0;
    }
    return find_lcm(steps_taken);
}

int main() {

    save_input();

    parse_lines(lines);
    long long steps = count_steps();

    cout << steps << endl;
    return 0;
}
