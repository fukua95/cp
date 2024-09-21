#include <iostream>
#include <string>

std::string prev(int n) {
    std::string res = "";
    for (int i = 0; i < n; ++i) {
        res += "(";
    }
    for (int i = 0; i < n; ++i) {
        res += ")";
    }
    return res;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        for (int i = 0; i < n; ++i) {
            std::cout << prev(n - i);
            for (int j = 1; j <= i; ++j) {
                std::cout << "()";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}
