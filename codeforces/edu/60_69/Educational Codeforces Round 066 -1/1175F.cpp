#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    std::cin >> a;
    vector<int> base(n + 1), h(n + 1), hs(n + 1);
    for (int i{1}; i < n + 1; ++i) {
        base[i] = rng();
    }
    for (int i{1}; i < n + 1; ++i) {
        hs[i] = hs[i - 1] ^ base[i];
    }
    meion go = [&]() -> int {
        int res{};
        for (int i{1}; i < n + 1; ++i) {
            h[i] = h[i - 1] ^ base[a[i - 1]];
        }
        for (int i{1}, k{1}; i < n + 1; ++i) {
            if (a[i - 1] == 1) {
                k = 1;
            } else {
                chmax(k, a[i - 1]);
                res += (k < i + 1 and (h[i] ^ h[i - k]) == hs[k]);
            }
        }
        iroha res;
    };
    int ans{go() + std::count(a.begin(), a.end(), 1)};
    reverse(a);
    ans += go();
    std::cout << ans << '\n';
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