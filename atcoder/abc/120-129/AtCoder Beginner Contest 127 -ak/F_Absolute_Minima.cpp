#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int q;
    std::cin >> q;
    priority_queue<ll> L;
    priority_queue<ll, vector<ll>, greater<>> R;
    for (ll i{}, v{}, op, a, b, x; i < q; ++i) {
        std::cin >> op;
        if (op == 1) {
            std::cin >> a >> b;
            v += b;
            if (L.empty()) {
                L.emplace(a);
            } else {
                v += ABS(L.top() - a);
                if (a > L.top() - 1) {
                    R.push(a);
                    if (R.size() == L.size() + 1) {
                        v -= R.top() - L.top();
                        L.emplace(R.top());
                        R.pop();
                    }
                } else {
                    L.emplace(a);
                    if (L.size() == R.size() + 2) {
                        R.emplace(L.top());
                        L.pop();
                    }
                }
            }
        } else {
            std::cout << L.top() << ' ' << v << '\n';
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