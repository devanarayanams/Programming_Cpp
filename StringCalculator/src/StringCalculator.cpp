#include "StringCalculator.h"
#include "HelperFunctions.h"
#include <algorithm>
#include <numeric>

int StringCalculator::add(std::string input) {
    if (input.empty())
        return 0;

    std::vector<int> numbers = get_numbers(input);

    check_for_negatives(numbers);

    return std::accumulate(numbers.begin(), numbers.end(), 0);

}
