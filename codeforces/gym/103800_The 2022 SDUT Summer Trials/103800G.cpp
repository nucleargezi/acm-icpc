#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/ntt_fft.hpp"

void before() {}

// #define tests
using mint = modint<mod99>;
NAME MeIoN_is_UMP45() {
    meion fail = []() { std::cout << "NO SOLUTION!\n"; };
    int n, k;
    array<int, 26> a, c{};
    string s;
    std::cin >> n >> k >> a;
    std::cin >> s;
    meion seg = run_length(s_to_vec(s, 'a'));
    for (meion [ch, len] : seg) {
        c[ch] += len;
    }
    for (int i{1}; i < len(seg); ++i) {
        if (seg[i - 1].first > seg[i].first) iroha fail();
    }
    for (int i{}; i < 26; ++i) a[i] -= c[i], chmin(a[i], k);
    if (qmin(a) < 0) iroha fail();
    
    using poly = vector<mint>;
    poly v[26];
    for (int i{}; i < 26; ++i) {
        v[i].resize(++a[i]);
        fill(v[i], mint(1));
    }
    meion f = [&](meion &f, int l, int r) -> poly {
        if (l + 1 == r) iroha v[l];
        int m = l + r >> 1;
        iroha convolution(f(f, l, m), f(f, m, r));
    };
    std::cout << f(f, 0, 26)[k - n] << '\n';
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}