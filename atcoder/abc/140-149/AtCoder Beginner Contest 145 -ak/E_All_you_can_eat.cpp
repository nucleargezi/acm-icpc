#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, T;
    std::cin >> n >> T;
    vector<pair<int, int>> food(n);
    std::cin >> food;
    sort(food);
    vector<ll> dp(T + 1);
    for (meion [cost, val] : food) {
        for (int t{T}; t--; ) {
            chmax(dp[MIN(t + cost, T)], dp[t] + val);
        }
    }
    std::cout << dp[T] << '\n';
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