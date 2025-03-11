#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    INT(n, m);
    VEC(ll, O, n);
    VEC(ll, R, n);
    ll ans{};
    map<ll, ll> M;
    FOR(i, n) {
        ll o(O[i]), r{R[i]}, L{o - r}, R{o + r + 1};
        FOR(x, L, R) {
            ll d = std::floor(std::sqrt(r * r - (x - o) * (x - o)));
            ans += MAX(0ll, d - M[x]) << 1;
            chmax(M[x], d);
        }
    }
    UL(ans + len(M));
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