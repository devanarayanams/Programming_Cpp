#include "NegativesChecker.h"

void GetNegatives::operator()(int i) {
    if (i < 0)
        negatives.append(std::to_string(i) + ",");
}

GetNegatives::operator std::string() {
    if (negatives.length() > 0)
        negatives.pop_back();

    return negatives;
}
