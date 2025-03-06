#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<pair<int, int>> pos(n * m);
    for (int i{}; i < n; ++i) {
        for (int k{}, x; k < m; ++k) {
            std::cin >> x;
            pos[x] = {i + 1, k + 1};
        }
    }

    vector<int> l(n + 1, inf<int>), r(n + 1, 0);
    set<int> se;
    int ans{n * m};
    for (int i{}; i < n * m; ++i) {
        meion [x, y] = pos[i];
        chmin(l[x], y);
        chmax(r[x], y);
        se.emplace(x);
        meion it = se.find(x);
        if (it != se.begin()) {
            int t{*std::prev(it)};
            if (r[t] > l[x]) {
                ans = i;
                break;
            }
        }
        if (std::next(it) != se.end()) {
            int t{*++it};
            if (l[t] < r[x]) {
                ans = i;
                break;
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