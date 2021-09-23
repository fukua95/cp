#include <iostream>
#include <set>
#include <vector>
#include <stdio.h>

int main() {
    int n;
    std::cin >> n;
    std::multiset<int64_t> heroes;
    int64_t sum = 0;
    for (int i = 0; i < n; ++i) {
        int64_t a;
        scanf("%lld", &a);
        sum += a;
        heroes.insert(a);
    }

    int q;
    int64_t defense, attack, ans;
    std::cin >> q;
    while (q--) {
        std::cin >> defense >> attack;
        ans = (int64_t)1e18 + (int64_t)1e13 + 1;
        auto iter = heroes.lower_bound(defense);
        if (iter != heroes.end()) {
            ans = sum - *iter >= attack ? 0 : attack - sum + *iter;
        }
        if (iter != heroes.begin()) {
            --iter;
            int64_t cur = (defense - *iter) + (sum - *iter >= attack ? 0: attack - sum + *iter);
            if (cur < ans) {
                ans = cur;
            }
        }
        // std::cout << ans << std::endl;
        printf("%lld\n", ans);
    }
    return 0;
}