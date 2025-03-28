#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/bit_vec.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    bit_vec bit(114514);
    array<int, 6> a, ed{};
    int tot = 0;
    while (std::cin >> a, a != ed) {
        int sum{};
        FOR(i, 6) sum += (i + 1) * a[i];
        UL(string("Collection #") + std::to_string(++tot) + ':');
        bit.reset();
        bit[0] = 1;
        FOR(i, 6) FOR(a[i]) bit |= bit << i + 1;
        if (not(sum & 1) and bit[sum >> 1]) {
            UL("Can be divided.\n");
        } else {
            UL("Can't be divided.\n");
        }
    }
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