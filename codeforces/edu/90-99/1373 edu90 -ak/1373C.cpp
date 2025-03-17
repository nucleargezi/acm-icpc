#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    S(s);
    const int n{len(s)};
    vector<int> a(n);
    FOR(i, n) a[i] = s[i] == '+' ? 1 : -1;
    a = pre_sum<false>(a);

    ll ans{n}, init{};
    FOR(i, n) {
        if (init < -a[i]) {
            ans += (i + 1) * (-a[i] - init);
            init = -a[i];
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