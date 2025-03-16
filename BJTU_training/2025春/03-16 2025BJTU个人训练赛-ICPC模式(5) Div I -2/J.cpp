#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    LL(n, m, k);
    
    vector<pair<ll, ll>> a;
    ll ans{(n - 2) * (m - 2)};
    FOR(i, k) {
        LL(x, y);
        FOR(k, 3) FOR(j, 3) {
            if (x - k > 0 and x - k < n - 1 and y - j > 0 and y - j < m - 1) {
                a.emplace_back(x - k, y - j);
            }
        }
    }
    sort(a);
    vector<int> s(9);
    for (int i{}, t{}; i < len(a); ++i) {
        if (i + 1 < len(a) and a[i] == a[i + 1]) ++t;
        else ++s[t], t = 0, --ans;
    }
    UL(ans);
    FOR(i, 9) UL(s[i]);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}