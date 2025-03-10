#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> L(n), R(n);
    for (int i{}; i < n; ++i) std::cin >> L[i] >> R[i];
    int l{qmin(L)}, r(qmax(R));
    for (int i{}; i < n; ++i) {
        if (L[i] == l and R[i] == r) {
            iroha std::cout << ++i << '\n', void();
        }
    }
    std::cout << "-1\n";
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