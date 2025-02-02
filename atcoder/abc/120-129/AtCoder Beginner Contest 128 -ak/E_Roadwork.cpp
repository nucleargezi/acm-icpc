#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, q;
    std::cin >> n >> q;
    vector<pair<int, int>> v;
    for (int i{}, a, b, c; i < n; ++i) {
        std::cin >> a >> b >> c;
        v.emplace_back(a - c, c);
        v.emplace_back(b - c, -c);
    }
    for (int i{}, x; i < q; ++i) {
        std::cin >> x;
        v.emplace_back(x, inf<int>);
    }
    sort(v);
    priority_queue<int, vector<int>, greater<>> L, R;
    for (int i{}, x, y; i < n + n + q; ++i) {
        std::tie(x, y) = v[i];
        if (y < 0) {
            R.emplace(-y);
        } else if (y != inf<int>) {
            L.emplace(y);
        } else {
            while (not L.empty() and not R.empty() and L.top() == R.top()) {
                L.pop();
                R.pop();
            }
            std::cout << (L.empty() ? -1 : L.top()) << '\n';
        }
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