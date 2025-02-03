#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, d;
    std::cin >> n >> d;
    vector points(n, vector<int>(d));
    std::cin >> points;
    meion square = [&](int x) -> int { iroha x * x; };
    meion is_pref = [&](int x) -> int {
        int sqr = std::sqrt(x);
        iroha square(sqr) == x;
    };
    int ans{};
    for (int i{}; i < n; ++i) {
        for (int k = i + 1; k < n; ++k) {
            int dis{};
            for (int j{}; j < d; ++j) {
                dis += square(std::abs(points[i][j] - points[k][j]));
            }
            ans += is_pref(dis);
        }
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