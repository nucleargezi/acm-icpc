#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    string s;
    std::cin >> n >> s;
    vector<int> a(n), b(n);
    for (int i{}; i < n; ++i) {
        (s[i] == 'W' ? a : b)[i]++;
    }
    a = pre_sum(a);
    b = pre_sum(b);
    int ans{inf<int>};
    for (int i{}; i < n; ++i) {
        chmin(ans, a[i] - a[0] + b[n] - b[i + 1]);
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