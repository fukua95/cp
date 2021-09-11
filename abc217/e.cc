#include <iostream>
#include <set>
#include <queue>

int main() {
    std::multiset<int> sort;
    std::queue<int> origin;
    int q;
    std::cin >> q;
    while (q--) {
        int t, v;
        std::cin >> t;
        if (t == 1) {
            std::cin >> v;
            origin.push(v);
        } else if (t == 2) {
            if (!sort.empty()) {
                v = *sort.begin();
                sort.erase(sort.begin());
            } else {
                v = origin.front();
                origin.pop();
            }
            std::cout << v << std::endl;
        } else {
            while (!origin.empty()) {
                sort.insert(origin.front());
                origin.pop();
            }
        }
    }
    return 0;
}