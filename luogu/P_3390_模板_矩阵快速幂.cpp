#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/math/mat.hpp"

void before() {}

// #define tests
using mint = modint<mod17>;
using mat = MAT<mint, 100>;
NAME MeIoN_is_UMP45() {
    ll n, k;
    std::cin >> n >> k;
    mat x;
    for (int i{}; i < n; ++i) {
        for (int k{}; k < n; ++k) {
            std::cin >> x[i][k];
        }
    }
    x = x.ksm(k);
    for (int i{}; i < n; ++i) {
        for (int k{}; k < n; ++k) {
            std::cout << x[i][k] << " \n"[k + 1 == n];
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
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}