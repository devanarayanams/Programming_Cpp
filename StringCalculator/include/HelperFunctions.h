#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include <vector>
#include <string>

void check_for_negatives(const std::vector<int> &numbers);
void add_if_valid(std::vector<int> &numbers, std::string number_string);
std::vector<int> get_numbers(const std::string &input);

#endif // HELPERFUNCTIONS_H
