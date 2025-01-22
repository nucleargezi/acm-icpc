#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    std::cin >> a;
    a.insert(a.begin(), 0);
    a.emplace_back(a[0]);
    int s{};
    for (int i{1}; i < n + 2; ++i) {
        s += ABS(a[i] - a[i - 1]);
    }
    for (int i{1}; i < n + 1; ++i) {
        std::cout << s - ABS(a[i + 1] - a[i]) - ABS(a[i] - a[i - 1]) +
                         ABS(a[i - 1] - a[i + 1])
                  << '\n';
    }
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