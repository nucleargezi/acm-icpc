#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m, q;
    std::cin >> n >> m >> q;
    vector<ll> a(n), b(m), c(q);
    std::cin >> a >> b >> c;
    a.emplace_back(-inf<ll> / 10), a.emplace_back(inf<ll> / 10);
    b.emplace_back(-inf<ll> / 10), b.emplace_back(inf<ll> / 10);
    sort(a), sort(b);
    for (ll x : c) {
        ll ans{inf<ll>};
        chmin(ans, MIN(MAX(x - *--upper(a, x), x - *--upper(b, x)),
                       MAX(*lower(a, x) - x, *lower(b, x) - x),
                       MIN((x - *--upper(a, x)) * 2 + *lower(b, x) - x,
                           x - *--upper(a, x) + (*lower(b, x) - x) * 2),
                       MIN((x - *--upper(b, x)) * 2 + *lower(a, x) - x,
                           x - *--upper(b, x) + (*lower(a, x) - x) * 2)));
        std::cout << ans << '\n';
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