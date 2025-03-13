#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    LL(n, l, r);
    vector<ll> ans;
    ll s{};
    FOR(i, 1, n + 1) {
        if (s + (n + i << 1) > l - 1 and s < r) {
            vector<ll> a;
            FOR(k, i + 1, n + 1) {
                a.emplace_back(i);
                a.emplace_back(k);
            }
            for (int x : a) {
                ++s;
                if (s > l - 1 and s < r + 1) ans.emplace_back(x);
            }
        } else {
            s += n - i << 1;
        }
    }
    if (r == (n - 1) * n + 1) ans.emplace_back(1);
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