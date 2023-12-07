// SOLUTION: 49240091
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

std::vector<long long> race_time = {63789468};
std::vector<long long> distance = {411127420471035};

bool toyboat(long long pressing_time, long long total_time, long long distance_to_beat) {
    long time_left = total_time - pressing_time;
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
        for (long long j = 0; j < race_time[i]; j++) {
            if (toyboat(j, race_time[i], distance[i])) {
                lower_bound = j;
                break;
            }
        }
        for (long long k = race_time[i]; k > lower_bound; k--) {
            if (toyboat(k, race_time[i], distance[i])) {
                upper_bound = k;
                break;
            }
        }
        std::cout << "lower and upper: " << lower_bound << " " << upper_bound
                  << std::endl;
        prod *= upper_bound - lower_bound + 1;
    }
    std::cout << prod << std::endl;
    return 0;
}
