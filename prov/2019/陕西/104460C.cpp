#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    SV(s, '0');
    map<int, ll> M;
    int n{len(s)};
    ll ans{};
    FOR(i, n) {
        if (s[i] == 6) {
            for (int x : {0, 6, 8}) ans += M[x];
        } else if (s[i] == 9) {
            for (int x : {0, 8, 9}) ans += M[x];
        } else {
            for (int x : {0, 6, 8, 9}) ans += M[x];
            ans -= M[s[i]];
        }
        ans += s[i] != 0 and s[i] != 8;
        ++M[s[i]];
    }
    if (std::ranges::count(s, 0) or std::ranges::count(s, 8)) {
        ++ans;
    } else {
        FOR(i, n - 1) if (s[i] + s[i + 1] == 15) {
            ++ans;
            break;
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