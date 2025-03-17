#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
constexpr int ans[] = {1, 1, 2, 3, 7, 16, 54, 243, 2038, 33120, 1182004,
    87723296, 907260828, 445874017, 131059413, 750854059, 85710140, 46269468,
    106575268, 569924828, 477980796, 853121491, 916490672, 848722293, 179336057,
    577163661, 709912061, 916083428, 988859367, 286999618, 29547862, 713350279,
    194424628, 553076032, 609634772, 876525030, 182311698, 148716617, 346128108,
    650982654, 373128192, 361260409, 524419271, 834718796, 514750301, 478609700,
    386216865, 881562716, 715225681, 602577017};
NAME MeIoN_is_UMP45() {
    INT(n);
    UL(ans[--n]);
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