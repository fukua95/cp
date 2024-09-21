#include <iostream>

int main() {
    int n;
    std::cin >> n;
    std::string s = "0000";
    s[0] = (n / 1000) + '0';
    s[1] = (n / 100) % 10 + '0';
    s[2] = (n / 10) % 10 + '0';
    s[3] = n % 10 + '0';
    std::cout << s << std::endl;
    return 0;
}