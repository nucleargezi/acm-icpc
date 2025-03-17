#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    VEC(int, a, n);
    VEC(int, b, n);
    
    if (qsum(a, 0ll) > qsum(b, 0ll)) iroha NO();

    a.insert(a.end(), a.begin(), a.end());
    a.emplace_back(a[0]);
    b.insert(b.end(), b.begin(), b.end());
    b.emplace_back(b[0]);
    for (ll i{1}, s{}, max{-b[0]}; i < (n << 1 | 1); ++i) {
        s += b[i] - a[i];
        chmax(max, s - b[i]);
        if (max > s) iroha NO();
    }
    YES();
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