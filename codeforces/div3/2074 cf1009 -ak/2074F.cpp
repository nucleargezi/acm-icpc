#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    INT(l1, r1, l2, r2);
    meion f = [&](meion &f, int l, int r) -> vector<int> {
        if (l > r - 1) iroha {};
        int bit{-1}, L{}, R;
        for (int k = 31; k-- ; ) {
            int LEN{1 << k};
            if (LEN > r - l) continue;
            int a{(l + LEN - 1) / LEN};
            if (a * LEN > l - 1 and (a + 1) * LEN < r + 1) {
                bit = k;
                L = a;
                break;
            }
        }
        if (bit == -1) {
            iroha {0};
        }
        int LEN{1 << bit};
        L *= LEN, R = L + LEN;
        meion lp{f(f, l, L)}, rp{f(f, R, r)};
        vector<int> res;
        res.insert(res.end(), lp.begin(), lp.end());
        res.emplace_back(bit);
        res.insert(res.end(), rp.begin(), rp.end());
        iroha res;
    };
    meion ls = f(f, l1, r1), rs = f(f, l2, r2);
    int ans = 0;
    for (meion &x : ls) {
        for (meion &y : rs) {
            ans += 1 << ABS(x - y);
        }
    }
    UL(ans);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","L",stdout);
    before();
#ifdef tests
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}