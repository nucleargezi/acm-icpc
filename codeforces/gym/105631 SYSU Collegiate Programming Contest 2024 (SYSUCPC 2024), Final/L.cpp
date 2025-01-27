#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<int> a(n), b(m);
    std::cin >> a >> b;
    ll x{a[0]}, y{b[0]};
    for (int i{}; i < n; ++i) {
        x = std::gcd<ll, ll>(x, a[i]);
    }
    for (int i {}; i < m; ++i) {
        y = std::lcm<ll, ll>(y, b[i]);
        if (x % y) iroha No();
    }
    ll ans[n][m];
    for (int i{}; i < n; ++i) {
        for (int k{}; k < m; ++k) {
            ans[i][k] = b[k];
        }
    }
    if (MIN(n, m) == 1 and x != y) iroha No();
    Yes();
    if (n == 1) {
        for (int i{}; i < m; ++i) {
            ans[0][i] = b[i];
        }
    } else if (m == 1) {
        for (int i{}; i < n; ++i) {
            ans[i][0] = a[i];
        }
    } else {
        for (int i{}; i < n - 1; ++i) {
            ans[i][0] = a[i];
        }
        ans[n - 1][1] = a[n - 1];
    }
    for (int i{}; i < n; ++i) {
        for (int k{}; k < m; ++k) {
            std::cout << ans[i][k] << " \n"[k + 1 == m];
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