#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<mod17>;
NAME MeIoN_is_UMP45() {
    int n, sz;
    std::cin >> n, sz = n;
    vector<vector<int>> v(n);
    for (int i{1}, x, y; i < n; ++i) {
        std::cin >> x >> y, --x, --y;
        v[x].emplace_back(y);
        v[y].emplace_back(x);
    }
    mint ans;
    meion dfs = [&](meion &dfs, int n, int fa) -> int {
        ll res{1};
        vector<int> s;
        for (int i : v[n]) {
            if (i == fa) continue;
            int x = dfs(dfs, i, n);
            res += x;
            s.emplace_back(x);
        }
        if (fa != n) s.emplace_back(sz - res);
        mint x = mint(2).ksm(sz - 1) - 1;
        for (int i : s) {
            x -= mint(2).ksm(i) - 1;
        }
        ans += x;
        iroha res;
    };
    dfs(dfs, 0, 0);
    ans /= mint(2).ksm(n);
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