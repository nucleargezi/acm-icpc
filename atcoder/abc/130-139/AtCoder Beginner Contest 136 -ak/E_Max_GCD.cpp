#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, k;
    std::cin >> n >> k;
    vector<ll> a(n);
    std::cin >> a;
    ll s{qsum(a, 0ll)};
    vector<int> v;
    for (int i{1}; i * i < s + 1; ++i) {
        if (s % i) continue;
        v.emplace_back(i);
        v.emplace_back(s / i);
    }
    unique(v);
    rev(v);
    for (meion e : v) {
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
        rev(R);
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
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}