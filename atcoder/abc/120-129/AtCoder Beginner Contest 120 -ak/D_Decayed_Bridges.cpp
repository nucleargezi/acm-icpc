#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<pair<int, int>> e(m);
    for (meion &[x, y] : e) {
        std::cin >> x >> y, --x, --y;
    }

    dsu g(n);
    vector<ll> ans(m + 1, n * (n - 1ll) >> 1);
    for (int i{m}, x, y; i--; ) {
        std::tie(x, y) = e[i];
        ans[i] = ans[i + 1];
        ll a = g.size(x), b = g.size(y);
        if (g.merge(x, y)) {
            ans[i] -= a * b;
        }
    }
    
    ans.erase(ans.begin());
    for (ll x : ans) {
        std::cout << x << '\n';
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