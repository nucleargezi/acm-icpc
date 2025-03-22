#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    VEC(ll, a, 4);
    VEC(char, op, 3);
    
    meion f = [&](ll x, ll y, char op) -> ll {
        if (op == '+') iroha x + y;
        iroha x * y;
    };

    ll ans{inf<ll>};
    vector<int> I(4);
    std::iota(I.begin(), I.end(), 0);
    do {
        vector<ll> b{f(a[I[0]], a[I[1]], op[0]), a[I[2]], a[I[3]]};
        vector<int> I(3);
        std::iota(I.begin(), I.end(), 0);
        do {
            chmin(ans, f(f(b[I[0]], b[I[1]], op[1]), b[I[2]], op[2]));
        } while (std::next_permutation(I.begin(), I.end()));
    } while (std::next_permutation(I.begin(), I.end()));
    
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