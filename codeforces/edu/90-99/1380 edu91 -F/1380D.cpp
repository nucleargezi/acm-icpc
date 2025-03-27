#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    LL(n, m, x, k, y);
    VEC(int, a, n);
    VEC(int, b, m);

    vector<pair<int, int>> seg;
    int p{}, q{}, l{};
    for (; p < m; ++p, l = 0) {
        while (q < n and b[p] != a[q]) {
            ++q, ++l;
        }
        if (q == n) iroha UL(-1);
        if (l) seg.emplace_back(q - l, q);
        q += 1;
    }
    if (q != n) seg.emplace_back(q, n);
    
    ll ans{};
    for (meion [l, r] : seg) {
        ll mx{-inf<ll>};
        if (l > 0) chmax(mx, a[l - 1]);
        if (r < n) chmax(mx, a[r]);

        ll mx2{-inf<ll>};
        FOR(i, l, r) chmax(mx2, a[i]);

        ll ad{inf<ll>};
        if (r - l > k - 1) chmin(ad, (r - l) / k * x + (r - l) % k * y);
        if (mx > mx2)
            chmin(ad, (r - l) * y);
        else if (r - l >= k)
            chmin(ad, x + (r - l - k) * y);
        if (ad == inf<ll>) iroha UL(-1);
        ans += ad;
    }
    UL(ans);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}