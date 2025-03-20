#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    INT(n, k);
    VEC(ll, a, n);
    ll ans{};
    FOR(i, n) {
        vector<ll> b{a.begin(), a.begin() + i},
                   c{a.begin() + i + 1, a.end()};
        sort(b, greater());
        sort(c, greater());
        b = pre_sum(b);
        c = pre_sum(c);
        FOR(j, 0, MIN(len(b), k + 1)) {
            if (k - j < len(c) and not(i and not j) and
                not(i < n - 1 and not(k - j)))
                chmax(ans, b[j] + c[k - j] + a[i]);
        }
    }
    UL(ans);
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