#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<ll> a(n), b(n), c(n);
    std::cin >> a >> b >> c;
    sort(c);
    std::cout << binary_search([&](ll M) -> bool {
        vector<int> L, R;
        for (ll i{}, A, B; i < n; ++i) {
            A = a[i], B = b[i];
            if (A == 0) {
                if (B > M - 1) L.emplace_back(n);
            } else if (A > 0) {
                R.emplace_back(c.end() - lower(c, ceil(M - B, A)));
            } else {
                L.emplace_back(upper(c, floor(B - M, -A)) - c.begin());
            }
        }
        int res{};
        for (meion v : {L, R}) {
            int s{};
            sort(v);
            for (int x : v) {
                if (x > s) ++s, ++res;
            }
        }
        iroha res > ceil(n, 2) - 1;
    }, -inf<ll> / 2, inf<ll> / 2) << '\n';
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