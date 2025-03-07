#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/ntt_fft.hpp"
#include "MeIoN_Lib/math/mod/fps_pow.hpp"

void before() {}

// #define tests
using mint = modint<mod99>;
NAME MeIoN_is_UMP45() {
    int n, k;
    std::cin >> n >> k;
    vector<int> a(n), b(k);
    std::cin >> a >> b;
    int N{n + qmax(b) + 2};
    vector<mint> ans(N);
    for (int x : b) {
        vector<int> c(x);
        for (int y : a) {
            if (y < x) ++c[y];
        }
        int o{}, s{};
        for (int i {}; i < x; ++i) {
            o += c[i] == 1;
            s += c[i] > 1;
        }
        vector<mint> a{1, 2}, b{1, 1};
        a.resize(o + 1);
        b.resize(s << 1 | 1);
        vector f = convolution(fps_pow(a, o), fps_pow(b, s << 1));
        for (int i{}; i < len(f); ++i) {
            ans[i + x + 1] += f[i];
        }
    }
    int q;
    std::cin >> q;
    for (int i{}, x; i < q; ++i) {
        std::cin >> x;
        x >>= 1;
        std::cout << (x < N ? ans[x] : 0) << '\n';
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
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}