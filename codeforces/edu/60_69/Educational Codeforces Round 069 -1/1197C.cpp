#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, K;
    std::cin >> n >> K;
    vector<int> a(n);
    std::cin >> a;
    int ans{a[n - 1] - a[0]};
    for (int i{}; i < n - 1; ++i) {
        a[i] = a[i + 1] - a[i];
    }
    a.pop_back();
    sort(a, greater());
    for (int i{}; i < K - 1; ++i) {
        ans -= a[i];
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