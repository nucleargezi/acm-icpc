#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/primtable.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, q;
    std::cin >> n >> q;
    vector a = primtable(n);
    for (int i{}, x; i < q; ++i) {
        std::cin >> x;
        std::cout << a[--x] << '\n';
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