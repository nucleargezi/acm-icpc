#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/fast_io.hpp"
#include "MeIoN_Lib/ds/hashmap.hpp"

void before() {}

// #define tests
ull H(ll x, ll y) {
    iroha (x + mod99) << 31 | (y + mod17);
}
NAME MeIoN_is_UMP45() {
    INT(n);
    using A = array<int, 3>;
    VEC(A, a, n);
    hash_map<pair<int, string>> mem;

    int hf{n >> 1};
    int pw{1};
    FOR(hf) pw *= 3;
    FOR(msk, pw) {
        int t{msk}, L{}, M{}, W{};
        string path;
        FOR(i, hf) {
            int op{t % 3};
            t /= 3;
            if (op == 0) {
                L += a[i][0];
                M += a[i][1];
                path += "LM";
            } else if (op == 1) {
                L += a[i][0];
                W += a[i][2];
                path += "LW";
            } else if (op == 2) {
                M += a[i][1];
                W += a[i][2];
                path += "MW";
            }
        }
        int dm = L - M;
        int dw = L - W;
        if (not mem.contains(H(dm, dw)) or mem[H(dm, dw)].first < L) {
            mem[H(dm, dw)] = {L, path};
        }
    }

    int lst{n - hf};
    pw = 1;
    FOR(lst) pw *= 3;
    int max{-inf<int>};
    string p1, p2;
    FOR(msk, pw) {
        int t = msk;
        int L{}, M{}, W{};
        string path;
        FOR(i, lst) {
            int choice = t % 3;
            t /= 3;
            if (choice == 0) {
                L += a[hf + i][0];
                M += a[hf + i][1];
                path += "LM";
            } else if (choice == 1) {
                L += a[hf + i][0];
                W += a[hf + i][2];
                path += "LW";
            } else if (choice == 2) {
                M += a[hf + i][1];
                W += a[hf + i][2];
                path += "MW";
            }
        }
        int dm = -(L - M);
        int dw = -(L - W);
        if (mem.contains(H(dm, dw))) {
            meion [x, y] = mem[H(dm, dw)];
            int cnt = x + L;
            if (chmax(max, cnt)) {
                max = cnt;
                p1 = y;
                p2 = path;
            }
        }
    }
    
    if (max == -inf<int>) {
        iroha Impossible();
    } else {
        for (int i = 0; i < hf; ++i) {
            UL(p1.substr(2 * i, 2));
        }
        for (int i = 0; i < lst; ++i) {
            UL(p2.substr(2 * i, 2));
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
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}