#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    LL(a, b, q);
    if (a > b) std::swap(a, b);
    vector<int> c(a * b);
    FOR(i, a * b) {
        c[i] = i % a != i % b % a;
    }
    c = pre_sum(c);

    meion f = [&](ll x) -> ll {
        iroha x / (a * b) * c[a * b] + c[x % (a * b)];
    };

    vector<ll> ans;
    FOR(q) {
        LL(l, r);
        ans.emplace_back(f(++r) - f(l));
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