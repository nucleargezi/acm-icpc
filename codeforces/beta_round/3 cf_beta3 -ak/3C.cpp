#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int a[3][3]{};
    int aa{}, bb{};
    FOR(i, 3) {
        S(s);
        FOR(k, 3) {
            if (s[k] == '.') continue;
            a[i][k] = s[k] == 'X' ? 1 : -1;
            (s[k] == 'X' ? aa : bb) += 1;
        }
    }
    if ((a[0][0] + a[0][1] + a[0][2] == 3 or a[1][0] + a[1][1] + a[1][2] == 3 or a[2][0] + a[2][1] + a[2][2] == 3 or a[0][0] + a[1][0] + a[2][0] == 3 or a[0][1] + a[1][1] + a[2][1] == 3 or a[0][2] + a[1][2] + a[2][2] == 3 or a[0][0] + a[1][1] + a[2][2] == 3 or a[0][2] + a[1][1] + a[2][0] == 3) and (a[0][0] + a[0][1] + a[0][2] == -3 or a[1][0] + a[1][1] + a[1][2] == -3 or a[2][0] + a[2][1] + a[2][2] == -3 or a[0][0] + a[1][0] + a[2][0] == -3 or a[0][1] + a[1][1] + a[2][1] == -3 or a[0][2] + a[1][2] + a[2][2] == -3 or a[0][0] + a[1][1] + a[2][2] == -3 or a[0][2] + a[1][1] + a[2][0] == -3)) {
        UL("illegal");
    } else if ((a[0][0] + a[0][1] + a[0][2] == 3 or a[1][0] + a[1][1] + a[1][2] == 3 or a[2][0] + a[2][1] + a[2][2] == 3 or a[0][0] + a[1][0] + a[2][0] == 3 or a[0][1] + a[1][1] + a[2][1] == 3 or a[0][2] + a[1][2] + a[2][2] == 3 or a[0][0] + a[1][1] + a[2][2] == 3 or a[0][2] + a[1][1] + a[2][0] == 3)) {
        UL((aa == bb + 1) ? "the first player won" : "illegal");
    } else if (a[0][0] + a[0][1] + a[0][2] == -3 or a[1][0] + a[1][1] + a[1][2] == -3 or a[2][0] + a[2][1] + a[2][2] == -3 or a[0][0] + a[1][0] + a[2][0] == -3 or a[0][1] + a[1][1] + a[2][1] == -3 or a[0][2] + a[1][2] + a[2][2] == -3 or a[0][0] + a[1][1] + a[2][2] == -3 or a[0][2] + a[1][1] + a[2][0] == -3) {
        UL(aa == bb ? "the second player won" : "illegal");
    } else if (a[0][0] and a[0][1] and a[0][2] and a[1][0] and a[1][1] and a[1][2] and a[2][0] and a[2][1] and a[2][2]) {
        UL((aa == bb + 1) ? "draw" : "illegal");
    } else if (aa == bb) {
        UL("first");
    } else if (aa == bb + 1) {
        UL("second");
    } else {
        UL("illegal");
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
    LL(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}