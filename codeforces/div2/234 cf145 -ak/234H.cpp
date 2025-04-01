#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    VEC(int, a, n);
    INT(m);
    VEC(int, b, m);

    meion f = [&](int t) {
        vector<int> I, F;
        int x{}, y{};
        while (x < n or y < m) {
            while (x < n and a[x] == t) {
                I.emplace_back(++x);
            }
            while (y < m and b[y] == t) {
                I.emplace_back(++y + n);
            }
            if (t == 1 or (x < n or y < m)) F.emplace_back(x + y);
            t ^= 1;
        }
        iroha tuple{len(F), I, F};
    };
    meion [x, Ix, Fx] = f(0);
    meion [y, Iy, Fy] = f(1);
    if (y < x) Ix.swap(Iy), Fx.swap(Fy);
    UL(Ix);
    UL(len(Fx));
    UL(Fx);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    before();
#ifdef tests
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}