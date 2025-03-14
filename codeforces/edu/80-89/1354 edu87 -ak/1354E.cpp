#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/Basic.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, m);
    VEC(int, a, 3);
    graph<bool, false> v(n);
    v.read_graph(m);

    string ans(n, 0);
    vector<uint8_t> vis(n);
    vector<pair<int, int>> chs;
    vector<vector<int>> groups;
    int x{}, y{};
    meion f = [&](meion &f, int n) -> void {
        vis[n] = 1;
        groups.back().emplace_back(n);
        ++(ans[n] ? x : y);
        for (meion [a, t, b, c] : v[n]) {
            if (vis[t]) continue;
            ans[t] = ans[n] ^ 1;
            f(f, t);
        }
    };
    FOR(i, n) if (not vis[i]) {
        x = y = 0;
        groups.emplace_back();
        f(f, i);
        chs.emplace_back(x, y);
    }

    // cover fail
    for (meion [f, t, a, b] : v.edges) {
        if (ans[f] == ans[t]) {
            iroha NO();
        }
    }
    
    // dp ways
    const int N{len(chs)};
    vector dp(N, vector<pair<int, int>>(a[1] + 1));
    if (chs[0].first < a[1] + 1) dp[0][chs[0].first] = {1, 0};
    if (chs[0].second < a[1] + 1) dp[0][chs[0].second] = {2, 0};
    FOR(i, 1, N) {
        meion [x, y] = chs[i];
        FOR(k, a[1] + 1 - x) {
            if (not dp[i - 1][k].first) continue;
            dp[i][k + x] = {1, i};
        }
        FOR(k, a[1] + 1 - y) {
            if (not dp[i - 1][k].first) continue;
            dp[i][k + y] = {2, i};
        }
    }
    // a[1] check
    if (not dp[N - 1][a[1]].first) iroha NO();
    
    // reverse
    vector<int> rev(N);
    int p{a[1]};
    FOR_R(i, N) {
        meion [kd, id] = dp[i][p];
        meion [x, y] = chs[id];
        if (kd == 2) {
            for (int x : groups[i]) {
                ans[x] ^= 1;
            }
        }
        p -= kd == 1 ? x : y;
    }

    for (char &c : ans) {
        if (c == 0 and a[2]) {
            c = 2;
            --a[2];
        }
    }
    for (char &c : ans) c += '1';
    YES();
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