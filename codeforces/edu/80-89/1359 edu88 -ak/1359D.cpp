#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    VEC(ll, a, n);
    
    ll ans{};
    meion f = [&](meion &f, int l, int r) -> void {
        if (r - l < 2) iroha;
        int m = l + r >> 1;
        f(f, l, m), f(f, m, r);
        vector<int> L{a.begin() + l, a.begin() + m},
            R{a.begin() + m, a.begin() + r};
        reverse(L);
        for (int i{}; i < 2; ++i, std::swap(L, R)) {
            ll max{-inf<ll>}, sl{}, sr{}, p{}, s{};
            FOR(i, len(L)) {
                sl += L[i];
                chmax(max, L[i]);
                while (p < len(R) and R[p] < max + 1) {
                    sr += R[p++];
                    chmax(s, sr);
                }
                chmax(ans, sl + s - max);
            }
        }
    };
    f(f, 0, n);
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