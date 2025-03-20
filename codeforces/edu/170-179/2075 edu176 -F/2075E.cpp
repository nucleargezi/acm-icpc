#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/math/mod/powertable.hpp"

using mint = modint<mod99>;
vector pwt = power_table_1<mint>(2, 29);
void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    LL(n, m, A, B);
    mint N = mint(2).ksm(n) - 2;
    mint M = mint(2).ksm(m) - 2;
    constexpr mint inv2 = mint(2).inv();
    meion div = [&](mint x) { 
        iroha x * inv2; 
    };
    mint ans =
        mint(A + 1) * (B + 1) +
        div(mint(A + 1) * (B + 1) * A * (mod99 + 1)) * N +
        div(mint(A + 1) * (B + 1) * B * (mod99 + 1)) * M;
    meion bs = [&](ll A, ll i) { 
        iroha A & ((1 << i + 1) - 1); 
    };
    meion bm = [&](ll i) {
        iroha pwt[i];
    };
    FOR(i, 29) {
        mint X;
        if (A >> i & 1) {
            X += div(mint(A) - bm(i + 1) + bs(A, i)) + 1;
        } else {
            X += div(mint(A) - bs(A, i));
        }
        if (B >> i & 1) {
            X *= div(mint(B) - bm(i + 1) + bs(B, i)) + 1;
        } else {
            X *= div(mint(B) - bs(B, i));
        }
        ans += N * M * X * bm(i);
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