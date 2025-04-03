#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    vector<ll> a(n), b(n), c(n);
    FOR(i, n) IN(a[i], b[i], c[i]);
    vector<ll> ans, I(n);
    std::iota(I.begin(), I.end(), 0);
    while (not I.empty()) {
        ll id{I[0]};
        ans.emplace_back(id + 1);
        FOR(i, 1, len(I)) c[I[i]] -= MAX(0ll, a[id] - i + 1);
        ll x{};
        FOR(i, len(I)) {
            c[I[i]] -= x;
            if (c[I[i]] < 0) x += b[I[i]];
        }
        c[I[0]] = -1;
        vector<ll> nI;
        for (ll x : I) if (c[x] > -1) nI.emplace_back(x);
        I.swap(nI);
    }
    UL(len(ans));
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