#include <iostream>
#include <vector>

const int P = 998244353;

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }
    
    std::vector<std::vector<int>> f(n, std::vector<int>(3001, 0));
    f[0][a[0]] = 1;
    for (int i = a[0] + 1; i <= 3000; ++i) {
        f[0][i] = f[0][i - 1] + (i <= b[0]);
    }
    for (int i = 1; i < n; ++i) {
        f[i][a[i]] = f[i - 1][a[i]];
        for (int j = a[i] + 1; j <= 3000; ++j) {
            if (j <= b[i]) {
                f[i][j] = ((int64_t)f[i][j - 1] + f[i - 1][j]) % P;
            } else {
                f[i][j] = f[i][j - 1];
            }
        }
    }

    std::cout << f[n - 1][b[n - 1]] << std::endl;
    return 0;
}