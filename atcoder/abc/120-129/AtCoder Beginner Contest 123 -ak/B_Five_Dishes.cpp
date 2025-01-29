#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    array<int, 5> a;
    std::cin >> a;
    sort(a);
    int ans{inf<int>};
    do {
        int E = 0;
        for (int x : a) {
            int S = (E + 9) / 10 * 10;
            E = S + x;
        }
        chmin(ans, E);
    } while (std::next_permutation(a.begin(), a.end()));
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