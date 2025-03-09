#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<mod99>;
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    dsu g(n);
    for (int i{}, p; i < n; ++i) {
        std::cin >> p;
        g.merge(i, --p);
    }
    for (int i {}; i < n; ++i){
        if (g.size(i) & 1) {
            iroha std::cout << "0\n", void();
        }
    }
    std::cout << mint(2).ksm(g.get_comp()) << '\n';
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