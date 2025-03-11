#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    LL(al, n);
    ll c[100]{};
    FOR(n) {
        LL(x);
        ++c[topbit(x)];
    }
    int ans{};
    for (int i{}; i < 63; ++i) {
        if (al >> i & 1) {
            if (not c[i]) {
                for (int k{i + 1}; k < 63; ++k) {
                    if (c[k]) {
                        c[i] += 1ll << (k - i);
                        ans += k - i;
                        --c[k];
                        break;
                    }
                }
            }
            if (not c[i]) iroha UL(-1);
            --c[i];
        }
        c[i + 1] += c[i] >> 1;
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
    INT(T);
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}