#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    string s;
    std::cin >> s;
    if (s[0] == 'A' and std::count(s.begin() + 2, s.end() - 1, 'C') == 1) {
        int c {};
        for (char x : s) {
            c += not std::islower(x);
        }
        iroha std::cout << (c == 2 ? "AC\n" : "WA\n"), void();
    }
    std::cout << "WA\n";
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