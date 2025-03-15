#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/Basic.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/geo/1-base.hpp"

void before() {}

// #define tests
using mint = modint<mod17>;
NAME MeIoN_is_UMP45() {
    INT(n, m, q);
    q -= n - 1;
    graph<ll, false> v(n);
    v.read_graph<true>(m);

    vector dp(n, -inf<ll>), ndp(dp);
    dp[0] = 0;
    mint ans;
    FOR(i, n - 1) {
        fill(ndp, -inf<ll>);
        FOR(f, n) {
            if (dp[f] == -inf<ll>) continue;
            for (meion [a, t, w, id] : v[f]) {
                chmax(ndp[t], dp[f] + w);
            }
        }
        dp.swap(ndp);
        ans += qmax(dp);
    }

    vector<pair<ll, ll>> lines(m);
    for (int i{}; meion [f, t, c, id] : v.edges) {
        lines[i++] = {c, MAX(dp[f], dp[t])};
    }

    FOR(i, m) {
        meion [K, B] = lines[i];
        ll l{1}, r{q + 1};
        FOR(k, m) {
            if (i == k) continue;
            meion [KK, BB] = lines[k];
            if (K > KK) { // left
                chmax(l, (ll)line_x_line(line(K, B), line(KK, BB)).x + 1);
            } else if (K < KK) { // right
                chmin(r, (ll)line_x_line(line(K, B), line(KK, BB)).x + 1);
            } else {
                if (B > BB or (B == BB and i < k)) continue;
                l = r;
            }
        }
        if (l < r)
            ans += mint(r - l) * (mint(K) * (l + r - 1) / 2 + B);
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