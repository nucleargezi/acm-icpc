#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/14-max_norm_sum.hpp"

// #define tests
using P = point<ll>;
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<P> ps(n);
    std::cin >> ps;
    meion square = max_norm_sum<ll>(ps);
    std::cout << std::sqrt(square) << '\n';
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // std::ifstream in("in"); std::cin.rdbuf(in.rdbuf());
    // std::ofstream ou("out"); std::cout.rdbuf(ou.rdbuf());
#ifdef tests
std::cin >> T;
#endif
while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}