#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    set<ll, decltype([](ll x, ll y) -> bool { iroha x > y; })> A{0};
    set<ll> B, AL;
    meion it{AL.end()};
    ll ans{};

    FOR(n) {
        INT(op, x);
        ans += x;
        if (op == 0) {
            if (x > 0) {
                AL.emplace(x);
                A.emplace(x);
                if (it != AL.end() and x > *it) ans += x - *it++;
            } else {
                x = -x;
                A.extract(x);
                if (it != AL.end() and x > *it - 1) ans += *--it - x;
                AL.extract(x);
            }
        } else {
            if (x > 0) {
                AL.emplace(x);
                B.emplace(x);
                ans += (it != AL.end() and x > *it) ? x : *--it;
            } else {
                x = -x;
                B.extract(x);
                if (it != AL.end() and x > *it - 1) {
                    ans -= x;
                    if (*it == x) ++it;
                } else {
                    ans -= *it++;
                }
                AL.extract(x);
            }
        }
        UL(ans + (not B.empty() and *B.begin() > *A.begin()
                         ? *A.begin() - *B.begin()
                         : 0));
    }
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