#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, m);
    vector<vector<int>> v(n);
    FOR(m) {
        INT(x, y);
        --x, --y;
        v[x].emplace_back(y);
        v[y].emplace_back(x);
    }
    vector<uint8_t> vis(n);
    priority_queue<int, vector<int>, greater<>> q;
    q.emplace(0);
    vis[0] = 1;
    vector<int> ans;
    while (not q.empty()) {
        int n{q.top()};
        q.pop();
        ans.emplace_back(n + 1);
        for (int x : v[n]) if (not vis[x]) {
            q.emplace(x);
            vis[x] = 1;
        }
    }
    UL(ans);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}