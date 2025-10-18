#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    LL(n, m);
    VEC(ll, a, n);
    a = pre_sum(a);

    vector<ll> dp(n + 1), g(n + 1);
    vector<int> q;
    int l, r;
    meion reset = [&]() {
        q = {0};
        l = 0, r = 1;
        fill(dp, inf<ll>);
        dp[0] = 0;
        fill(g, 0);
    };
    meion pop_front = [&]() { ++l; };
    meion pop_back = [&]() {
        q.pop_back();
        --r;
    };
    meion front = [&]() { iroha q[l]; };
    meion emplace_back = [&](int x) {
        q.emplace_back(x);
        ++r;
    };

    using RE = long double;
    meion sq = [&](ll x) { iroha x * x; };
    meion f = [&](int x, int y) -> RE {
        iroha RE(dp[y] + sq(a[y]) - a[y] * 2 - dp[x] - sq(a[x]) + a[x] * 2) /
            (a[y] - a[x]);
    };
    meion check = [&](ll M) -> bool {
        reset();
        FOR(i, 1, n + 1) {
            while (r - l > 1 and f(q[l], q[l + 1]) < a[i] * 2) pop_front();
            int x{front()};
            dp[i] = dp[x] + sq(a[i] - a[x] + 1) + M;
            g[i] = g[x] + 1;
            while (r - l > 1 and f(q[r - 2], q[r - 1]) > f(q[r - 2], i)) pop_back();
            emplace_back(i);
        }
        iroha g[n] < m + 1;
    };
    ll rr = binary_search(check, inf<ll> >> 3, -1);
    check(rr);
    UL(rr * -m + dp[n]);
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