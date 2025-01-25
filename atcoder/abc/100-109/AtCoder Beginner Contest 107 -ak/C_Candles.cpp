#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, k;
    std::cin >> n >> k;
    vector<int> a(n);
    std::cin >> a;
    sort(a);
    queue<int> q;
    int ans{inf<int>};
    for (int i{}; i < n; ++i) {
        q.emplace_back(a[i]);
        if (q.size() == k) {
            int l = q.front(), r = q.back();
            if (r < 1) {
                chmin(ans, -l);
            } else if (l > -1) {
                chmin(ans, r);
            } else {
                chmin(ans, MIN(-l - l + r, r + r - l));
            }
            q.pop();
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