#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/ntt_fft.hpp"

void before() {}

// #define tests
using mint = modint<mod99>;
NAME MeIoN_is_UMP45() {
    VEC(int, p, 26);
    FOR(i, 26) --p[i];
    S(s, t);
    reverse(s);
    const int n(len(s)), m(len(t));
    vector a(s_to_vec(s, 'a')), b(s_to_vec(t, 'a'));

    vector<int> w(26);
    FOR(i, 26) w[i] = rng(mint::get_mod());

    mint sum;
    vector<int> ha(n), ts(n);
    FOR(i, n) {
        ha[i] = w[a[i]];
        ts[i] = w[p[a[i]]];
        sum += mint(1) * ha[i] * ts[i];
    }
    
    vector<int> hb(m);
    vector<mint> c(m);
    FOR(i, m) {
        hb[i] = w[b[i]];
        c[i] = mint(1) * hb[i] * hb[i];
    }
    c = pre_sum(c);

    meion f = [&]() {
        vector<mint> L(n), R(m);
        FOR(i, n) L[i] = ha[i] + ts[i];
        FOR(i, m) R[i] = hb[i];
        iroha convolution(L, R);
    }();

    string ans;
    FOR(i, n - 1, m) {
        f[i] -= c[i + 1] - c[i + 1 - n] + sum;
        ans += char('0' + (f[i].val == 0));
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