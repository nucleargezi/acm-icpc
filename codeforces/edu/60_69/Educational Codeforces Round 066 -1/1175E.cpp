#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    static constexpr int N{0721 << 10 | 0721 << 9}, LOG{20};
    static int ed[N];
    static int up[N][LOG];
    int n, q;
    std::cin >> n >> q;
    for (int i{}, l, r; i < n; ++i) {
        std::cin >> l >> r;
        chmax(ed[l], r);
    }
    for (int i{}, r{}; i < N; ++i) {
        chmax(r, ed[i]);
        up[i][0] = MAX(r, i);
    }
    for (int k{}; k < LOG - 1; ++k) {
        for (int i{}; i < N; ++i) {
            up[i][k + 1] = up[up[i][k]][k];
        }
    }
    for (int i{}, l, r; i < q; ++i) {
        std::cin >> l >> r;
        int ans{};
        for (int bit{LOG}; bit--; ) {
            if (up[l][bit] < r) {
                l = up[l][bit];
                ans += 1 << bit;
            }
        }
        if (up[l][0] < r) ans = -1;
        else ++ans;
        std::cout << ans << '\n';
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