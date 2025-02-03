#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<mod17>;
NAME MeIoN_is_UMP45() {
    int n, k;
    std::cin >> n >> k;
    vector<vector<int>> v(n);
    for (int i = 1, x, y; i < n; ++i) {
        std::cin >> x >> y;
        --x, --y;
        v[x].emplace_back(y);
        v[y].emplace_back(x);
    }
    mint ans(k);
    meion dfs = [&](meion &&se, int n, int fa, int dp) -> void {
        int s = 0;
        for (int i : v[n]) {
            if (i == fa) continue;
            ++s;
            ans *= MAX(k - s - not not(dp), 0);
            se(se, i, n, dp + 1);
        }
    };
    dfs(dfs, 0, 0, 0);
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