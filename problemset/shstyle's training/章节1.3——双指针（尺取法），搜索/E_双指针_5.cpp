#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    ll n, k;
    std::cin >> n >> k;
    vector<ll> a(n), h(n);
    std::cin >> a >> h;
    a = pre_sum(a);
    vector<int> fail(n - 1);
    for (int i{}; i < n - 1; ++i) {
        fail[i] = h[i] % h[i + 1] != 0;
    }
    fail = pre_sum(fail);
    int ans{};
    for (int l{}; l < n; ++l) {
        chmax(ans, binary_search([&](int m) -> bool {
            if (m == l) iroha true;
            if (a[m] - a[l] > k) iroha false;
            if (fail[m - 1] - fail[l]) iroha false;
            iroha true;
        }, l, n + 1) - l);
    }
    std::cout << ans << '\n';
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