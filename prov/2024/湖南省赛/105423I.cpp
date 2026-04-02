#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, k, m, q;
    std::cin >> n >> k >> m >> q;
    static bitset<10000> bit;
    for (int i{}, x; i < m; ++i) {
        std::cin >> x;
        for (int i{}, s{1}; i < k; ++i) {
            s = (s * x) % n;
            bit[s] = 1;
        }
    }
    for (int i{}, x; i < q; ++i) {
        std::cin >> x;
        bool f{true};
        for (int i{}, s{1}; i < k and f; ++i) {
            s = (s * x) % n;
            f &= bit[s];
        }
        std::cout << f << " \n"[i + 1 == q];
    }
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // std::ifstream in("in"); std::cin.rdbuf(in.rdbuf());
    // std::ofstream ou("out"); std::cout.rdbuf(ou.rdbuf());
    before();
#ifdef tests
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}