#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/heap.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    std::cin >> a;
    heap<int> q;
    for (int i : a) {
        q.emplace(i);
    }
    for (int i : a) {
        q.pop(i);
        std::cout << q.top() << '\n';
        q.emplace(i);
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