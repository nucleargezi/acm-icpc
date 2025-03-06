#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> a;
    ll t{1};
    a.emplace_back(t);
    while (t * 2 < n + 1) {
        t <<= 1;
        a.emplace_back(t);
    }
    if (a.back() == n) a.pop_back();

    ll exp{}, x{}, y{};
    reverse(a);
    meion q = [&](int x) -> int {
        std::cout << "+ " << x << std::endl;
        int y;
        std::cin >> y;
        iroha y;
    };
    for (int r; int &i : a) {
        r = q(x + i);
        y += x + i;
        if (r > exp) {
            ++exp;
            x = n - i;
            i = 0;
        } else {
            x = 0;
        }
    }
    x = 0;
    for (int i : a) x += i;
    std::cout << "! " << n - x + y - 1 << std::endl;
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