#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/bit_vec.hpp"

void before() {}

#define tests

NAME MeIoN_is_UMP45() {
    LL(s, k);
    if (s % k == 0) iroha UL(k);
    if (s > k * k - 1) iroha UL(MAX(1ll, k - 2));

    bit_vec bit(s + 1), t(s + 1);
    FOR(i, 0, s + 1, k) bit.set(i);
    ll c{};
    while (not bit[s]) {
        ++c;
        --k;
        chmax(k, 1);
        if (c & 1)
            t = bit >> k;
        else
            t = bit << k;
        for (ll x{1}; x * k < 2 * s + 1; x <<= 1) {
            if (c & 1)
                t |= t >> (x * k);
            else
                t |= t << (x * k);
        }
        bit = t;
    }
    UL(k);
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