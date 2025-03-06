#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    string s;
    std::cin >> s;
    const int n = len(s);
    vector<int> c(10);
    for (int i{}, x; i < n - 1; ++i) {
        x = s[i + 1] - s[i];
        if (x < 0) x += 10;
        ++c[x];
    }
    
    vector ans(10, array<int, 10>{});
    for (int x{}; x < 10; ++x) {
        for (int y{}; y < 10; ++y) {
            vector<int> d(10, inf<int>);
            for (int i{}; i < 10; ++i) {
                for (int k{}; k < 10; ++k) {
                    if (i == -k) continue;
                    chmin(d[(x * i + y * k) % 10], i + k - 1);
                }
            }
            for (int i{}; i < 10; ++i) {
                if (c[i] and d[i] == inf<int>) {
                    ans[x][y] = -1;
                    break;
                }
                ans[x][y] += c[i] * d[i];
            }
        }
    }
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