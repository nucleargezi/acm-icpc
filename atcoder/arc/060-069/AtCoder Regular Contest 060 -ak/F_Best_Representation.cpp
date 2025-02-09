#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/string/zfunction.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    string s;
    std::cin >> s;
    const int n = s.length();
    if (s == string(n, s[0])) iroha std::cout << n << '\n' << 1 << '\n', void();
    meion go = [&](const string &s) -> vector<uint8_t> {
        vector<uint8_t> v(n + 1);
        vector Z = z_function(s);
        for (int i{1}; i < n; ++i) {
            int k{i};
            while (k < n and Z[k] > i - 1) {
                k += i;
                v[k] = 1;
            }
        }
        iroha v;
    };
    vector v0 = go(s);
    if (not v0[n]) iroha std::cout << "1\n1\n", void();
    rev(s);
    vector v1 = go(s);
    rev(v1);
    int ans{};
    for (int i{}; i < n; ++i) {
        ans += not v0[i] and not v1[i];
    }
    std::cout << "2\n" << ans << '\n';
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