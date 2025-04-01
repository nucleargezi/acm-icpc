#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(N, A, B);
    VEC(int, a, N);
    
    int ans{}, C{};
    FOR(i, N) {
        if (a[i] == 1) {
            if (A) --A;
            else if (B) --B, ++C;
            else if (C) --C;
            else ans += 1;
        } else {
            if (B) --B;
            else ans += 2;
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