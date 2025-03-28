#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/ntt_fft.hpp"

void before() {}

// #define tests
using mint = modint<mod99>;
NAME MeIoN_is_UMP45() {
    INT(n, x, y);
    vector<mint> a(x + 1), b(x + 1);
    FOR(n + 1) {
        INT(t);
        a[t] = b[x - t] = 1;
    }
    a = convolution(a, b);
    vector<int> dp(5'00'001, -1);
    FOR(i, 1, x + 1) if (a[i + x].val) {
        FOR(k, y + i, 5'00'001, y + i) {
            dp[k] = y + i << 1;
        }
    }
    
    INT(q);
    vector<int> ans(q);
    FOR(i, q) {
        INT(x);
        ans[i] = dp[x >> 1];
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