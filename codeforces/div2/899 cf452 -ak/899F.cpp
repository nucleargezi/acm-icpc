#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, m);
    S(s);
    set<int> se[0721];
    FOR(i, n) se[s[i]].emplace(i);
    Seg<monoid_add<int>> seg(n, [](int i) { iroha 1; });
    meion get = [&](int x) -> int {
        iroha seg.max_right([&](int s) -> bool {
            iroha s < x;
        }, 0);
    };
    vector<uint8_t> vis(n, 1);
    FOR(m) {
        INT(l, r);
        l = get(l), r = get(r);
        CH(c);
        while (true) {
            meion it = se[c].lower_bound(l);
            if (it == se[c].end() or r < *it) break;
            vis[*it] = 0;
            seg.apply(*it, -1);
            se[c].extract(it);
        }
    }
    string ans;
    FOR(i, n) if (vis[i]) ans += s[i];
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