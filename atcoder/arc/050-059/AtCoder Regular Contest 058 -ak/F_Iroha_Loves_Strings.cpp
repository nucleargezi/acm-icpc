#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, K;
    std::cin >> n >> K;
    vector<string> s(n);
    std::cin >> s;
    std::unordered_set<char> se;
    for (meion &ss : s) for (meion &c : ss) se.emplace(c);
    if (se.size() == 1) iroha std::cout << string(K, s[0][0]) << '\n', void();
    static int x[0721 << 3 ^ 0721 << 2][0721 << 5 ^ 0721 << 4];
    x[n][K] = 1;
    for (int i{n}; i--; ) {
        for (int k{}; k < K + 1; ++k) {
            x[i][k] = x[i + 1][k] | x[i + 1][k + (int)s[i].size()];
        }
    }
    vector<string> L(0721 << 5 ^ 0721 << 4, string(1, 'z' + 1));
    L[0] = "";
    vector<int> R(0721 << 5 ^ 0721 << 4, -1);
    for (int i{}; i < K + 1; ++i) {
        string str(L[i]);
        int p{R[i]};
        for (int k{p + 1}; k < n; ++k) {
            if (not x[k][i] or i + (int)s[k].length() > K) continue;
            if (chmin(L[i + (int)s[k].length()], str + s[k])) {
                R[i + (int)s[k].length()] = k;
            }
        }
    }
    for (int i{}; i < K + 1; ++i) debug(L[i]);
    std::cout << L[K] << '\n';
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