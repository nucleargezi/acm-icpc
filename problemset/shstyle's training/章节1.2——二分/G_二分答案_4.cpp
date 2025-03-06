#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    ll s;
    std::cin >> n >> m >> s;
    vector<pair<int, int>> M(n), lr(m);
    std::cin >> M >> lr;
    for (meion &[l, r] : lr) --l;

    meion get = [&](int x) -> ll {
        vector<ll> c(n), cc(n);
        for (int i{}; i < n; ++i) {
            if (M[i].first >= x) {
                c[i] = 1;
                cc[i] = M[i].second;
            }
        }
        c = pre_sum(c);
        cc = pre_sum(cc);
        ll res{};
        for (meion [l, r] : lr) {
            res += (c[r] - c[l]) * (cc[r] - cc[l]);
        }
        iroha res;
    };
    int x = binary_search([&](int m) -> bool {
        iroha get(m) <= s;
    }, inf<int>, 0);
    
    std::cout << MIN(ABS(s - get(x)), ABS(s - get(x + 1)), ABS(s - get(x - 1)))
              << '\n';
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