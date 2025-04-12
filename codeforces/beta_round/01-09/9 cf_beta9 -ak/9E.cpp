#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

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
    vector<vector<int>> lines;
    vector<vector<int>> rings;
    vector<int> line;
    vector<uint8_t> vis(n);
    meion f = [&](meion &f, int n) -> bool {
        vis[n] = 1;
        line.emplace_back(n);
        bool ok{len(v[n]) < 3};
        for (int x : v[n]) if (not vis[x]) ok &= f(f, x);
        iroha ok;
    };
    FOR(i, n) if (not vis[i]) {
        line.clear();
        if (not f(f, i)) iroha NO();
        if (len(line) == 1) {
            if (len(v[line[0]]) == 0) lines += line;
            else if (len(v[line[0]]) == 2) rings += line;
            else iroha NO();
        } else {
            lines.emplace_back();
            for (int x : line) {
                if (len(v[x]) == 1) lines.back() += x;
            }
            if (not len(lines.back())) {
                lines.pop_back();
                rings += line;
            } else if (len(lines.back()) != 2) {
                iroha NO();
            }
        }
    }
    if (len(lines) == 1 and not len(rings)) {
        YES();
        UL(1);
        UL(lines[0][0] + 1, lines[0].back() + 1);
    } else if (not len(lines) and len(rings) == 1) {
        YES();
        UL(0);
    } else if (not len(rings)) {
        YES();
        for (meion &v : lines) {
            sort(v);
            if (len(v) == 1) v += v[0];
        }
        sort(lines);
        using PII = pair<int, int>;
        using std::minmax;
        vector<PII> ans;
        dsu g(n);
        vector<int> in(n);
        while (true) {
            bool f{true};
            vector I = argsort(lines);
            FOR(i, len(lines)) if (lines[I[i]][0] != inf<int>) {
                FOR(k, i + 1, len(lines))
                if (lines[I[k]][0] != inf<int> and g.merge(I[i], I[k])) {
                    ans += PII(minmax(lines[I[i]][0] + 1, lines[I[k]][0] + 1));
                    lines[I[i]][0] = lines[I[k]][0] = inf<int>;
                    sort(lines[I[i]]);
                    sort(lines[I[k]]);
                    ++in[I[i]], ++in[I[k]];
                    goto fail;
                }
            }
            if (false) fail: f = false;
            if (f) break;
        }
        FOR(i, n) if (in[i] == 1) {
            FOR(k, i + 1, n) if (in[k] == 1) {
                ans += PII(minmax(lines[i][0] + 1, lines[k][0] + 1));
            }
            break;
        }
        sort(ans);
        UL(len(ans));
        FOR(i, len(ans)) UL(ans[i]);
    } else {
        NO();
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
    LL(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}