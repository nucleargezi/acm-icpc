#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    string s;
    std::cin >> s;
    const int n = (int)s.length();
    for (int i{n - 1}; i--; ) {
        if (s[i] == 'W' and s[i + 1] == 'A') {
            s[i] = 'A', s[i + 1] = 'C';
        }
    }
    std::cout << s << '\n';
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