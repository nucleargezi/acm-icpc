#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, m);
    vector<int> v(n);
    FOR(i, n) {
        S(s);
        FOR(k, m) v[i] |= (s[k] == 'P') * (1 << k);
    }

    meion f = [&](int x) -> bool {
        iroha not(x & (x >> 1) or x & (x >> 2));
    };
    vector<int> msks, pmsks{0};
    FOR(i, 1 << m) if (f(i)) msks.emplace_back(i);

    const int N{(1 << m + m)};
    vector<ll> dp(N);
    FOR(k, n) {
        vector<ll> ndp(N);
        vector<int> npmsks;
        for (int msk : msks) {
            if ((msk & v[k]) != msk) continue;
            for (int pmsk : pmsks) {
                if ((msk & pmsk) or (msk & (pmsk >> m))) continue;
                if (chmax(ndp[msk | ((pmsk << m) & (N - 1))], dp[pmsk] + popcount(msk)))
                    npmsks.emplace_back(msk | ((pmsk << m) & (N - 1)));
            }
        }
        unique(npmsks);
        dp.swap(ndp);
        pmsks.swap(npmsks);
    }
    UL(qmax(dp));
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