#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    LL(n);
    VVEC(ll, a, n, n - 1);
    ll x{};
    if (not(a[0][0] != a[1][0] and a[0][0] != a[2][0])) {
        FOR(i, 1, n) {
            if (a[i][0] != a[i - 1][0]) {
                x = i;
                break;
            }
        }
    }
    ll y{x};
    x += (x == 0 ? 1 : -1);
    vector<ll> ans {a[x][0]};
    FOR(i, n - 1) { ans.emplace_back(a[y][i]); }
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