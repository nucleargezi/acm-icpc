#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, T);
    vector<int> a(n), b(n);
    FOR(i, n) IN(a[i], b[i]);
    int sa{SUM(a)}, sb{SUM(b)};
    if (T < sa or T > sb) iroha NO();
    T = T - sa;
    vector<int> ans(a);
    FOR(i, n) {
        int d{b[i] - a[i]};
        int sub = MIN(d, T);
        ans[i] += sub;
        T -= sub;
    }
    YES();
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
    LL(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}