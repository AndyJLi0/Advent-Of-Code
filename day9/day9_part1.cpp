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
int extrapolate(vector<int> line, int n) {
    int ret = 0;
    for (int i = n; i < line.size(); i++) {
        ret += line[i];
    }
    return ret;
}

int extrapolate_line(string line) {
    cout << line << endl;
    vector<int> parsed_line = parse_line(line);
    int n = parsed_line.size();
    while (!zeros_up_to_n(parsed_line, n)) {
        for (int i = 0; i < n - 1; i++) {
            parsed_line[i] = parsed_line[i + 1] - parsed_line[i];
            cout << parsed_line[i] << " ";
        }
        n--;
        cout << endl;
    }
    return extrapolate(parsed_line, n);
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
