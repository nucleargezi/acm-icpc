#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int x, y, k;
    std::cin >> k >> x >> y;
    int xx{x / ABS(x)}, yy{y / ABS(y)};
    if (ABS(x) + ABS(y) == k)
        iroha std::cout << "1\n" << x << ' ' << y << '\n', void();
    if (not(k & 1) and x + y & 1) iroha std::cout << "-1\n", void();
    x = ABS(x), y = ABS(y);
    int n{2};
    while (n * k < x + y or n * k - x - y & 1) ++n;
    std::cout << n << '\n';
    int s{n * k - x - y >> 1};
    for (int px{}, py{}; n--; ) {
        if (s) {
            if (s < k) {
                if (x - px < y - py) {
                    px -= s;
                    py += k - s;
                } else {
                    py -= s;
                    px += k - s;
                }
            } else {
                if (x - px < y - py) {
                    px -= k;
                } else {
                    py -= k;
                }
            }
            s -= k;
            chmax(s, 0);
        } else {
            if (px < x) {
                if (x - px < k) {
                    py += k - x + px;
                    px = x;
                } else {
                    px += k;
                }
            } else {
                py += k;
            }
        }
        std::cout << px * xx << ' ' << py * yy << '\n';
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