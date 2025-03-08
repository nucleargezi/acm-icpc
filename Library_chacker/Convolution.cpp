#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/ntt_fft.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    using poly = vector<modint<mod99>>;
    int n, m;
    std::cin >> n >> m;
    poly a(n), b(m);
    std::cin >> a >> b;
    std::cout << convolution(a, b) << '\n';
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