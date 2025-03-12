#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    S(s);
    meion seg = run_length(s_to_vec(s, '0'));
    not s.empty() and not seg[0].first and TRUE(seg.erase(seg.begin()));
    not s.empty() and not seg.back().first and TRUE(seg.erase(--seg.end()));
    int ans{};
    for (meion [x, y] : seg) {
        not x and TRUE(ans += y);
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
    INT(T);
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}