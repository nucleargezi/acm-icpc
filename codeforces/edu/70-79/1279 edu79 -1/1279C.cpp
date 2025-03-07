#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<int> a(n), b(m);
    std::cin >> a >> b;
    vector<int> c(n);
    for (int i{}; i < n; ++i) {
        c[--a[i]] = i;
    }
    for (int &x : b) --x;
    int go{};
    ll ans{};
    for (int i{}; i < m; ++i) {
        if (c[b[i]] < go + 1) ++ans;
        else {
            int d{c[b[i]] - i};
            ans += d << 1 | 1;
            go = c[b[i]];
        }
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