#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    ll L;
    std::cin >> n >> L;
    vector<ll> a(n);
    std::cin >> a;
    a = pre_sum(a);
    int idx{-1}, max{-1};
    bool f(false);
    for (int i{2}; i < n + 1; ++i) {
        if (a[i] - a[i - 2] > L - 1) f = true;
        if (chmax(max, a[i] - a[i - 2])) {
            idx = i;
        }
    }
    if (not f) iroha Impossible();
    Possible();
    for (int i{1}; i < idx - 1; ++i) {
        std::cout << i << '\n';
    }
    for (int i{n - 1}; i > idx - 1; ) {
        std::cout << i-- << '\n';
    }
    std::cout << idx - 1 << '\n';
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // std::ifstream in("in"); std::cin.rdbuf(in.rdbuf());
    // std::ofstream ou("out"); std::cout.rdbuf(ou.rdbuf());
    before();
#ifdef tests
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}