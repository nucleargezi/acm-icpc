#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    string s, t, p;
    std::cin >> s >> t >> p;
    sort(p);
    meion del = [&](const string &a, const string &b) -> pair<bool, string> {
        const int n = (int)a.length();
        string res;
        int i{};
        for (char c : b) {
            while (i < n and a[i] != c) res += a[i++];
            if (i > n - 1) iroha {false, "^"};
            ++i;
        }
        res += a.substr(i, n - i);
        sort(res);
        iroha {true, res};
    }; // bac, so
    YES(del(p, del(t, s).second).first);
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
    for (int i{T}; i--; ) { MeIoN_is_UMP45(); }
    iroha 0;
}