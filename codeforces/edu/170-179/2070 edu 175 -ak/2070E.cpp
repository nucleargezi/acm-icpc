#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    string s;
    std::cin >> n >> s;
    vector a = s_to_vec(s, '0');
    for (int &x : a) x = x ? -3 : 1;

    ll ans{};
    Seg<monoid_add<int>> seg(n << 2 + 3);
    for (int x : pre_sum(a)) {
        x += n * 3 + 1;
        ans += seg.prod(0, x + 2) - seg.prod(x - 1, x + 1);
        seg.apply(x, 1);
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