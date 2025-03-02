#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> b(n);
    std::cin >> b;
    vector<pair<int, int>> range(n);
    for (int i{}; i < n; ++i) {
        int x{i + 1};
        if (not b[i]) {
            range[i] = {x + 1, n};
        } else {
            range[i] = {
                binary_search([&](int m) -> bool { iroha x / m == b[i]; },
                              x / b[i], 0),
                x / b[i]};
        }
    }
    vector<int> ans(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    meion id = argsort(range);
    for (int i {1}, t {}; i < n + 1; ++i) {
        while (t < n and range[id[t]].first < i + 1 and
               range[id[t]].second > i - 1) {
            q.emplace(range[id[t]].second, id[t]);
            ++t;
        }
        ans[q.top().second] = i;
        q.pop();
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