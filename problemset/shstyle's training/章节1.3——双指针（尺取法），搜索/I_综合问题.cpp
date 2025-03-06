#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/monoid/max.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<int> a(n), b(m);
    std::cin >> a >> b;
    sort(b, greater());
    vector<int> ans;
    int i{}, k{};
    for (; i < n; ++i) {
        while (k < m and b[k] >= a[i]) {
            ans.emplace_back(b[k++]);
        }
        ans.emplace_back(a[i]);
    }
    ans.insert(ans.end(), b.begin() + k, b.end());
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