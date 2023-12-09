// SOLUTION: 11567
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

vector<string> lines;

void save_input() {
    string currline;
    ifstream myfile("day9data.txt");
    if (myfile.is_open()) {
        while (getline(myfile, currline)) {
            lines.push_back(currline);
        }
        myfile.close();
    }
}

vector<int> parse_line(string &line) {
    vector<int> values;
    stringstream stream(line);
    int n;
    while (stream >> n) {
        values.push_back(n);
    }
    return values;
}
bool zeros_up_to_n(vector<int> line, int n) {
    for (int i = 0; i < n; i++) {
        if (line[i] != 0) {
            return false;
        }
    }
    return true;
}
int extrapolate_part2(vector<int> line) {
    // upper minus lower
    int ret = 0;
    for (int i = line.size() - 2; i >= 0; i--) {
        ret = line[i] - ret;
    }
    cout << ret << endl;
    return ret;
}

int extrapolate_line(string line) {
    vector<int> parsed_line = parse_line(line);
    vector<int> index_zero = {parsed_line[0]};
    int n = parsed_line.size();

    while (!zeros_up_to_n(parsed_line, n)) {
        for (int i = 0; i < n - 1; i++) {
            parsed_line[i] = parsed_line[i + 1] - parsed_line[i];
        }
        index_zero.push_back(parsed_line[0]);
        n--;
    }
    for (int i = 0; i < index_zero.size(); i++) {
        cout << index_zero[i] << " ";
    }
    cout << endl;
    return extrapolate_part2(index_zero);
}

long extrapolate_all() {
    long sum = 0;
    for (int i = 0; i < lines.size(); i++) {
        sum += extrapolate_line(lines[i]);
    }
    return sum;
}

int main() {

    long sum = 0;

    save_input();

    sum = extrapolate_all();
    cout << sum << endl;
    return 0;
}
