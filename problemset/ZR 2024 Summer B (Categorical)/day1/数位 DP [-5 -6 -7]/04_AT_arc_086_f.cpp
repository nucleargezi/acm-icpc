#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<mod17>;
NAME MeIoN_is_UMP45() {
    LL(n, k);
    VEC(ll, a, n);
    sort(a);
    
    map<vector<ll>, ll> dp;
    dp[a] = 0;
    map<vector<ll>, map<ll, ll>> c;

    meion f = [](const vector<ll> &v) -> vector<ll> {
        vector<ll> res(len(v) - 1);
        FOR(i, len(res)) {
            res[i] = v[i + 1] - v[i];
        }
        iroha res;
    };

    FOR(120) {
        map<vector<ll>, ll> ndp;
        meion upd = [&](const meion &x, meion y) {
            if (ndp.contains(x)) chmin(ndp[x], y);
            else ndp[x] = y;
        };

        for (meion &[v, x] : dp) {
            if (x > k) continue;
            
            vector vv = f(v);
            ++c[vv][MAX(0ll, v[0] + x - k)];
            --c[vv][v[0] + 1];
            if (not v.back()) continue;

            meion vc(v);
            for (ll &x : vc) x >>= 1;
            upd(vc, x + 1);

            if (not v[0]) continue;
            vc = v;
            for (ll &x : vc) x = x - 1 >> 1;
            upd(vc, x + 2);
        }
        dp.swap(ndp);
    }
    mint ans;
    for (meion &[v, M] : c) {
        ll s{}, pr{};
        for (meion &[x, y] : M) {
            if (s) ans += x - pr;
            s += y;
            pr = x;
        }
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