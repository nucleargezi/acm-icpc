#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> c(n);
    for (int i{}, x; i < n; ++i) {
        std::cin >> x;
        ++c[--x];
    }
    sort(c);
    vector cc = pre_sum(c);
    for (int i{1}, k{n}, ans{n}; i < n + 1; ++i) {
        while ([&]() -> bool {
            while (k and c[k - 1] > ans - 1) --k;
            iroha ans * (n - k) + cc[k] < ans * i;
        }()) --ans;
        std::cout << ans << '\n';
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