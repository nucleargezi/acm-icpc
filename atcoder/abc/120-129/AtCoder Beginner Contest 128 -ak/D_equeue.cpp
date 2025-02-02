#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, k;
    std::cin >> n >> k;
    vector<int> a(n);
    std::cin >> a;
    int ans{-inf<int>};
    for (int l{}; l < k + 1; ++l) {
        for (int r{}; r + l < k + 1; ++r) {
            if (l + r > n) continue;
            int THROW = k - l - r;
            vector<int> v{a.begin(), a.begin() + l};
            v.insert(v.end(), a.rbegin(), a.rbegin() + r);
            sort(v);
            int s{qsum(v, 0ll)};
            for (int i{}; i < l + r and i < THROW; ++i) {
                s += v[i] < 0 ? -v[i] : 0;
            }
            chmax(ans, s);
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