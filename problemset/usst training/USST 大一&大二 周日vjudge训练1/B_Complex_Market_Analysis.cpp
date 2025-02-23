#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/prims_test.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n, e;
    std::cin >> n >> e;
    vector<int> a(n);
    std::cin >> a;
    vector<vector<int>> v(n);
    for (int i{}; i < n; ++i) {
        if (a[i] == 1) {
            v[i % e].emplace_back(i);
        }
    }
    vector<int> L(n), R(n);
    for (meion &s : v) {
        int sz = (int)s.size();
        for (int i{}; i < sz; ++i) {
            L[s[i]] = 1;
            if (i and s[i - 1] + e == s[i]) {
                L[s[i]] += L[s[i - 1]];
            }
        }
        for (int i{sz}; i--; ) {
            R[s[i]] = 1;
            if (i != sz - 1 and s[i] + e == s[i + 1]) {
                R[s[i]] += R[s[i + 1]];
            }
        }
    }
    ll ans{};
    for (int i{}; i < n; ++i) {
        int x = a[i];
        if (not primetest(x)) continue;
        if (i < e and i + e > n - 1) continue;
        if (i < e) ans += R[i + e];
        else if (i + e > n - 1) ans += L[i - e];
        else ans += (L[i - e] + 1ll) * (R[i + e] + 1ll) - 1;
    }
    std::cout << ans << '\n';
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