#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    SV(s, '0');
    meion seg = run_length(s);
    sort(seg, greater());
    int ans{};
    for (int t{}; meion [x, y] : seg) {
        if (not x) break;
        if (t & 1 ^ 1) ans += y;
        t ^= 1;
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