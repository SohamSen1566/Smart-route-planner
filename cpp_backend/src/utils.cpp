<<<<<<< HEAD
//aditya
=======
>>>>>>> 8f69d57 (added utils.cpp and utils.hpp files with utility functions)
#include "utils.hpp"

string Utils::toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

void Utils::printDivider() {
    cout << "----------------------------------------\n";
}