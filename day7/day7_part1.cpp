// its bid multiplied by its rank
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

vector<string> lines;
vector<pair<string, int>> hands;
map<char, int> value = {{'A', 14}, {'K', 13}, {'Q', 12}, {'J', 11}, {'T', 10},
                        {'9', 9},  {'8', 8},  {'7', 7},  {'6', 6},  {'5', 5},
                        {'4', 4},  {'3', 3},  {'2', 2}};

void parse_lines(vector<string> input) {
    for (const auto& currline : input) {
        size_t spacePos = currline.find(" ");
        string cards = currline.substr(0, spacePos);
        int bid = stoi(currline.substr(spacePos + 1));
        hands.push_back(make_pair(cards, bid));
        cout << cards << " " << bid << endl;
    }
}

pair<int, int> repeated_chars(string input) {
    map<char, int> char_count;
    for (int i = 0; i < input.size(); i++) {
        char_count[input[i]]++;
    }
    int max = 0;
    int second_max = 0;
    for (auto it = char_count.begin(); it != char_count.end(); it++) {
        if (it->second > max) {
            second_max = max;
            max = it->second;
        } else if (it->second > second_max && it->second <= max) {
            second_max = it->second;
        }
    }
    return {max, second_max};
}
bool cmp(const pair<string, int> &a, const pair<string, int> &b) {
    auto a_chars = repeated_chars(a.first);
    auto b_chars = repeated_chars(b.first);

    // First, compare based on the type of hand (most frequent character count)
    if (a_chars.first != b_chars.first) {
        return a_chars.first < b_chars.first;
    }

    // If tied, compare based on the second most frequent character count
    if (a_chars.first == b_chars.first && a_chars.first == 3) {
        //is a full house?
        if (a_chars.second != b_chars.second) {
            return a_chars.second < b_chars.second;
        }
    }
    if (a_chars.first == b_chars.first && a_chars.first == 2) {
        //is a two pair?
        if (a_chars.second != b_chars.second) {
            return a_chars.second < b_chars.second;
        }
    }

    // If still tied, compare based on individual card values
    for (int i = 0; i < a.first.size(); i++) {
        if (value.at(a.first[i]) != value.at(b.first[i])) {
            return value.at(a.first[i]) < value.at(b.first[i]);
        }
    }
    return false; // If all cards are equal, consider them equal
}

int main() {

    int sum = 0;
    // parse input file
    string currline;
    ifstream myfile("day7data.txt");
    if (myfile.is_open()) {
        while (getline(myfile, currline)) {
            lines.push_back(currline);
        }
        myfile.close();
    }

    parse_lines(lines);
    sort(hands.begin(), hands.end(), cmp);
    for (int i = 0; i < hands.size(); i++) {
        sum += hands[i].second * (i + 1);
    }
    cout << sum << endl;
    return 0;
}
