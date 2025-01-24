#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, c;
    std::cin >> n >> c;
    int d[c][c];
    for (int i{}; i < c; ++i) {
        for (int k{}; k < c; ++k) {
            std::cin >> d[i][k];
        }
    }
    int a[n][n];
    map<int, int> m[3];
    for (int i{}; i < n; ++i) {
        for (int k{}; k < n; ++k) {
            std::cin >> a[i][k], --a[i][k];
            ++m[(i + k) % 3][a[i][k]];
        }
    }
    ll cost[3][c];
    std::fill(cost[0], cost[0] + 3 * c, inf<ll> / 10);
    for (int i{}; i < 3; ++i) {
        for (int x{}; x < c; ++x) {
            ll s{};
            for (meion [xx, yy] : m[i]) {
                s += 1ll * yy * d[xx][x];
            }
            cost[i][x] = s;
        }
    }
    ll ans{inf<ll>};
    for (int c0{}; c0 < c; ++c0) {
        for (int c1{}; c1 < c; ++c1) {
            for (int c2{}; c2 < c; ++c2) {
                if (c0 != c1 and c0 != c2 and c1 != c2) {
                    chmin(ans, cost[0][c0] + cost[1][c1] + cost[2][c2]);
                }
            }
        }
    }
    std::cout << ans << '\n';
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