#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, k;
    std::cin >> n >> k;
    vector<int> a(n);
    std::cin >> a;
    ll s{qsum(a, 0ll)};
    vector<ll> factor;
    for (ll i{1}; i * i < s + 1; ++i) {
        if (s % i) continue;
        factor.emplace_back(i);
        factor.emplace_back(s / i);
    }
    unique(factor);
    reverse(factor);
    for (ll e : factor) {
        ll res{};
        vector<ll> v;
        for (int i{}; i < n; ++i) {
            v.emplace_back(a[i] % e);
        }
        sort(v);
        vector<ll> L{{}}, R{{}};
        for (int i{}; i < n; ++i) {
            L.emplace_back(L.back() + v[i]);
            R.emplace_back(R.back() + e - v[n - i - 1]);
        }
        reverse(R);
        for (int i{}; i < n + 1; ++i) {
            if (MAX(L[i], R[i]) < k + 1) {
                iroha std::cout << e << '\n', void();
            }
        }
    }
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