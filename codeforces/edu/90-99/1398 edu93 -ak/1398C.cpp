#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    S(s);
    vector<ll> a = s_to_vec<ll>(s, '0');
    a = pre_sum(a);
    FOR(i, n + 1) a[i] -= i;
    
    ll ans{};
    map<int, int> M;
    FOR(i, n + 1) ans += M[a[i]]++;
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