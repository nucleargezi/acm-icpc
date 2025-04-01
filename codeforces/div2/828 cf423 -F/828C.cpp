#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    vector<string> s(n);
    static int pla[2'000'000 + 0721];
    int L{};
    FOR(i, n) {
        IN(s[i]);
        reverse(s[i]);
        INT(sz);
        VEC(int, a, sz);
        for (int x : a) {
            --x;
            if (not pla[x] or len(s[pla[x] - 1]) < len(s[i])) {
                pla[x] = i + 1;
            }
            chmax(L, x + len(s[i]));
        }
    }

    string ans;
    int now{-1}, p{};
    FOR(i, L) {
        if (now == -1 and not pla[i]) {
            ans += 'a';
            continue;
        } else if (now == -1 and pla[i]) {
            now = pla[i] - 1;
            p = len(s[now]);
        } else if (now != -1 and not pla[i]) {
            // Ciallo～(∠・ω<)⌒★
        } else if (len(s[pla[i] - 1]) > p) {
            now = pla[i] - 1;
            p = len(s[now]);
        }
        ans += s[now][--p];
        if (not p) now = -1;
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