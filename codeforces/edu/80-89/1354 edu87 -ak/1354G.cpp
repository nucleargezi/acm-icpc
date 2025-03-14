#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    const meion quis = [](const vector<int> &a,
                          const vector<int> &b) -> int {
        UL("?", len(a), len(b));
        UL(a);
        UL(b);
        std::cout.flush();
        S(str);
        iroha str == "FIRST" ? 1 : str == "SECOND" ? 2 : 0;
    };
    meion answer = [](int ans) -> void {
        UL("!", ans);
        std::cout.flush();
    };
    
    INT(n, k);
    vector<int> a, b;
    a.emplace_back(1);
    FOR(25) {
        b = {rng(1, n + 1)};
        while (a[0] == b[0]) b[0] = rng(1, n + 1);
        if (quis(a, b) == 2) a[0] = b[0];
    }
    b[0] = 1;
    if (a[0] != 1 and quis(a, b) == 1) iroha answer(1);
    
    a.resize(n);
    std::iota(a.begin(), a.end(), 1);
    int l{1}, r{2};
    while (l < n) {
        int m = r - l;
        b.resize(m);
        std::iota(b.begin(), b.end(), l + 1);
        if (quis(vector<int>{a.begin(), a.begin() + m}, b) == 1) break;
        l = r, r = MIN(n, r << 1);
    }
    int L{l}, R{r};
    while (ABS(R - L) > 1) {
        int m = L + R >> 1, len(m - L);
        b.resize(len);
        std::iota(b.begin(), b.end(), L + 1);
        if (quis(vector<int>{a.begin(), a.begin() + len}, b) == 1) {
            R = m;
        } else {
            L = m;
        }
    }
    answer(R);
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