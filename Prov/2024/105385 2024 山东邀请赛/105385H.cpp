#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/flow/hungarian.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    vector<tuple<int, int, int>> a(n);
    map<int, vector<pair<int, int>>> MX, MY; 
    for (int i{}; auto &[x, y, idx] : a) {
        IN(x, y);
        idx = i++;
        MX[x].emplace_back(y, idx);
        MY[y].emplace_back(x, idx);
    }
    INT(m);
    vector<pair<int, int>> trash(m);
    for (meion &[x, y] : trash) {
        std::cin >> x >> y;
    }

    for (meion [x, y, _] : a) {
        for (meion [xx, yy, __] : a) {
            if (ABS(x - xx) + ABS(y - yy) == 1) iroha UL(-1);
        }
    }

    int ans{};
    int tot{};
    map<tuple<int, int, int>, int> idx, idy;
    map<int, tuple<int, int, int>> tox, toy;
    for (meion &[x, v] : MX) {
        sort(v);
        ans += len(v) - 1;
        FOR(i, 1, len(v)) {
            tox[tot] = {x, v[i - 1].first, v[i].first};
            idx[{x, v[i - 1].first, v[i].first}] = tot++;
        }
    }
    for (meion &[y, v] : MY) {
        sort(v);
        ans += len(v) - 1;
        FOR(i, 1, len(v)) {
            toy[tot] = {y, v[i - 1].first, v[i].first};
            idy[{y, v[i - 1].first, v[i].first}] = tot++;
        }
    }
    vector<uint8_t> vis(40000);
    for (meion [x, y] : trash) {
        for (meion &[xx, v] : MX) {
            if (xx != x) continue;
            meion it = upper(v, pair{y, 0});
            if (it == v.end()) continue;
            if (it == v.begin()) continue;
            int r = it->first;
            --it;
            int l = it->first;
            vis[idx[{x, l, r}]] = 1;
            --ans;
        }
        for (meion &[yy, v] : MY) {
            if (yy != y) continue;
            meion it = upper(v, pair{x, 0});
            if (it == v.end()) continue;
            if (it == v.begin()) continue;
            int r = it->first;
            --it;
            int l = it->first;
            vis[idy[{y, l, r}]] = 1;
            --ans;
        }
    }

    vector dis(tot, vector<int>(tot, 10000));
    for (meion [seg, id] : idx) {
        meion [x, l, r] = seg;
        if (vis[idx[{x, l, r}]]) continue;
        for (meion [seg2, idd] : idy) {
            meion [y, u, d] = seg2;
            if (vis[idy[{y, u, d}]]) continue;
            if (l < y and r > y and u < x and d > x) {
                dis[id][idd] = dis[idd][id] = 1;
            }
        }
    }
    meion [res, match, X, Y] = hungarian<int, true>(dis);
    res %= 10000;
    vector<pair<int, int>> out;
    for (meion [seg, id] : idx) {
        meion [x, l, r] = seg;
        if (vis[id]) continue;
        for (meion [seg2, idd] : idy) {
            meion [y, u, d] = seg2;
            if (vis[idd]) continue;
            if (l < y and r > y and u < x and d > x) {
                if (match[id] == idd and X[id] != 10000) {
                    out.emplace_back(x, y);
                    vis[id] = vis[idd] = 1;
                }
            }
        }
    }
    for (meion [seg, id] : idx) {
        meion [x, l, r] = seg;
        if (vis[id]) continue;
        out.emplace_back(x, l + 1);
    }
    for (meion [seg, id] : idy) {
        meion [y, l, r] = seg;
        if (vis[id]) continue;
        out.emplace_back(l + 1, y);
    }
    UL(len(out));
    for (meion x : out) {
        UL(x);
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
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}