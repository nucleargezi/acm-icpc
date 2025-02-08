#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> m(n + 1);
    vector<int> L(n + 2), R(n + 2);
    for (int i{1}, x; i < n + 1; ++i) {
        std::cin >> x;
        m[x] = i;
        L[i] = i - 1;
        R[i] = i + 1;
    }
    ll ans{};
    for (int i{}; i < n; ++i) {
        int l = L[m[i + 1]], r = R[m[i + 1]];
        if (l > 0) ans += ll(i + 1) * (l - L[l]) * (r - m[i + 1]);
        if (r < n + 1) ans += ll(i + 1) * (R[r] - r) * (m[i + 1] - l);
        L[r] = l, R[l] = r;
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