#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> q(n);
    for (int i = 0, p; i < n; ++i) {
        std::cin >> p;
        q[p - 1] = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        std::cout << q[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}