#include <iostream>
#include <string>

int main() {
    std::string s, t;
    std::cin >> s >> t;
    if (s < t) std::cout << "Yes" << std::endl;
    else std::cout << "No" << std::endl;
    return 0;
}