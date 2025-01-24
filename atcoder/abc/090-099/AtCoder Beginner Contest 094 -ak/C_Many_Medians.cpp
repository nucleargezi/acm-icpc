#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    int k = n - 1 >> 1;
    vector<int> v(n);
    std::cin >> v;
    multiset<int> a, b;
    meion balance = [&]() -> void {
        while (a.size() > k) {
            b.emplace(*a.rbegin());
            a.extract(*a.rbegin());
        }
        while (a.size() and b.size() and *a.rbegin() > *b.begin()) {
            int x = *a.rbegin(), y = *b.begin();
            a.extract(x), b.extract(y);
            a.emplace(y), b.emplace(x);
        }
    };
    for (int x : v) {
        a.emplace(x);
    }
    for (int x : v) {
        (a.contains(x) ? a : b).extract(x);
        balance();
        std::cout << *b.begin() << '\n';
        a.emplace(x);
    }
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}