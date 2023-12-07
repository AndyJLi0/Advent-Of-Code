// SOLUTION: 25183
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
vector<string> lines;
int main() {

    int sum = 0;
    string currline;
    ifstream myfile("day4data.txt");
    if (myfile.is_open()) {
        while (getline(myfile, currline)) {
            lines.push_back(currline);
        }
        myfile.close();
    }
    cout << lines.size() << endl;
    for (int j = 0; j < lines.size(); ++j) {

        currline = lines[j];
        vector<int> winners;
        int points = 0;
        int number = 0;
        int i = 0;
        while (currline[i] != ':') {
            i++;
        }
        while (i < currline.length()) {
            if (isdigit(currline[i])) {
                number = 10 * number + (currline[i] - '0');

            } else if (number) {
                winners.push_back(number);
                number = 0;
            } else if (currline[i] == '|') {
                break;
            }
            i++;
        }

        while (i < currline.length()) {
            if (isdigit(currline[i])) {
                number = 10 * number + (currline[i] - '0');
            } else if (number) {
                if (find(winners.begin(), winners.end(), number) !=
                    winners.end()) {
                    points = points ? points * 2 : 1;
                }
                number = 0;
            }
            i++;
        }
        // number at the end of the line (spent 20 min on this edge case)
        if (number) {
            if (find(winners.begin(), winners.end(), number) != winners.end()) {
                points = points ? points * 2 : 1;
            }
        }
        sum += points;
    }
    cout << sum << endl;
    return 0;
}
