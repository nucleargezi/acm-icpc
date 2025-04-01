#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(x, y);
    int ans{};
    priority_queue<int> q;
    int a[] = {y, y, y};
    while (a[0] < x) {
        ++ans;
        a[0] = MIN(x, a[1] + a[2] - 1);
        std::sort(a, a + 3);
    }
    UL(ans);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}


// 0 1 0 0 0 -1
// -> cumsum
// 0 1 1 1 1 0