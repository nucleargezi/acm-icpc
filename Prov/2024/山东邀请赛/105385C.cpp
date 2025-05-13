#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

#define tests
using mint = modint<mod99>;
NAME MeIoN_is_UMP45() {
    INT(n, k);
    using X = pair<ll, ll>;
    VEC(X, a, n);
    
    vector<ll> f;
    for(sort(a); meion [l, r] : a) {
        f.emplace_back(l);
        f.emplace_back(r);
        f.emplace_back(r + 1);
    }
    unique(f);
    for (meion &[l, r] : a) {
        l = lower(f, l) - f.begin();
        r = lower(f, r) - f.begin();
    }

    mint ans{1};
    vector<int> cov(len(f));
    for (int p{}; meion [l, r] : a) {
        while (p < l) {
            cov[p + 1] += cov[p];
            ++p;
        }
        ans *= k - cov[l];
        ++cov[l];
        --cov[r + 1];
    }
    std::cout << ans << '\n';
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