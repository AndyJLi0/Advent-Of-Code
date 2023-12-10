// SOLUTION: 6786
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
    ifstream myfile("day10data.txt");
    if (myfile.is_open()) {
        while (getline(myfile, currline)) {
            lines.push_back(currline);
        }
        myfile.close();
    }
}
pair<int, int> find_s() {
    for (int i = 0; i < lines.size(); i++) {
        for (int j = 0; j < lines[i].size(); j++) {
            if (lines[i][j] == 'S') {
                return {i, j};
                //     row, column
            }
        }
    }
}

int follow_path(int row, int col) {
    int step = 2;
    pair<int, int> previous = {row, col-1};

    while (lines[row][col] != 'S') {
        //cout << lines[row][col] << endl;
        if (lines[row][col] == '|') {
            if (previous.first - row == 1) {
                // up
                previous = {row, col};
                row--;
            } else if (previous.first - row == -1) {
                // down
                previous = {row, col};
                row++;
            }
        } else if (lines[row][col] == '-') {
            if (previous.second - col == 1) {
                // left
                previous = {row, col};
                col--;
            } else if (previous.second - col == -1) {
                // right
                previous = {row, col};
                col++;
            }
        } else if (lines[row][col] == 'J') {
            if (previous.first - row == 0) {
                // right, so we go up
                previous = {row, col};
                row--;
            } else if (previous.second - col == 0) {
                // down, so we go left
                previous = {row, col};
                col--;
            }
        } else if (lines[row][col] == 'F') {
            if (previous.first - row == 0) {
                // went left, so we go down
                previous = {row, col};
                row++;
            } else if (previous.second - col == 0) {
                // same column, went up, so we go right
                previous = {row, col};
                col++;
            }
        } else if (lines[row][col] == 'L') {
            if (previous.first - row == 0) {
                // went left, so we go up
                previous = {row, col};
                row--;
            } else if (previous.second - col == 0) {
                // same column, went down, so we go right
                previous = {row, col};
                col++;
            }
        } else if (lines[row][col] == '7') {
            if (previous.first - row == 0) {
                // went right, so we go down
                previous = {row, col};
                row++;
            } else if (previous.second - col == 0) {
                // same column, went up, so we go left
                previous = {row, col};
                col--;
            }
        }
        step++;
    }
    return step / 2;
}

int main() {

    save_input();
    pair<int, int> start = find_s();
    // loop around including the start, divide by 2
    int answer = follow_path(start.first + 1, start.second + 1);
    // start.first +1, start.second +1
    cout << answer << endl;
    return 0;
}
