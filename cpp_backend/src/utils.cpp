<<<<<<< HEAD
//aditya
=======
>>>>>>> 8f69d574989c9145fa4148e07e5c9db282076853
#include "utils.hpp"

string Utils::toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

void Utils::printDivider() {
    cout << "----------------------------------------\n";
}