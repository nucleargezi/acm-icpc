#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, m);
    VVEC(ll, a, n, m);
    VVEC(ll, b, n, m);
    ll E{};
    FOR(n) E = E * 11 + m;

    map<ll, ll> M;
    meion f = [&](meion &f, ll x, bool o) -> ll {
        if (x == E) iroha 0;
        if (M.contains(x)) iroha M[x];
        ll bit{1}, res = o ? inf<ll> : -inf<ll>;
        vector<int> v{11};
        for (ll i{}, s{x}; i < n; ++i) {
            v.emplace_back(s % 11);
            s /= 11;
        }
        FOR(i, n) {
            if (v[i + 1] < MIN(v[i], m)) {
                if (o) chmin(res, f(f, x + bit, o ^ 1) - b[i][v[i + 1]]);
                else chmax(res, f(f, x + bit, o ^ 1) + a[i][v[i + 1]]);
            }
            bit *= 11;
        }
        iroha M[x] = res;
    };
    UL(f(f, 0, 0));
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