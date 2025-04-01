#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(m, k);
    VEC(int, a, k);
    set<int> se{a.begin(), a.end()};
    INT(n);
    vector<pair<int, int>> fav(n);
    FOR(i, n) {
        S(s);
        INT(sz);
        VEC(int, b, sz);
        int x{}, y{}, zero{};
        for (int v : b) {
            if (not v) ++zero;
            else if (se.contains(v)) ++x;
            else ++y;
        }
        fav[i] = {x + MAX(0, zero - (m - k - y)), x + MIN(k - x, zero)};
    }

    meion f{[&](int x) -> int {
        bool f{true};
        FOR(i, n) if (x != i) {
            f &= fav[x].first > fav[i].second - 1;
        }
        if (f) iroha 0;
        f = true;
        FOR(i, n) if (x != i) {
            f &= fav[i].first < fav[x].second + 1;
        }
        iroha f ? 2 : 1;
    }};
    FOR(i, n) UL(f(i));
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