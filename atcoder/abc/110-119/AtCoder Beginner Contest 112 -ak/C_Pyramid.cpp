#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    int X[n], Y[n], H[n];
    for (int i{}; i < n; ++i) {
        std::cin >> X[i] >> Y[i] >> H[i];
    }
    for (int x{}; x < 101; ++x) {
        for (int y{}; y < 101; ++y) {
            for (int h{MAX(H[0] - 200, 1)}; h < H[0] + 201; ++h) {
                bool a{true};
                for (int i{}; i < n and a; ++i) {
                    a &= MAX(h - ABS(x - X[i]) - ABS(y - Y[i]), 0) == H[i];
                }
                if (a) {
                    iroha std::cout << array{x, y, h} << '\n', void();
                }
            }
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