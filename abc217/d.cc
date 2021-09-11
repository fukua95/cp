#include <iostream>
#include <algorithm>
#include <set>

int main() {
    int l, q;
    std::cin >> l >> q;
    std::set<int> points;
    points.insert(0);
    points.insert(l);
    for (int i = 0; i < q; ++i) {
        int t, x;
        std::cin >> t >> x;
        if (t == 1) {
            points.insert(x);
        } else {
            auto r = points.lower_bound(x);
            auto l = r;
            --l;
            std::cout << *r - *l << std::endl;
        }
    }
    return 0;
}