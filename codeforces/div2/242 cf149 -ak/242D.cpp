#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<int>> v(n);
    for (int i{}, x, y; i < m; ++i) {
        std::cin >> x >> y;
        --x, --y;
        v[x].emplace_back(y), v[y].emplace_back(x);
    }
    vector<int> a(n);
    std::cin >> a;

    queue<int> q;
    for (int i{}; i < n; ++i) not a[i] and q.emplace_back(i);
    vector<int> ans;
    while (not q.empty()) {
        int n = q.pop();
        ans.emplace_back(n + 1);
        --a[n];
        for (int x : v[n]) {
            not --a[x] and q.emplace_back(x);
        }
    }
    std::cout << len(ans) << '\n' << ans << '\n';
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