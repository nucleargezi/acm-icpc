#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, k;
    std::cin >> n >> k;
    if (n == 1) {
        std::cout << (k ? "-1" : "0 0 1 1") << '\n';
    } else {
        if (k + 1 > (1 << n)) {
            std::cout << "-1\n";
        } else {
            vector<int> v(1 << n);
            std::iota(v.begin(), v.end(), 0);
            v.erase(v.begin() + k);
            meion vv(v);
            v.emplace_back(k);
            v.insert(v.end(), vv.rbegin(), vv.rend());
            v.emplace_back(k);
            std::cout << v << '\n';
        }
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