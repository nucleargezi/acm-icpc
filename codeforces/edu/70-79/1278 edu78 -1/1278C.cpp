#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> a(n << 1);
    for (int &x : a) {
        std::cin >> x;
        x = (x == 2 ? -1 : 1);
    }
    vector<int> l{a.begin(), a.begin() + n}, r{a.begin() + n, a.end()};
    reverse(r);
    l = pre_sum(l);
    r = pre_sum(r);
    vector<int> L(n << 1 | 1, inf<int> / 2), R(L);
    for (int i{}; i < n + 1; ++i) chmin(L[n + l[i]], n - i);
    for (int i{}; i < n + 1; ++i) chmin(R[n - r[i]], n - i);
    int ans{inf<int>};
    for (int i{}; i < (n << 1 | 1); ++i) {
        chmin(ans, L[i] + R[i]);
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