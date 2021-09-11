#include <iostream>
#include <string>
#include <map>

int main() {
    std::map<std::string, bool> has;
    has["ABC"] = false;
    has["ARC"] = false;
    has["AGC"] = false;
    has["AHC"] = false;

    for (int i = 0; i < 3; ++i) {
        std::string s;
        std::cin >> s;
        has[s] = true;
    }
    for (const auto& [k, v] : has) {
        if (!v) {
            std::cout << k << std::endl;
        }
    }
    return 0;
}