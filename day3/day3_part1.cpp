#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool isAdjacent(const string &prevLine, const string &currline,
                const string &nextLine, int start, int end) {
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
            if (!isdigit(prevLine[i]) && prevLine[i] != '.') {
                return true;
            }
        }
    }

    // Check next line
    if (!nextLine.empty()) {
        for (int i = max(0, start);
             i <= min(static_cast<int>(nextLine.length()) - 1, end); ++i) {
            if (!isdigit(nextLine[i]) && nextLine[i] != '.') {
                return true;
            }
        }
    }

    if ((currline[start] != '.' && !isdigit(currline[start])) ||
        (currline[end] != '.' && !isdigit(currline[end]))) {
        return true;
    }

    return false;
}

int main() {
    int sum = 0;
    vector<string> lines;
    string currline;
    ofstream output;
    output.open("test.txt");
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
                number = 10 * number + currline[i] - '0';
            } else {
                if (number &&
                    isAdjacent(prevLine, currline, nextLine,
                               i - to_string(number).length(), i - 1)) {
                    output << number << endl;

                    sum += number;
                }
                number = 0;
            }
        }
        // number at the end of the line (spent 20 min on this edge case)
        if (number && isAdjacent(prevLine, currline, nextLine,
                                 currline.length() - to_string(number).length(),
                                 currline.length() - 1)) {
            sum += number;
        }
    }
    output.close();
    cout << sum << endl;
    return 0;
}
