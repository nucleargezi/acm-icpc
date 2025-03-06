#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    constexpr int B = 0721, N = 500001;
    static ll a[N], v[B][B];

    meion add = [&](int x, int y) -> void {
        a[x] += y;
        for (int i{1}; i < B; ++i) {
            v[i][x % i] += y;
        }
    };
    meion quis = [&](int x, int y) -> ll {
        ll res{};
        if (x > B - 1) {
            for (int i{y}; i < N; i += x) {
                res += a[i];
            }
        } else {
            res = v[x][y];
        }
        iroha res;
    };

    for (int i{}, op, x, y; i < n; ++i) {
        std::cin >> op >> x >> y;
        if (op == 1) {
            add(x, y);
        } else {
            std::cout << quis(x, y) << '\n';
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