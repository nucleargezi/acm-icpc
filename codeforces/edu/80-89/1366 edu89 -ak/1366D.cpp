#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/sieve.hpp"

void before() {
    sieve(1'000'0000);
}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    VEC(int, a, n);

    vector<int> X, Y;
    meion emplace = [&](int a, int b) { X.emplace_back(a), Y.emplace_back(b); };

    for (int x : a) {
        int mx{minp[x]};
        if (mx == x) {
            emplace(-1, -1);
        } else {
            while (x % mx == 0) x /= mx;
            if (x ^ 1)
                emplace(mx, x);
            else
                emplace(-1, -1);
        }
    }
    UL(X);
    UL(Y);    
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