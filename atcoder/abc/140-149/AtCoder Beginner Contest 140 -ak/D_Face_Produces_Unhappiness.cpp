#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, k;
    string s;
    std::cin >> n >> k >> s;
    int x{}, y{};
    for (int i{1}; i < n; ++i) {
        x += s[i] == s[i - 1];
    }
    for (int i{1}; i < n; ++i) {
        y += s[i] != s[i - 1];
    }
    vector<int> a(ceil(y, 2), 2);
    a.back() -= y & 1;
    sort(a, greater());
    a.resize(k, 0);
    std::cout << x + qsum(a, 0) << '\n';
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