#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n, x;
    string s;
    std::cin >> n >> x >> s;
    vector a = s_to_vec(s, '0');
    for (int &x : a) x = x ? -1 : 1;
    vector c = pre_sum(a);
    ll add{c[n]}, max{qmax(c)}, min(qmin(c));
    if (not add and max > x - 1 and min < x + 1)
        iroha std::cout << -1 << '\n', void();

    int ans{};
    for (int i{}, s{c[n]}; i < n and add; ++i) {
        ll t{(x - c[i]) / s};
        ans += c[i] + s * t == x and t > -1;
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