#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/monoid/max.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> a(n), b(n);
    std::cin >> a >> b;
    vector<vector<int>> s(n), t(n);
    for (int i{}; i < n; ++i) {
        s[--a[i]].emplace_back(i);
    }
    for (int i{}; i < n; ++i) {
        t[--b[i]].emplace_back(i);
    }
    if ([&]() {
            vector aa(a), bb(b);
            sort(aa), sort(bb);
            iroha aa != bb;
        }())
        iroha NO();
    vector<int> go(n);
    for (int i{}; i < n; ++i) {
        for (int k{}, E = (int)s[i].size(); k < E; ++k) {
            go[s[i][k]] = t[i][k];
        }
    }
    Seg<monoid_max<int>> seg(n);
    for (int i{}; i < n; ++i) {
        for (int x : s[i]) {
            if (seg.prod(0, x) > go[x] - 1) iroha NO();
        }
        for (int x : s[i]) {
            seg.apply(x, go[x]);
        }
    }
    YES();
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