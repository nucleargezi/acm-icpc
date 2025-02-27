#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n, k;
    std::cin >> n >> k;
    vector<int> a(n);
    vector<uint8_t> vis(n);
    string s;
    std::cin >> s;
    for (int i{}; i < n; ++i) {
        std::cin >> a[i];
        vis[i] = s[i] == 'R';
    }

    std::cout << binary_search([&](int m) -> bool {
        int st{}, s{}, ok{};
        for (int i{}; i < n; ++i) {
            if (a[i] > m) {
                if (vis[i]) {
                    s += st < i and ok;
                    st = i + 1;
                    ok = false;
                } else {
                    ok = true;
                }
            }
        }
        s += st < n and ok;
        iroha s < k + 1;
    }, qmax(a) + 1, -1) << '\n';
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