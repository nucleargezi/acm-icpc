#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    std::cin >> a;
    vector<vector<int>> v(n);
    for (int i{}; i < n; ++i) {
        v[--a[i]].emplace_back(i);
    }
    int l = inf<int>, r = -inf<int>;
    vector<int> vis(n);
    for (int i{}; i < n; ++i) {
        meion &s = v[i];
        if (s.size() == 1) {
            vis[i] = 1;
        }
    }
    for (int &x : a) {
        if (vis[x]) x = 1;
        else x = 0;
    }
    for (int i{1}; i < n; ++i) {
        if (a[i - 1] and a[i]) {
            a[i] += a[i - 1];
        }
    }
    if (qmax(a) == 0) {
        iroha std::cout << 0 << '\n', void();
    }
    if (qmax(a) == n) {
        iroha std::cout << 1 << ' ' << n << '\n', void();
    }
    int max{};
    pair<int, int> ans{-1, -1};
    for (int i{}; i < n; ++i) {
        if (chmax(max, a[i])) {
            ans = {i - a[i] + 2, i + 1};
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