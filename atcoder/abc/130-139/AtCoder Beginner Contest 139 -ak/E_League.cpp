#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n;
    m = n - 1;
    vector<int> v[n + 1];
    for (int i{}; i < n; ++i) {
        for (int k{}, x; k < n - 1; ++k) {
            std::cin >> x;
            v[i].emplace_back(--x);
        }
        v[i].emplace_back(n);
        rev(v[i]);
    }
    v[n].emplace_back(n);
    vector<int> q(n);
    std::iota(q.begin(), q.end(), 0);
    int ans{};
    while (not q.empty()) {
        ++ans;
        vector<uint8_t> vis(n + 1);
        for (meion x : q) {
            if (v[v[x].back()].back() == x) {
                vis[v[x].back()] = 1;
                vis[x] = 1;
            }
        }
        q.clear();
        for (int i{}; i < n; ++i) {
            if (vis[i]) {
                q.emplace_back(i);
                v[i].pop_back();
            }
        }
    }
    for (int i{}; i < n; ++i) {
        if (v[i].back() != n) {
            iroha std::cout << -1 << '\n', void();
        }
    }
    std::cout << --ans << '\n';
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