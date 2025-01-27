#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> l(n + 1), r(n + 1);
    for (int i = 0; i < n; ++i) {
        std::cin >> l[i] >> r[i];
    }
    vector<vector<int>> v(n + 1);
    v[n].emplace_back(0);
    for (int i = 1, x, y; i < n; ++i) {
        std::cin >> x >> y, --x, --y;
        v[x].emplace_back(y), v[y].emplace_back(x);
    }
    ll ans = 0;
    vector<int> a(n + 1);
    [&](this meion &&dfs, int n, int fa) -> void {
        int m = -inf<int>;
        for (int i : v[n]) {
            if (i == fa) continue;
            dfs(i, n); 
            chmax(m, a[i]);
        }
        chmin(m, r[n]), chmax(m, l[n]);
        a[n] = m;
        for (int i : v[n]) {
            ans += std::max(0, a[i] - a[n]);
        }
    }(n, n);
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