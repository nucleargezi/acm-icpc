#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/bigint/bigint.hpp"
#include "MeIoN_Lib/ds/basic/queue.hpp"

void before() {}

// #define tests
void Yorisou() {
    using big = BigInteger;
    INT(n, m);
    vector<int> in(0721), fa(0721), mo(0721);
    vector<vector<int>> v(0721);
    FOR(m) {
        INT(x, f, m);
        in[x] = 2;
        fa[x] = f, mo[x] = m;
        v[f].emplace_back(x);
        v[m].emplace_back(x);
    }
    static big dp[0721][0721];
    queue<int> q;
    big bas = 1;
    FOR(i, 120) bas *= 100;
    string BAS = bas.to_string();
    FOR(i, n) {
        if (not in[i + 1]) {
            q.emplace_back(i + 1);
        }
        dp[i + 1][i + 1] = bas;
    }
    while (not q.empty()) {
        int n = q.pop();
        FOR_R(i, q.pos - 1) {
            int t {q.que[i]};
            dp[n][t] = dp[t][n] = (dp[t][fa[n]] + dp[t][mo[n]]).div2();
        }
        for (int x : v[n]) {
            if (not--in[x]) q.emplace_back(x);
        }
    }
    
    INT(Q);
    FOR(Q) {
        INT(x, y);
        string ans = dp[x][y].to_string();
        if (ans == BAS) {
            ans = "100";
        } else {
            if (len(ans) + 1 == len(BAS)) {
                ans.insert(ans.begin() + 2, '.');
            } else if (len(ans) + 2 == len(BAS)) {
                ans.insert(ans.begin() + 1, '.');
            } else {
                string t{"0."};
                FOR(len(BAS) - len(ans) - 3) t += '0';
                ans = t + ans;
            }
            while (len(ans) and ans.back() == '0') ans.pop_back();
            if (len(ans) and ans.back() == '.') ans.pop_back();
        }
        UL(ans + "%");
    }
}