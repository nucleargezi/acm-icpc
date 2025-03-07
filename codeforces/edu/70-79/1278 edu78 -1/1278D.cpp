#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/Wavelet_Matrix.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"
#include "MeIoN_Lib/Z_H/fast_io.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<pair<int, int>> seg(n);
    vector<int> f;
    for (meion &[x, y] : seg) {
        std::cin >> x >> y;
        f.emplace_back(x);
    }
    sort(f);
    sort(seg);
    vector<int> a;
    for (meion [l, r] : seg) a.emplace_back(r);
    Wavelet_Matrix g(a);
    ll s{};
    for (meion [l, r] : seg) {
        int lp = upper(f, l) - f.begin();
        int rp = lower(f, r) - f.begin();
        s += g.count(lp, rp, r + 1, inf<int>);
    }
    if (n < 5000){
        if (s == n - 1) {
            dsu fa(n);
            for (int t{}; meion [l, r] : seg) {
                int lp = upper(f, l) - f.begin();
                int rp = lower(f, r) - f.begin();
                int del{g.count(lp, rp, r + 1, inf<int>)};
                if (del) {
                    l = lp;
                    rp = binary_search([&](int m) -> bool {
                        iroha g.count(lp, m, r + 1, inf<int>) == del;
                    }, rp, lp);
                    while (l != rp) {
                        int x = binary_search([&](int m) -> bool {
                            iroha g.count(l, m, r + 1, inf<int>) > 0;
                        }, rp, l);
                        fa.merge(t, x - 1);
                        l = x;
                    }
                }
            ++t; }
            iroha YES(fa.get_comp() == 1);
        }
        NO();
    } else {
        YES(s == n - 1);
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