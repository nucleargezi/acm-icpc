#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> s[2];
    for (int i{}, x; i < n; ++i) {
        std::cin >> x;
        s[i & 1].emplace_back(x);
    }
    map<int, int> m[2];
    for (int i{}; i < 2; ++i) {
        for (int x : s[i]) {
            ++m[i][x];
        }
    }
    vector<pair<int, int>> L[] = {{m[0].begin(), m[0].end()}, {m[1].begin(), m[1].end()}};
    for (int i{}; i < 2; ++i) {
        for (meion &[x, y] : L[i]) {
            std::swap(x, y);
        }
        sort(L[i], greater());
    }
    int ans{inf<int>};
    for (int i{}; i < L[0].size() and i < 3; ++i) {
        for (int k{}; k < L[1].size() and k < 3; ++k) {
            meion [s0, x] = L[0][i];
            meion [s1, y] = L[1][k];
            if (x == y) continue;
            chmin(ans, n - s0 - s1);
        }
    }
    std::cout << (ans == inf<int> ? n / 2 : ans) << '\n';
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