#include "HelperFunctions.h"
#include <stdexcept>
#include <regex>
#include <numeric>

void check_for_negatives(const std::vector<int> &numbers) {
    std::string negatives;
    for (int num : numbers) {
        if (num < 0) {
            negatives.append(std::to_string(num) + ",");
        }
    }

    if (!negatives.empty()) {
        throw std::invalid_argument("Negatives not allowed: " + negatives);
    }
}

void add_if_valid(std::vector<int> &numbers, std::string number_string) {
    int number = std::stoi(number_string);
    if (number <= 1000)
        numbers.push_back(number);
}

std::vector<int> get_numbers(const std::string &input) {
    std::regex numbers_only("(-?\\d+)+");

    std::vector<int> numbers;
    for (std::sregex_iterator it(input.begin(), input.end(), numbers_only); it != std::sregex_iterator(); ++it) {
        add_if_valid(numbers, it->str());
    }

    return numbers;
}
