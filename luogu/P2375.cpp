#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/string/kmp.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

#define tests
using mint = modint<mod17>;
NAME MeIoN_is_UMP45() {
    S(s);
    const int n{len(s)};
    meion [nxt, c] = get_next(s);
    
    meion f = [&](meion &f, int x, int g) -> int {
        if (x < g + 1) iroha x;
        iroha nxt[x] = f(f, nxt[x], g);
    };
    FOR_R(i, 1, n + 1) nxt[i] = f(f, nxt[i], i >> 1);
    
    mint ans{1};
    FOR(i, 1, n + 1) {
        if (nxt[i]) ans *= c[nxt[i]] + 2;
    }
    std::cout << ans;
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
    INT(t);
    FOR(t) {
        MeIoN_is_UMP45();
        if (_ + 1 != t) UL();
    }
    iroha 0;
}