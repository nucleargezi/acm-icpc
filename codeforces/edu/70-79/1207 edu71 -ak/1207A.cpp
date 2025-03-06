#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n, a, b, c, d;
    std::cin >> n >> a >> b >> c >> d;
    n >>= 1;
    std::cout << MAX(c * MIN(n, a), d * MIN(n, b),
                     c * MIN(n, a) + d * MIN(MAX(n - a, 0), b), 
                     d * MIN(n, b) + c * MIN(MAX(n - b, 0), a))
              << '\n';
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