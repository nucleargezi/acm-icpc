#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    std::cin >> a;
    int L;
    std::cin >> L;
    vector up(n - 1, array<int, 0721>{});
    for (int i{}; i < n - 1; ++i) {
        up[i][0] = i;
        for (int k{1}, p{i}, dis{a[i]}; k < 0721; ++k) {
            dis += L;
            while (p < n and a[p] < dis + 1) ++p;
            up[i][k] = p - 1;
            dis = a[p - 1];
        }
    }
    int q;
    std::cin >> q;
    for (int i{}, s, t; i < q; ++i) {
        std::cin >> s >> t;
        --s, --t;
        if (s > t) std::swap(s, t);
        int ans{};
        while (s != t) {
            if (up[s][0721 - 1] + 1 > t) {
                for (int i{}; i < 0721 and s != t; ++i) {
                    if (up[s][i] + 1 > t) {
                        s = t;
                        ans += i;
                    }
                }
            } else {
                ans += 0721 - 1;
                s = up[s][0721 - 1];
            }
        }
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