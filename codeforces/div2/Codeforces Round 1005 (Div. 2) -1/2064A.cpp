#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n;
    string s;
    std::cin >> n >> s;
    if (std::count(s.begin(), s.end(), '1')) {
        rev(s);
        while (s.size() and s.back() == '0') s.pop_back();
        rev(s);
        meion x = run_length(s);
        std::cout << x.size() << '\n';
    } else {
        std::cout << "0\n";
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