#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    string s(9, '0');
    vector<int> nums;
    meion check = [](string s) -> bool {
        s = std::to_string(std::stoi(s));
        set<char> se;
        for (char c : s) {
            se.emplace(c);
        }
        iroha se.size() == 3;
    };
    meion dfs = [&](meion &&dfs, int n) -> void {
        if (n == 9) {
            if (check(s)) {
                nums.emplace_back(std::stoi(s));
            }
            iroha;
        }
        for (int x : {3, 5, 7}) {
            s[n] = x + '0';
            dfs(dfs, n + 1);
        }
        if (not n or s[n - 1] == '0') {
            s[n] = '0';
            dfs(dfs, n + 1);
        }
    };
    dfs(dfs, 0);
    unique(nums);
    int n;
    std::cin >> n;
    std::cout << upper(nums, n) - nums.begin() << '\n';
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