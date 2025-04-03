#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    INT(n, k);
    VEC(string, a, 3);
    FOR(i, 3) a[i].append("......"); 
    int x{}, y{};
    FOR(i, 3) if (a[i][0] == 's') x = i;
    int ok{1 << x};
    while (y < n + 1) {
        ++y;
        int c{};
        FOR(i, 3) if (a[i][y] == '.') c |= 1 << i;
        ok &= c;
        ok |= ok >> 1 | ok << 1;
        ok &= c;
        FOR(2) {
            ++y;
            c = 0;
            FOR(i, 3) if (a[i][y] == '.') c |= 1 << i;
            ok &= c;
        }
    }
    YES(ok);
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