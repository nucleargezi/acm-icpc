#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<string> s(n);
    std::cin >> s;
    
    vector dis(n, vector<int>(n, inf<int>));
    queue<pair<int, int>> q;
    for (int i{}; i < n; ++i) {
        dis[i][i] = 0;
        q.emplace_back(i, i);
    }
    for (int i{}; i < n; ++i) {
        for (int k{}; k < n; ++k) {
            if (i == k or s[i][k] == '-') continue;
            if (chmin(dis[i][k], 1)) {
                q.emplace_back(i, k);
            }
        }
    }
    while (not q.empty()) {
        meion [x, y] = q.front();
        q.pop();
        for (int i{}; i < n; ++i) {
            for (int k{}; k < n; ++k) {
                if (s[i][x] != '-' and s[i][x] == s[y][k] and
                    chmin(dis[i][k], dis[x][y] + 2)) {
                    q.emplace_back(i, k);
                }
            }
        }
    }
    for (meion &v : dis) {
        for (int t{}; int x : v) {
            std::cout << (x == inf<int> ? -1 : x) << " \n"[++t == n];
        }
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