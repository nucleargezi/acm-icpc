#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<ll> a(n);
    std::cin >> a;
    ll ans = qsum(a, 0ll);
    while (a.size() > 1) {
        vector b = a, c = a;
        rev(c);
        for (int i = 1; i < b.size(); ++i) {
            b[i - 1] = b[i] - b[i - 1];
        }
        for (int i = 1; i < c.size(); ++i) {
            c[i - 1] = c[i] - c[i - 1];
        }
        b.pop_back(), c.pop_back();
        ll sb = qsum(b, 0ll), sc = qsum(c, 0ll);
        a = (chmax(sb, sc) ? b : c);
        chmax(ans, sb);
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