#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<mod99>;
NAME MeIoN_is_UMP45() {
    INT(n, m);
    VEC(int, a, n);
    VEC(int, b, m);
    FOR_R(i, n - 1) chmin(a[i], a[i + 1]);
    if (a[0] != b[0]) iroha UL(0);

    mint ans{1};
    for (int i{1}, k{}; i < m; ++i) {
        while (k < n and a[k] < b[i]) ++k;
        if (k > n - 1 and a[k] != b[i]) {
            ans = 0;
            break;
        }
        int c{};
        while (k < n and a[k] == b[i]) {
            ++k, ++c;
        }
        ans *= c;
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