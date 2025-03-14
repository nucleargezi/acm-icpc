#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    INT(n, K);
    using P = pair<int, int>;
    VEC(P, a, n);
    FOR(i, n) std::swap(a[i].first, a[i].second);
    meion rk = argsort(a);
    FOR(i, n) std::swap(a[i].first, a[i].second);

    vector dp(n + 1, vector<ll>(K + 1, -inf<ll>));
    vector fa(n + 1, vector<int>(K + 1, -1));
    dp[0][0] = 0;
    FOR(i, n) {
        meion [x, y] = a[rk[i]];
        FOR(k, K + 1) {
            if (chmax(dp[i + 1][k], dp[i][k] + (K - 1) * y)) fa[i + 1][k] = k;
        }
        FOR(k, K) {
            if (chmax(dp[i + 1][k + 1], dp[i][k] + x + k * y))
                fa[i + 1][k + 1] = k;
        }
    }

    vector<int> L, R;
    int p{K};
    FOR_R(i, n) {
        (fa[i + 1][p] != p ? L : R).emplace_back(rk[i]);
        p = fa[i + 1][p];
    }
    vector<int> ans;
    for (reverse(L); int x : L) {
        ans.emplace_back(++x);
    }
    ans.pop_back();
    for (reverse(R); int x : R) {
        ans.emplace_back(++x);
        ans.emplace_back(-x);
    }
    ans.emplace_back(++L.back());
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