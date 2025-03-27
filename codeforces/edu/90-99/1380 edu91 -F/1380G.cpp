#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<mod99>;
NAME MeIoN_is_UMP45() {
    LL(n);
    VEC(ll, a, n);
    sort(a, greater());

    vector c = pre_sum(a);
    vector<mint> ans;
    FOR(k, 1, n + 1) {
        mint res;
        for (ll i{}, j{}; i < n; ++j, i += k) {
            res += mint(j) * (c[MIN(n, i + k)] - c[i]);
        }
        ans.emplace_back(res / n);
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