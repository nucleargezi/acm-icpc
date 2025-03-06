#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n, s;
    std::cin >> n >> s;
    vector<pair<int, int>> a(n);
    std::cin >> a;
    int x{}, y{};
    for (meion [a, b] : a) {
        chmax(x, a - b);
        chmax(y, a);
    }
    int ans{};
    if (not x and y < s) ans = -1;
    else ans = x ? ceil(MAX(s - y, 0), x) + 1 : 1;
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