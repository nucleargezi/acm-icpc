#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    ll n, s;
    std::cin >> n >> s;
    vector<int> l(n), r(n);
    for (int i{}; i < n; ++i) {
        std::cin >> l[i] >> r[i];
    }
    std::cout << binary_search([&](int m) -> bool {
        ll c{};
        vector<int> v;
        for (int i{}; i < n; ++i) {
            c += l[i];
            if (r[i] > m - 1) {
                v.emplace_back(MAX(m - l[i], 0));
            }
        }
        sort(v);
        if (len(v) < ceil(n, 2)) iroha false;
        for (int i{}; i < ceil(n, 2); ++i) c += v[i];
        iroha c < s + 1;
    }, 0, qmax(r) + 1) << '\n';
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