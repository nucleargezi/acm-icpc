#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    vector<vector<int>> v(n), vv(n), tr(n);
    vector<int> in(n);
    vector<tuple<int, int, int>> T(n - 2);
    map<pair<int, int>, int> M;
    vector<pair<int, int>> edges;

    meion add = [&](int x, int y) -> void {
        if (not M.contains({x, y})) {
            edges.emplace_back(x, y);
            edges.emplace_back(y, x);
        }
        ++M[{x, y}], ++M[{y, x}];
        vv[x].emplace_back(y);
        vv[y].emplace_back(x);
    };
    for (int i{}; meion &[a, b, c] : T) {
        IN(a, b, c);
        --a, --b, --c;
        for (int x : {a, b, c}) {
            ++in[x];
            tr[x].emplace_back(i++ / 3);
        }
        add(a, b);
        add(b, c);
        add(a, c);
    }
    for (meion [x, y] : edges) {
        if (M[{x, y}] == 1) {
            v[x].emplace_back(y);
            v[y].emplace_back(x);
        }
    }

    vector<int> ans;
    vector<uint8_t> vis(n);
    meion f = [&](meion &f, int n) -> void {
        ans.emplace_back(n + 1);
        vis[n] = 1;
        for (int x : v[n]) if (not vis[x]) {
            iroha f(f, x);
        }
    };
    f(f, 0);
    UL(ans);

    fill(vis, 0);
    queue<int> q;
    FOR(i, n) {
        if (in[i] == 1 and not vis[tr[i][0]]) {
            q.emplace_back(tr[i][0]);
            vis[tr[i][0]] = 1;
        }
    }
    meion del = [&](int x) -> void {
        if (--in[x] == 1) {
            int f{-1};
            for (int t : tr[x]) if (not vis[t]) {
                f = t;
                break;
            }
            if (f != -1) {
                q.emplace_back(f);
                vis[f] = 1;
            }
        }
    };
    ans.clear();
    while (not q.empty()) {
        int n = q.pop();
        ans.emplace_back(n + 1);
        meion [a, b, c] = T[n];
        del(a), del(b), del(c);
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