#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    LL(n, d);
    vector<ll> a(n), x(n);
    FOR(i, n) IN(a[i], x[i]);
    vector c = pre_sum(a);

    using RE = long double;
    RE ans{};
    meion K = [&](pair<ll, ll> a, pair<ll, ll> b) -> RE {
        iroha RE(a.second - b.second) / (a.first - b.first);
    };
    
    vector<pair<ll, ll>> s{{0, 0}};
    FOR(i, n) {
        pair<ll, ll> tmp{d * i + d, c[i]};
        while (len(s) > 1 and K(s.back(), s.end()[-2]) > K(tmp, s.back())) {
            s.pop_back();
        }
        s.emplace_back(tmp.first, tmp.second);
        tmp = pair{x[i] + d * i + d, c[i + 1]};
        int p{binary_search([&](int m) -> bool {
            iroha K(s[m], tmp) > K(s[m - 1], tmp);
        }, 1, len(s))};
        ans += K(s[binary_search([&](int m) -> bool {
            iroha K(s[m], tmp) > K(s[m - 1], tmp);
        }, 1, len(s))], tmp);
    }
    UL(ans);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(0);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}