#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    LL(n, T, a, b);
    vector<pair<ll, ll>> prob(n);
    ll easy{}, hard{};
    FOR(i, n) {
        IN(prob[i].second);
        (prob[i].second ? hard : easy) += 1;
    }
    FOR(i, n) IN(prob[i].first);
    sort(prob);

    vector<ll> ts{T};
    FOR(i, n) ts.emplace_back(prob[i].first - 1);
    unique(ts);

    ll ez{}, hd{}, k{}, ans{};
    meion f = [&](ll lst, ll ez, ll hd) -> ll {
        ll res = MIN(lst / a, ez);
        lst -= res * a;
        iroha res + MIN(hd, lst / b);
    };
    for (ll t : ts) {
        ll cp = k;
        while (k < n and prob[k].first < t + 1) {
            (prob[k].second ? hd : ez) += 1;
            ++k;
        }
        if (ez * a + hd * b > t) {
            continue;
        } else {
            chmax(ans, k + f(t - ez * a - hd * b, easy - ez, hard - hd));
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