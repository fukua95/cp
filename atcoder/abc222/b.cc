#include <iostream>

int main() {
    int n, p, a;
    int ans = 0;
    std::cin >> n >> p;
    for (int i = 0; i < n; ++i) {
        std::cin >> a;
        if (a < p) ++ans;
    }
    std::cout << ans << std::endl;
    return 0;
}