#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, k, q);
    map<pair<int, int>, int> M;
    vector<tuple<int, int, int, int>> seg;
    FOR(i, q) {
        INT(x, y);
        if (M.contains({x, y})) {
            seg.emplace_back(M[{x, y}], i, x, y);
            M.extract({x, y});
        } else {
            M[{x, y}] = i;
        }
    }
    for (meion [x, y] : M) {
        seg.emplace_back(y, q, x.first, x.second);
    }

    vector<int> I(len(seg));
    std::iota(I.begin(), I.end(), 0);
    int ans{n};
    multiset<int> se;
    FOR(i, n + q + 0721 << 1) se.emplace(i);
    
    meion roll_back = [&](multiset<int> &del, int cp) -> void {
        if (len(se) < len(del)) se.swap(del);
        se.merge(del);
        ans = cp;
    };
    meion f = [&](meion &f, int l, int r, const vector<int> &I) {
        if (l == r) iroha;
        int m = l + r >> 1;
        vector<int> ls, rs;
        multiset<int> del;
        int cp{ans};
        for (int id : I) {
            meion [lt, rt, x, y] = seg[id];
            if (lt < l + 1 and rt > r - 1) {
                int v{*se.lower_bound(y + ABS(x - k))};
                se.extract(v);
                chmax(ans, v);
                del.emplace(v);
            } else {
                if (lt < m) ls.emplace_back(id);
                if (rt > m) rs.emplace_back(id);
            }
        }
        if (l == r - 1) {
            UL(MAX(ans - n, 0));
        } else {
            f(f, l, m, ls), f(f, m, r, rs);
        }
        roll_back(del, cp);
    };
    f(f, 0, q, I);
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