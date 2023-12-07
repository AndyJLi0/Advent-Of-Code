// SOLUTION: 79842967
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<string> lines;
map<pair<int, int>, vector<int>> gears;
void markGears(int prev, int curr, int next, int start, int end, int number) {
    string prevLine = "";
    string currline = lines[curr];
    string nextLine = "";
    if (prev > 0) {
        prevLine = lines[prev];
    }
    if (next < lines.size()) {
        nextLine = lines[next];
    }
    // Boundary checks for start and end
    if (start > 0) {
        start--;
    }
    if (end < currline.length() - 1) {
        end++;
    }

    // Check previous line
    if (!prevLine.empty()) {
        for (int i = max(0, start);
             i <= min(static_cast<int>(prevLine.length()) - 1, end); ++i) {
            if (prevLine[i] == '*') {
                gears[{prev, i}].push_back(number);
            }
        }
    }

    // Check next line
    if (!nextLine.empty()) {
        for (int i = max(0, start);
             i <= min(static_cast<int>(nextLine.length()) - 1, end); ++i) {
            if (nextLine[i] == '*') {
                gears[{next, i}].push_back(number);
            }
        }
    }

    if (currline[start] == '*') {
        gears[{curr, start}].push_back(number);
    }
    if (currline[end] == '*') {
        gears[{curr, end}].push_back(number);
    }
}

int main() {

    int sum = 0;
    string currline;
    ifstream myfile("day3data.txt");
    if (myfile.is_open()) {
        while (getline(myfile, currline)) {
            lines.push_back(currline);
        }
        myfile.close();
    }
    cout << lines.size() << endl;
    for (int j = 0; j < lines.size(); ++j) {
        currline = lines[j];
        string prevLine = j > 0 ? lines[j - 1] : "";
        string nextLine = j < lines.size() - 1 ? lines[j + 1] : "";

        int number = 0;
        for (int i = 0; i < currline.length(); ++i) {
            if (isdigit(currline[i])) {
                number = 10 * number + (currline[i] - '0');
                
            } else if (number) {
                cout << "bruh" << endl;

                markGears(j - 1, j, j + 1, i - to_string(number).length(),
                          i - 1, number);
                number = 0;
            }
        }
        // number at the end of the line (spent 20 min on this edge case)
        if (number) {
            markGears(j - 1, j, j + 1,
                      currline.length() - to_string(number).length(),
                      currline.length() - 1, number);
        }
    }
    for (auto gear : gears) {
        if (gear.second.size() == 2) {
            sum += gear.second[0] * gear.second[1];
        }
    }
    cout << sum << endl;
    return 0;
}
