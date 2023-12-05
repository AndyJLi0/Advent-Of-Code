#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <climits>

// Function to split a string by a delimiter and return a vector of strings
std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Function to process each map and transform the value
long long lookup(long long val, const std::string& m) {
    auto lines = split(m, '\n');
    for (size_t i = 1; i < lines.size(); ++i) {
        auto parts = split(lines[i], ' ');
        long long dst = std::stoll(parts[0]);
        long long src = std::stoll(parts[1]);
        long long n = std::stoll(parts[2]);

        if (src <= val && val < src + n) {
            return val - src + dst;
        }
    }
    return val;
}

int main() {
    std::ifstream file("day5data.txt");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    auto sections = split(content, '\n\n');
    auto seeds = split(sections[0], ' ');

    std::vector<long long> seedValues;
    std::transform(seeds.begin() + 1, seeds.end(), std::back_inserter(seedValues),
                   [](const std::string& s) { return std::stoll(s); });

    long long minValue = LLONG_MAX;
    for (auto seed : seedValues) {
        long long value = seed;
        for (size_t i = 1; i < sections.size(); ++i) {
            value = lookup(value, sections[i]);
        }
        minValue = std::min(minValue, value);
    }

    std::cout << minValue << std::endl;

    return 0;
}
