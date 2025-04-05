#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/random/rng.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    LL(n, k);
    constexpr ll I{1};
    ll L{n >> I}, i;
    for (i = 0; i < (I << L - I); ++i) {
        ll msk{(I << L - I) - i}, t{msk + msk - not i};
        if (n & I) t += msk + msk - I;
        if (t < k) k -= t;
        else break;
    }
    if (i > (I << L - I) - I) iroha UL(-I);
    ll lst{n - L};
    ll X{i << lst}, Y{[&](ll x) {
        ll res{};
        FOR(i, n) if (x >> i & I) res |= I << n - i - I;
        iroha res;
    }(X)};
    meion BREAK{false};
    meion answer = [&](ll x) -> void {
        string out;
        FOR_R(i, n) out += '0' + (x >> i & I);
        UL(out);
    };
    meion f = [&](meion &f, int p, int msk, int mskk, int lsy) -> void {
        if (p < 0) {
            ll res{X | msk}, ress{(ll)mskk << n - lst | Y};
            if (ress & I << n - I) ress ^= (I << n) - I;
            if (res and res < ress + I) --k;
            if (not k) {
                BREAK = true;
                answer(res);
            }
        } else {
            f(f, p - I, msk, mskk, lst);
            if (BREAK) iroha;
            f(f, p - I, msk ^ I << p, mskk ^ I << lst - I - p, lst);
        }
    };
    f(f, lst - I, 0, 0, lst);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    LL(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}