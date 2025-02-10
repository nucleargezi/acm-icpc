#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    string s;
    std::cin >> s;
    const int n = (int)s.length();
    string x, y;
    for (char c : s) {
        ((c - 'a' + 1 & 1) ? x : y) += c;
    }
    if (x.empty() or y.empty()) iroha std::cout << s << '\n', void();
    sort(x);
    sort(y);
    if (ABS(x.back() - y[0]) != 1) {
        std::cout << x + y << '\n';
    } else if (std::abs(x[0] - y.back()) != 1) {
        std::cout << y + x << '\n';
    } else {
        std::cout << "No answer\n";
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