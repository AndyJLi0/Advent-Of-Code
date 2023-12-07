// SOLUTION: 5667240
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
    //cout << lines.size() << endl;
    vector<int> copies(lines.size(), 1);

    for (int j = 0; j < lines.size(); ++j) {

        currline = lines[j];
        vector<int> winners;
        int num_of_winners = 0;
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
                    num_of_winners++;
                }
                number = 0;
            }
            i++;
        }
        // number at the end of the line
        if (number) {
            if (find(winners.begin(), winners.end(), number) != winners.end()) {
                num_of_winners++;
            }
        }
        int adding_factor = copies[j];
        for (int k = 1; k < num_of_winners + 1; ++k) {
            if (j + k < lines.size()) {
                copies[j + k] += adding_factor;
            }
        }
    }

    for (int i = 0; i < copies.size(); ++i) {
        //cout << copies[i] << endl;
        sum += copies[i];
    }
    cout << sum << endl;
    return 0;
}
