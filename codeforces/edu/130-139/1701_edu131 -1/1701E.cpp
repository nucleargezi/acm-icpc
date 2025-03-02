#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/string/hash.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    string s, t;
    std::cin >> s >> t;
    HASH hs(s), ht(t);
    vector<int> L(n), R(n);
    for (int i{}, k{}; i < n; ++i) {
        if (k < m and s[i] == t[k]) ++k;
        L[i] = k;
    }
    L.insert(L.begin(), 0);
    for (int i{n}, k{m - 1}; i--; ) {
        if (k > -1 and s[i] == t[k]) --k;
        R[i] = m - k - 1;
    }
    R.insert(R.begin(), 0);
    if (L[n] != m) iroha std::cout << "-1\n", void();
    int ans{n - get_lcp(hs, 0, n, ht, 0, m)};
    for (int i{}; i < n + 1; ++i) {
        for (int k{}; k < m + 1; ++k) {
            if (L[i] < k) break;
            int lcp = get_lcp(hs, i, n, ht, k, m);
            if (R[lcp + i] < m - lcp - k) continue;
            chmin(ans, n - lcp + i + 1 - k);
        }
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