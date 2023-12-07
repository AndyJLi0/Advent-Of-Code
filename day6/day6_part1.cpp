// SOLUTION: 781200
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

std::vector<int> race_time = {63,78,94,68};
std::vector<int> distance = {411,1274,2047,1035};

bool toyboat(int pressing_time, int total_time, int distance_to_beat) {
    int time_left = total_time - pressing_time;
    return time_left * pressing_time > distance_to_beat;
}

int main() {

    int prod = 1;
    // //parse input file
    // string currline;
    // ifstream myfile("day6data.txt");
    // if (myfile.is_open()) {
    //     while (getline(myfile, currline)) {
    //         lines.push_back(currline);
    //     }
    //     myfile.close();
    // }

    for (int i = 0; i < race_time.size(); i++) {
        int lower_bound = 0;
        int upper_bound = 0;
        for (int j = 0; j < race_time[i]; j++) {
            if (toyboat(j, race_time[i], distance[i])) {
                lower_bound = j;
                break;
            }
        }
        for (int k = lower_bound + 1; k < race_time[i]; k++) {
            //loops until the last one is found
            if (toyboat(k, race_time[i], distance[i])) {
                upper_bound = k;
            }
        }
        std::cout << "lower and upper: " << lower_bound << " " << upper_bound << std::endl;
        prod *= upper_bound - lower_bound + 1;
    }
    std::cout << prod << std::endl;
    return 0;
}
