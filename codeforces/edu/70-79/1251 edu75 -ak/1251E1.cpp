#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<pair<int, int>> a(n);
    vector<vector<int>> v(n);
    for (int t{}; meion &[x, y] : a) {
        std::cin >> x >> y;
        v[x].emplace_back(t++);
    }
    priority_queue<ll, vector<ll>, greater<>> q;
    ll ans{};
    for (int i{n}, c{}; i--; ) {
        n -= len(v[i]);
        for (int x : v[i]) {
            q.emplace(a[x].second);
        }
        while (c < i - n) {
            ++c;
            ans += q.top();
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