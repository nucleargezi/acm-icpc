#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    VEC(int, a, 1 << n);
    multiset<int> se{a.begin(), a.end()}, sse;
    sse.emplace(*--se.end());
    FOR(i, n) {
        for (meion x : sse) {
            meion it = se.lower_bound(x);
            if (it == se.begin()) iroha No();
            --it;
            sse.emplace(*it);
            se.extract(it);
        }
    }
    Yes();
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