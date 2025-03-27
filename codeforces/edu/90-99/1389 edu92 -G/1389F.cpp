#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    vector<tuple<ll, ll, ll>> a(n);
    for (meion &[l, r, w] : a) {
        IN(l, r, w);
        std::swap(l, r);
        --w;
    }
    sort(a);

    int ans{n};
    multiset<ll> se[2];
    for (meion [r, l, w] : a) {
        if (se[not w].lower_bound(l) == se[not w].end()) {
            se[w].emplace(r);
        } else {
            --ans;
            se[not w].extract(se[not w].lower_bound(l));
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