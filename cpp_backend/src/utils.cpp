#include "utils.hpp"

string Utils::toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}


void Utils::printDivider() {
    cout << "----------------------------------------\n";
}