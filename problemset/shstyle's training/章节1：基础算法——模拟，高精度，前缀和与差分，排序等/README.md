---
title: shstyle_problemset01题解
date: 2025-01-18 17:07:38
tags:
    - "题解"
categories:
    - "ACM-ICPC"
thumbnail: "images/Ciallo-World/Ciallo.png"
mathjax: true
---

## 章节1：基础算法——模拟，高精度，前缀和与差分，排序等

Link: [Vjudge链接](https://vjudge.net/contest/686173#overview)

```cpp
#define meion auto
#define iroha return
```

### A_简单模拟_1
记录当前的位置, 按照题意将指针左移右移即可, 由于这是一个环, 所以下标减成负数的时候可以加$n$来得到正确的下表, 下标超过$n - 1$时同理, 可以减$n$
#### code
```cpp
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    int dir[n];
    string name[n];
    for (int i{}; i < n; ++i) {
        std::cin >> dir[i] >> name[i];
    }
    int p{};
    for (int i{}, op, d; i < m; ++i) {
        std::cin >> op >> d;
        if (op) {
            p += d * (dir[p] ? -1 : 1);
        } else {
            p -= d * (dir[p] ? -1 : 1);
        }
        if (p < 0) p += n;
        if (p > n - 1) p -= n;
    }
    std::cout << name[p] << '\n';
}
```

### B_简单模拟_2
将一个$N$阶方阵顺时针或者逆时针旋转, 实际上顺时针旋转就是把第 $i$ 行放到第 $N - i - 1$ 列, 逆时针就是把第 $i$ 行放到第 $i$ 列, 模拟即可  
这种旋转方阵的问题实际上有根号级别的做法, 在去年还是前年的省选中考察过, 有兴趣的同学可以自行了解
#### code
```cpp
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    int a[n][n], b[n][n];
    for (int i{}; i < n * n; ++i) {
        a[0][i] = i + 1;
    }
    for (int i{}, x, y, r, z; i < m; ++i) {
        std::cin >> x >> y >> r >> z, --x, --y;
        int px = x - r, py = y - r, sz = r + r + 1;
        for (int i{}; i < sz; ++i) {
            for (int k{}; k < sz; ++k) {
                (z ? b[sz - k - 1][i] : b[k][sz - i - 1]) = a[px + i][py + k];
            }
        }
        for (int i{}; i < sz; ++i) {
            for (int k{}; k < sz; ++k) {
                a[px + i][py + k] = b[i][k];
            }
        }
    }
    for (int i{}; i < n; ++i) {
        for (int k{}; k < n; ++k) {
            std::cout << a[i][k] << " \n"[k + 1 == n];
        }
    }
}
```

### C_简单模拟_3
把胜负表打出来然后计算就可以, 循环可以通过对下标取模实现
#### code
```cpp
NAME MeIoN_is_UMP45() {
    int n, na, nb;
    std::cin >> n >> na >> nb;
    vector<int> a(na), b(nb);
    std::cin >> a >> b;
    constexpr int v[5][5] = {{0, 0, 1, 1, 0},
                             {1, 0, 0, 1, 0},
                             {0, 1, 0, 0, 1},
                             {0, 0, 1, 0, 1},
                             {1, 1, 0, 0, 0}},
                  w[5][5] = {{0, 1, 0, 0, 1},
                             {0, 0, 1, 0, 1},
                             {1, 0, 0, 1, 0},
                             {1, 1, 0, 0, 0},
                             {0, 0, 1, 1, 0}};
    int ans[] = {0, 0};
    for (int i{}, x{}, y{}; i < n; ++i) {
        ans[0] += v[a[x]][b[y]], ans[1] += w[a[x]][b[y]];
        x = (x + 1) % na;
        y = (y + 1) % nb;
    }
    std::cout << ans[0] << ' ' << ans[1] << '\n';
}
```

### D_简单模拟_4
用一个string储存答案, 对原串一位一位模拟, 对每一个可展开的```'-'```展开即可
#### code
```cpp
NAME MeIoN_is_UMP45() {
    array<int, 3> p;
    string s;
    std::cin >> p >> s;
    string ans;
    const int n = s.length();
    for (int i = 0; i < n; ++i) {
        if (i < n - 1 and i and s[i] == '-' and
            ((std::isdigit(s[i - 1]) and std::isdigit(s[i + 1]) or
              (std::isalpha(s[i - 1]) and std::isalpha(s[i + 1])))) and
            s[i + 1] >= s[i - 1]) {
            if (s[i + 1] == s[i - 1]) {
                ans += '-';
            } else if (s[i + 1] > s[i - 1] + 1) {
                string buf;
                for (char c = s[i - 1] + 1; c < s[i + 1]; ++c) {
                    buf += string(p[1], c);
                }
                if (p[2] == 2) std::ranges::reverse(buf);
                if (p[0] == 2 and std::isalpha(buf[0])) {
                    for (char &c : buf) {
                        c = std::toupper(c);
                    }
                }
                if (p[0] == 3) {
                    buf = string(buf.length(), '*');
                }
                ans += buf;
            }
        } else {
            ans += s[i];
        }
    }
    std::cout << ans << '\n';
}
```

### E - 你说得对，但是程序设计竞赛怎么能没有模拟题(1)
- 判断地址串是否合法  
    - 检查是否是 前面3个```'.'```, 后面一个```':'```
    - 分割出5个数字, 依次判断他们的值是否在值域内
    - 检查前导零, 这里直接把数字字串转成数字```std::stoi()```再转回字符串```std::to_string()```查看是否相等, 如果爆int了说明写法有问题, 可以遇到长数字串直接```return false```
- 判断连接情况
    - 可以直接用map模拟
#### code
```cpp
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    meion check = [&](string s) -> bool {
        int cnt{};
        for (char c : s) {
            if ((c == '.' and cnt == 3) or (c == ':' and cnt != 3)) {
                iroha false;
            }
            cnt += c == '.' or c == ':';
        }
        if (cnt != 4) iroha false;
        string n;
        for (char c : s) {
            if (c == '.' or c == ':') {
                if (n.empty()) iroha false;
                if (n.size() > 5) iroha false;
                int x = std::stoi(n);
                if (std::to_string(x) != n) iroha false;
                if (not(x < 256 and x > -1)) iroha false;
                n = "";
            } else {
                n += c;
            }
        }
        if (n.size() > 5) iroha false;
        if (n.empty()) iroha false;
        int x = std::stoi(n);
        if (std::to_string(x) != n) iroha false;
        if (not(x < 65536 and x > -1)) iroha false;
        iroha true;
    };
    map<string, int> serv;
    for (int i = 0; i < n; ++i) {
        string op, s;
        std::cin >> op >> s;
        if (not check(s)) {
            std::cout << "ERR\n";
        } else if (op[0] == 'S') {
            if (serv.contains(s)) {
                std::cout << "FAIL\n";
            } else {
                std::cout << "OK\n";
                serv[s] = i + 1;
            }
        } else {
            if (serv.contains(s)) {
                std::cout << serv[s] << '\n';
            } else {
                std::cout << "FAIL\n";
            }
        }
    }
}
```

### F_你说得对_但是程序设计竞赛怎么能没有模拟题_2
就是解方程
- 判断delta
  - $delta < 0$
    - 无解
  - $delta == 0$
    - 有唯一解
  - $delta > 0$
    - 输出较大解
- 输出
  - 没有根号的分数, 约分一下输出即可, 约分直接除gcd就行
  - 带根号的分数有要先提取根号内的整数部分, 对于 $\sqrt{x}$ 可以暴力枚举 $i$ 检查 $i * i$ 是否为 $x$ 的因子
#### code:
```cpp
NAME MeIoN_is_UMP45() {
    ll a, b, c;
    std::cin >> a >> b >> c;
    b = -b;
    ll del = b * b - (a * c << 2), aa = a + a;
    bool f = aa < 0;
    if (del < 0) iroha NO();
    meion outfra = [&](ll x, ll y) -> void {
        if (x % y == 0) iroha std::cout << x / y, void();
        if (x < 0 and y < 0) x = -x, y = -y;
        ll gcd = std::gcd(x, y);
        assert(gcd > 0);
        x /= gcd, y /= gcd;
        if (x < 0 or y < 0) {
            if (x < 0) x = -x;
            else y = -y;
            std::cout << '-' << x << '/' << y;
        } else {
            std::cout << x << '/' << y;
        }
    };
    meion check_sq = [&](ll x) -> pair<bool, ll> {
        ll sqr = binary_search([&](ll m) {
            iroha m * m < x + 1;
        }, 0, inf<int>);
        iroha {sqr * sqr == x, sqr};
    };
    if (not del) {
        if (not b) iroha std::cout << "0\n", void();
        iroha outfra(b, aa), std::cout << '\n', void();
    } else {
        meion [ok, sqr] = check_sq(del);
        if (ok) {
            outfra(b + (f ? -sqr : sqr), aa);
            std::cout << '\n';
        } else {
            if (b) {
                outfra(b, aa);
                std::cout << '+';
            }
            ll x{};
            for (int i = 1; i * i < del + 1; ++i) {
                if (del % (i * i) == 0) x = i;
            }
            del = del / x / x;
            if (aa < 0) aa = -aa;
            ll gcd = std::gcd(aa, x);
            x /= gcd, aa /= gcd;
            if (x != 1) std::cout << x << '*';
            std::cout << "sqrt(" << del << ')';
            if (aa != 1) std::cout << '/' << aa;
            std::cout << '\n';
        }
    }
}
```

### G_你说得对_但是程序设计竞赛怎么能没有模拟题_3
暴力枚举所有的式子, 判断是否合法即可
#### code:
```cpp
NAME MeIoN_is_UMP45() {
    string s, t;
    std::cin >> s >> t;
    s.erase(s.begin() + 5), s.erase(s.begin() + 2);
    t.erase(t.begin() + 5), t.erase(t.begin() + 2);
    array<int, 10> l{}, r{};
    for (int i{}; i < 6; ++i) {
        l[s[i] - '0'] += t[i] == 'P';
    }
    r.fill(0721);
    for (int i{}; i < 6; ++i) {
        if (t[i] == 'B') r[s[i] - '0'] = l[s[i] - '0'];
    }
    vector<string> ans;
    meion check = [&](const string &v) -> bool {
        array<int, 10> c{};
        for (int i{}; i < 6; ++i) {
            if (v[i] == s[i]) {
                if (t[i] != 'G') {
                    iroha false;
                }
            } else {
                ++c[v[i] - '0'];
                if (t[i] == 'G') {
                    iroha false;
                }
            }
        }
        for (int i{}; i < 10; ++i) {
            if (not(c[i] < r[i] + 1 and c[i] > l[i] - 1)) {
                iroha false;
            }
        }
        iroha true;
    };
    for (int x{}; x < 100; ++x) {
        for (int y{}; y < 100 - x; ++y) {
            int z = x + y;
            string v;
            v += '0' + x / 10, v += '0' + x % 10;
            v += '0' + y / 10, v += '0' + y % 10;
            v += '0' + z / 10, v += '0' + z % 10;
            if (check(v)) {
                ans.emplace_back(v.substr(0, 2) + "+" + v.substr(2, 2) + "=" +
                                 v.substr(4) + '\n');
            }
        }
    } 
    std::cout << ans.size() << '\n';
    for (meion &s : ans) {
        std::cout << s;
    }
}
```

### H_进阶_你说得对_但是程序设计竞赛怎么能没有模拟题_4
用栈模拟运行过程, 判断程序合法性; 注意无效循环内部嵌套的循环都是无效的, 这部分不能计入复杂度
#### code:
```cpp
NAME MeIoN_is_UMP45() {
    int n;
    string o;
    std::cin >> n >> o;
    int kd{}, sn{};
    for (char c : o) {
        if (c == 'n') kd = 1;
        if (std::isdigit(c)) {
            sn = sn * 10 + c - '0';
        }
    }
    if (not kd) sn = 0;
    vector<pair<string, int>> stk;
    set<string> se;
    bool ok = true;
    int max{};
    vector<int> a(n);
    for (int i{}, val{}, C{}; i < n; ++i) {
        char c; 
        std::cin >> c;
        if (c == 'F') {
            string it, sx, sy;
            std::cin >> it >> sx >> sy;
            int x{}, y{};
            for (char c : sx) {
                x = x * 10 + c - '0';
            }
            for (char c : sy) {
                y = y * 10 + c - '0';
            }
            if (not se.emplace(it).second) {
                ok = false;
            }
            if ((sx == "n" and sy != "n") or
                (sx != "n" and sy != "n" and x > y)) {
                a[i] = -1;
            } else if (sx == "n") {
                ;
            } else if (sy == "n") {
                a[i] = 1;
            } else {
                ;
            }
            if (a[i] == 1) {
                ++val;
            } else if (a[i] == -1) {
                ++C;
            }
            stk.emplace_back(it, i);
        } else {
            if (stk.empty()) {
                ok = false;
                continue;
            }
            if (not C) chmax(max, val);
            if (a[stk.back().second] == -1) {
                --C;
            } else if (a[stk.back().second] == 1) {
                --val;
            } 
            if (se.contains(stk.back().first)) {
                se.erase(stk.back().first);
            }
            stk.pop_back();
        }
    }
    if (not stk.empty() or not ok) {
        std::cout << "ERR\n";
    } else {
        Yes(max == sn);
    }
}
```

### I_进阶_你说得对_但是程序设计竞赛怎么能没有模拟题_5
- 只有两类题目可能计入罚时
    - 封榜前提交 直接计入罚时
    - 封榜后提交 我们并不知道哪几题过了, 可以用类似状压的方法枚举子集, 计算罚时是否正确
      - 注意封榜后的ac时间一定在 $240$ ~ $299$ 范围内
#### code:
```cpp
int m;
struct node {
    int id, type, time, cnt1, cnt2;
    node(int id = 0, int type = 0, int c = 0, int cc = 0)
        : id(id), type(type), cnt1(c), cnt2(c) {}
};
struct prob {
    int id, l, r;
};
NAME MeIoN_is_UMP45() {
    int n, pen;
    std::cin >> n >> pen;
    vector<node> a(m);
    meion out = [&]() {
        Yes();
        for (int i{}; i < m; ++i) {
            if (a[i].type == 1) {
                std::cout << "+ " << a[i].cnt1 << '/' << a[i].time;
            } else if (a[i].type == 2) {
                std::cout << "- " << a[i].cnt1;
            } else {
                std::cout << '.';
            }
            std::cout << '\n';
        }
    };
    int nown{}, nowp{};
    for (int i{}; i < m; ++i) {
        a[i].id = i;
        char c;
        std::cin >> c;
        if (c == '+') {
            a[i].type = 1;
            std::cin >> a[i].cnt1 >> c >> a[i].time;
            ++nown;
            nowp += a[i].time + (a[i].cnt1 - 1) * 20;
        } else if (c == '-') {
            a[i].type = 2;
            std::cin >> a[i].cnt1;
        } else if (c == '?') {
            a[i].type = 3;
            std::cin >> a[i].cnt2 >> a[i].cnt1;
            a[i].cnt1 -= a[i].cnt2;
        } else {
            a[i].type = 4;
        }
    }

    if (n < nown or pen < nowp) {
        iroha No();
    } else if (n == nown and pen == nowp) {
        for (int i{}; i < m; ++i) {
            if (a[i].type == 3) {
                a[i].type = 2;
                a[i].cnt1 += a[i].cnt2;
            }
        }
        iroha out();
    } else {
        n -= nown;
        pen -= nowp;
    }
    vector<prob> v;
    for (int i{}; i < m; ++i) {
        if (a[i].type == 3) {
            v.emplace_back(i, a[i].cnt1 * 20 + 240,
                           (a[i].cnt1 + a[i].cnt2 - 1) * 20 + 299);
        }
    }
    int sz = v.size();
    for (int i{}; i < (1 << sz); ++i) {
        if (popcount(i) != n) continue;
        int l{}, r{};
        for (int k{}; k < sz; ++k) {
            if (i >> k & 1) {
                l += v[k].l, r += v[k].r;
            }
        }
        if (l < pen + 1 and pen < r + 1) {
            int lst = pen - l;
            for (int k{}; k < sz; ++k) {
                int id = v[k].id;
                if (not(i >> k & 1)) {
                    a[id].type = 2;
                    a[id].cnt1 += a[id].cnt2;
                    continue;
                }
                a[id].type = 1;
                
                int N = std::min(a[id].cnt2 - 1, lst / 20);
                a[id].cnt1 += N + 1;
                lst -= N * 20;

                int tmp = std::min(59, lst);
                a[id].time = 240 + tmp;
                lst -= tmp;
            }
            iroha out();
        }
    }
    No();
}
```

### J_进阶_你说得对_但是程序设计竞赛怎么能没有模拟题_6
- 这题会爆int
- 注意一个结构题内每一个元素都要对齐一次
- 用map暴力模拟即可
#### code:
```cpp
NAME MeIoN_is_UMP45() {
    #define int long long
    int n;
    std::cin >> n;
    using Var = tuple<string, string, int, int>;
    map<string, vector<Var>> Struct;
    map<string, pair<int, int>> Mem;
    map<string, int> Size;

    Size["byte"] = 1, Size["short"] = 2, Size["int"] = 4, Size["long"] = 8;
    
    for (int i{}, op; i < n; ++i) {
        std::cin >> op;
        if (op == 1) {
            string s;
            int k;
            std::cin >> s >> k;
            Struct[s];
            int sz{}, b_sz{};
            for (int i{}; i < k; ++i) {
                string type, name;
                std::cin >> type >> name;
                int l{}, r{};
                if (Size.contains(type)) {
                    l = r = Size[type];
                } else {
                    std::tie(l, r) = Mem[type];
                }
                Struct[s].emplace_back(type, name, l, r);
                chmax(b_sz, r);
                sz = ceil(sz, r) * r;
                sz += l;
            }
            sz = ceil(sz, b_sz) * b_sz;
            Mem[s] = {sz, b_sz};
            std::cout << Mem[s] << '\n';
        } else if (op == 2) {
            string type, name;
            std::cin >> type >> name;
            int sz{};
            for (const meion &[type, name, l, r] : Struct["meion"]) {
                sz = ceil(sz, r) * r;
                sz += l;
            }
            int b_sz = (Size.contains(type) ? Size[type] : Mem[type].second);
            sz = ceil(sz, b_sz) * b_sz;
            std::cout << sz << '\n';
            sz = (Size.contains(type) ? Size[type] : Mem[type].first);
            Struct["meion"].emplace_back(type, name, sz, b_sz);
        } else if (op == 3) {
            string name;
            std::cin >> name;
            int sz{};
            string pla = "meion";
            for (int l{}, r; l < name.length(); l = r + 1) {
                r = l;
                while (r < name.length() and name[r] != '.') ++r;
                string s = name.substr(l, r - l);
                 for (meion [type, name, l, r] : Struct[pla]) {
                    sz = ceil(sz, r) * r;
                    if (name == s) {
                        pla = type;
                        break;
                    }
                    sz += l;
                }
            }
            std::cout << sz << '\n';
        } else {
            int cer;
            std::cin >> cer;
            int cp{};
            bool Break = true;
            string pla = "meion";
            while (Break) {
                ll s{};
                for (meion [type, name, l, r] : Struct[pla]) {
                    s = cp;
                    s = ceil(s, r) * r;
                    if (s < cer + 1 and cer < s + l) {
                        cp = s;
                        s += l;
                        if (Size.contains(type)) {
                            goto MYgo;
                        }
                        pla = type;
                        break;
                    }
                    if (s > cer) {
                        Break = false;
                        break;
                    }
                    cp = s + l;
                }
                if (s < cer + 1) break;
            }
            if (false) {
            MYgo:
                cp = {};
                pla = "meion";
                while (true)
                    for (int s; const meion &[type, name, l, r] : Struct[pla]) {
                        s = cp;
                        s = ceil(s, r) * r;
                        if (s < cer + 1 and cer < s + l) {
                            if (pla != "meion") std::cout << '.';
                            std::cout << name;
                            if (Size.contains(type)) {
                                goto MYGO;
                            }
                            cp = s;
                            pla = type;
                            break;
                        }
                        cp = s + l;
                    }
                MYGO: std::cout << '\n';
            } else {
                std::cout << "ERR\n";
            }
        }
    }
    #undef int
}
```

### 关于高精度
- 如果你不明白高精度的实现, 建议了解一下
  - 一般我们使用压位高精, 用一个 uint 或者 ull 来一次模拟高精度数的几个数位(比如8个), 用一个数组来存高精度数的所有位数, 这样节约空间, 当然你也可以使用 ```std::bitset``` 之类的东西来实现高精度, 也是节约空间的
  - 对于加减法就 $O(n)$ for一遍就好了
  - 对于乘法, 如果需要优秀的复杂度需要写 fft 复杂度 $O(nlog(n))$, naive实现则是 $O(n ^ 2)$
  - 对于除法, 可以二分商, 然后用高精度乘法check $O(nlog(n) ^ 2)$
  - 然后你写了以后就会发现高精度写起来很麻烦, 赛场上更是麻烦, 所以一般来说遇到高精度题还是用 python 或者 jvav 写( 
  - 判断高精度题的能力还是要有的( 

板子部分, 可以直接上网找一个简短且实现优秀的板子抄来用, 不过最好能理解高精度的实现
#### code:
```cpp
#include "MeIoN_Lib/math/Big_int.hpp"
using INT = BigInteger;
```

### K_高精度_1
高精度板子
#### code:
```cpp
NAME MeIoN_is_UMP45() {
    INT a, b;
    std::cin >> a >> b;
    std::cout << a + b << '\n';
}
```
### L_高精度_2
高精度板子
#### code:
```cpp
NAME MeIoN_is_UMP45() {
    INT a, b;
    std::cin >> a >> b;
    std::cout << a * b << '\n';
}
```
### M_高精度_3
高精度板子
#### code:
```cpp
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    INT x = 1, ans = 0;
    for (int i = 0; i < n; ) {
        x *= ++i;
        ans += x;
    }
    std::cout << ans << '\n';
}
```
### N_高精度_4
高精度板子
#### code:
```cpp
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    INT res = 2;
    INT limit = 1;
    for (int i = 0721 >> 1; i--; ) {
        limit *= 1000;
    }
    res = res.pow(n);
    res -= 1;
    res %= limit;
    std::cout << int(std::log10(2) * n + 1) << '\n';
    std::string ans = res.to_string();
    std::ranges::reverse(ans);
    while (ans.size() > 500) ans.pop_back();
    while (ans.size() < 500) ans += '0';
    std::ranges::reverse(ans);
    for (int i = 0; i < 500; ++i) {
        std::cout << ans[i];
        if ((i + 1) % 50 == 0) std::cout << '\n';
    }
}
```
### O_进阶_高精度_5
由于 *if i can be divided by $d ^ 2$ for some integers $d ≥ 2$* 我们实际上只需要质因子, 从小到大选取质因子相乘, 乘积在 $n$ 之内的最大组合就是选取的电阻
#### code:
```cpp
NAME MeIoN_is_UMP45() {
    INT n;
    std::cin >> n;
    INT p = 1, q = 1;
    for (int i{2}; i < 114514 and p * i < n + 1; ++i) {
        if (not primetest(i)) continue;
        p *= i;
        q *= i + 1;
    }
    INT gcd = p.gcd(q);
    p /= gcd, q /= gcd;
    std::cout << p << '/' << q << '\n';
}
```

### P_排序_1
```std::sort()```
#### code:
```cpp
NAME MeIoN_is_UMP45() {
    int n, k;
    std::cin >> n >> k;
    vector<int> a(n);
    std::cin >> a;
    sort(a);
    std::cout << a[k] << '\n';
}
```

### Q_排序_2
发现值域很小, 可以直接暴力, 用一个桶记录, 暴力查询
#### code:
```cpp
NAME MeIoN_is_UMP45() {
    int n, w;
    std::cin >> n >> w;
    static int c[601];
    for (int i{}, x, ans, s; i < n; ++i) {
        std::cin >> x;
        ++c[x];
        int p = i + 1 - std::max(1, (i + 1) * w / 100);
        for (ans = 0, s = 0; ans < 601 and s + c[ans] < p + 1; ++ans) {
            s += c[ans];
        }
        std::cout << ans << " \n"[i + 1 == n];
    }
}
```

### R_排序_3
虽然感觉不太对但是好像直接暴力能过  
如果不暴力的话, 可以考虑每次修改对其他数的影响, $O(n)$ 更新, 查询则是 $O(1)$ 
#### code:
```cpp
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<int> a(n);
    std::cin >> a;
    for (int i = 0, op, x, y; i < m; ++i) {
        std::cin >> op;
        if (op == 1) {
            std::cin >> x >> y;
            a[--x] = y;
        } else {
            std::cin >> x, --x;
            int ans{};
            for (int i{}; i < x + 1; ++i) {
                ans += a[i] < a[x] + 1;
            }
            for (int i{x + 1}; i < n; ++i) {
                ans += a[i] < a[x];
            }
            std::cout << ans << '\n';
        }
    }
}
```

### S_与排序相关的构造题_1
仔细观察会发现可以可以做出类似冒泡排序的操作, 题目也允许 $n ^ 2$ 的做法, 于是就做完了
#### code:
```cpp
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    std::cin >> a;
    vector<int> id(n);
    for (int i = 0, x; i < n; ++i) {
        std::cin >> x;
        id[--x] = i;
    }
    for (int i = 0; i < n; ++i) {
        a[i] = id[--a[i]];
    }
    string ans(n * n, '1');
    for (int i = 0; i < n * n; ++i) {
        int x = i % n, y = x + 1;
        if (y == n) continue;
        if (a[x] > a[y]) {
            std::swap(a[x], a[y]);
            ans[i] = '2';
        }
    }
    std::cout << ans << '\n';
}
```

### T_进阶_与排序相关的构造题_2
操作是交换逆序对, 所以对于一个小数字, 它可以和前面的更大的数字进行交换, 那么考虑如何操作比较优, 一定是尽量让这个数字不断与比它大一点的数交换直到到达目标位置, 这样造成的浪费比较少, 因为交换本身会导致另一个数字可交换的空间变少
#### code:
```cpp
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> a(n), b(n);
    std::cin >> a >> b;
    vector<int> f(n), ff(n);
    for (int i{}; i < n; ++i) {
        f[--a[i]] = i;
        ff[--b[i]] = i;
    }
    vector<pair<int, int>> ans;
    for (int i{}; i < n; i++) {
        if (f[i] > ff[i] - 1) {
            for (int k = i + 1, p = f[i]; k < n; ++k) {
                if (f[k] < p and f[k] > ff[i] - 1) {
                    f[i] = f[k];
                    std::swap(a[p], a[f[k]]);
                    std::swap(f[k], p);
                    ans.emplace_back(std::min(f[k], p) + 1,
                                     std::max(f[k], p) + 1);
                }
            }
        } else {
            iroha std::cout << "-1\n", void();
        }
    }
    std::cout << ans.size() << '\n';
    for (meion x : ans) {
        std::cout << x << '\n';
    }
}
```

### 关于 前缀和 与 差分
这两其实应该算是同一个东西, 理解思想, 写题很常用  
顺便 我一直把前缀和数组 $c$ 的意义认为是 "$c[i]$ 表示 前 $i$ 个元素的和" 之前遇到过不少对 $0-index$ 下前缀和数组的意义有疑问的同学(
### U_前缀和_1
板子 也可以用一些简单数据结构做这题
#### code:
```cpp
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<ll> a(n);
    std::cin >> a;
    a = pre_sum(a);
    int m;
    std::cin >> m;
    for (int i = 0, l, r; i < m; ++i) {
        std::cin >> l >> r, --l;
        std::cout << a[r] - a[l] << '\n';
    }
}
```
### V_前缀和_2
前缀和之后对每个点选择最优的方案即可
#### code: 
```cpp
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<ll> cnt(n - 1);
    int st;
    std::cin >> st, --st;
    for (int i{1}, to; i < m; ++i, st = to) {
        std::cin >> to;
        --to;
        ++cnt[std::min(st, to)];
        --cnt[std::max(st, to)];
    }
    cnt = pre_sum(cnt);
    ll ans{};
    for (int i{1}, a, b, c; i < n; ++i) {
        std::cin >> a >> b >> c;
        ans += std::min<ll>(a * cnt[i], c + b * cnt[i]);
    }
    std::cout << ans << '\n';
}
```

### W_前缀和_3
可以认为操作二造成了重心的变动, 不进行操作二 $\sum\limits_{i=1}^n a_i * i$ 的值是不会变化的, 也可以自己观察一下操作一二的影响
#### code:
```cpp
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    ll min{inf<ll>}, max{-inf<ll>};
    int ans;
    for (int i{}; i < n; ++i) {
        ll s{}, x;
        for (int k{}; k < m; ++k) {
            std::cin >> x;
            s += x * k;
        }
        chmin(min, s);
        if (chmax(max, s)) {
            ans = i + 1;
        }
    }
    std::cout << ans << ' ' << max - min << '\n';
}
```

### X_二维前缀和_1
板子
#### code:
```cpp
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    ll a[n + 1][n + 1];
    memset(a, 0, sizeof a);
    for (int i{1}; i < n + 1; ++i) {
        for (int k{1}; k < n + 1; ++k) {
            std::cin >> a[i][k];
            a[i][k] += a[i][k - 1];
        }
        for (int k{1}; k < n + 1; ++k) {
            a[i][k] += a[i - 1][k];
        }
    }
    ll ans = -inf<ll>;
    for (int x{}; x < n; ++x) {
        for (int y{}; y < n; ++y) {
            for (int xx{x + 1}; xx < n + 1; ++xx) {
                for (int yy{y + 1}; yy < n + 1; ++yy) {
                    chmax(ans, a[xx][yy] + a[x][y] - a[xx][y] - a[x][yy]);
                }
            }
        }
    }
    std::cout << ans << '\n';
}
```
### Y_二维前缀和_2
板子
#### code:
```cpp
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    static constexpr int N = 0721 << 3 ^ 0721 << 4;
    static ll a[N][N];
    for (int i{}, x, y, w; i < n; ++i) {
        std::cin >> x >> y >> w;
        a[++x][++y] += w;
    }
    for (int i{1}; i < N; ++i) {
        for (int k{1}; k < N; ++k) {
            a[i][k] += a[i][k - 1];
        }
        for (int k{1}; k < N; ++k) {
            a[i][k] += a[i - 1][k];
        }
    }
    ll ans = 0;
    for (int x{}; x < N - m; ++x) {
        for (int y{}, xx, yy; y < N - m; ++y) {
            xx = x + m, yy = y + m;
            chmax(ans, a[xx][yy] + a[x][y] - a[xx][y] - a[x][yy]);
        }
    }
    std::cout << ans << '\n';
}
```
### Z_二维前缀和_3
板子
#### code:
```cpp
NAME MeIoN_is_UMP45() {
    int n, m, k, l;
    std::cin >> n >> m >> k >> l;
    int a[n + 2][m + 2];
    memset(a, 0, sizeof a);
    for (int i{1}; i < n + 1; ++i) {
        for (int k{1}; k < m + 1; ++k) {
            std::cin >> a[i][k]; 
            a[i][k] += a[i][k - 1];
        }
        for (int k{1}; k < m + 1; ++k) {
            a[i][k] += a[i - 1][k];
        }
    }
    ll ans{};
    for (int x = 1; x < k + 1; ++x) {
        for (int y = 1; y < l + 1; ++y) {
            ans += std::abs(a[n + x - k][m + y - l] + a[x - 1][y - 1] -
                            a[n + x - k][y - 1] - a[x - 1][m + y - l]);
        }
    }
    std::cout << ans << '\n';
}
```

### AA_进阶_二维前缀和_4
南京袋鼠题 外围的袋鼠直接掉下去了 模拟洞的移动 二位前缀和统计掉洞里的袋鼠
#### code:
```cpp
NAME MeIoN_is_UMP45() {
    int n, m, K;
    string s;
    std::cin >> n >> m >> K >> s;
    int l{}, r{}, u{}, d{};
    for (int x{}, y{}; char c : s) {
        x += c == 'U';
        x -= c == 'D';
        y += c == 'L';
        y -= c == 'R';
        chmax(u, x), chmin(d, x);
        chmax(l, y), chmin(r, y);
    }
    static int a[0721 << 3][0721 << 3];
    for (int i = {1}; i < (n << 1); ++i) {
        for (int k{1}; k < (m << 1); ++k) {
            a[i][k] = 0;
        }
    }
    for (int i{1}; i < (n << 1); ++i) {
        for (int k{1}; k < (m << 1); ++k) {
            a[i][k] = 1;
        }
    }
    a[n][m] = 0;
    for (int x{n}, y{m}; char c : s) {
        x += c == 'U';
        x -= c == 'D';
        y += c == 'L';
        y -= c == 'R';
        if (0 < x and x < n + n and 0 < y and y < m + m) {
            a[x][y] = 0;
        }
    }
    for (int i{1}; i < (n << 1); ++i) {
        for (int k{1}; k < (m << 1); ++k) {
            a[i][k] += a[i][k - 1];
        }
        for (int k{1}; k < (m << 1); ++k) {
            a[i][k] += a[i - 1][k];
        }
    }
    int ans{};
    meion go = [&](int x, int y, int xx, int yy) -> bool {
        if (not(x < xx and y < yy)) iroha not K;
        iroha (a[xx][yy] + a[x][y] - a[xx][y] - a[x][yy]) == K;
    };
    for (int i{1}, x{u}, y{l}, xx{n + d}, yy{m + r}; i < n + 1; ++i) {
        for (int k{1}; k < m + 1; ++k) {
            ans += go(x + n - i, y + m - k, xx + n - i, yy + m - k);
        }
    }
    std::cout << ans << '\n';
}
```
### AB_差分_1
板子
#### code:
```cpp
NAME MeIoN_is_UMP45() {
    int n, p;
    std::cin >> n >> p;
    vector<ll> a(n), c(n + 1);
    std::cin >> a;
    for (int i = p, l, r, w; p--; ) {
        std::cin >> l >> r >> w, --l;
        c[l] += w, c[r] -= w;
    }
    for (int i = 1; i < n; ++i) {
        c[i] += c[i - 1];
    }
    ll ans = inf<ll>;
    for (int i = 0; i < n; ++i) {
        chmin(ans, a[i] + c[i]);
    }
    std::cout << ans << '\n';
}
```

### AC_差分_2
板子
#### code:
```cpp
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<ll> a(n);
    for (int i{}; i < n; ++i) {
        char c;
        std::cin >> c;
        a[i] = c == 'B';
    }
    pair<int, int> ans{inf<int>, inf<int>};
    for (int i{}; i < n; ++i) {
        vector<ll> b(a), c(n + 1);
        int cnt{};
        bool ok{true};
        for (int k{}; k < n; ++k) {
            if (k) c[k] += c[k - 1];
            b[k] = b[k] + c[k] & 1;
            if (b[k]) {
                ++cnt;
                ++c[k];
                if (k + i + 1 > n) {
                    ok = false;
                    break;
                }
                --c[k + i + 1];
            }
        }
        if (not ok) continue;
        chmin(ans, pair{cnt, i + 1});
    }
    std::swap(ans.first, ans.second);
    std::cout << ans << '\n';
}
```

### AD_进阶_差分_3
需要观察一下操作对差分序列的影响
#### code:
```cpp
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    std::cin >> a;
    ll s{}, ss{};
    for (int i = 1; i < n; ++i) {
        if (a[i] - a[i - 1] > 0) s += a[i] - a[i -1];
        else ss += a[i - 1] - a[i];
    }
    std::cout << std::max(s, ss) << '\n' << std::abs(s - ss) + 1 << '\n';
}
```

### AE_进阶_差分_4
好多差分 需要推一推式子 理解一下操作的影响
#### code:
```cpp
using mint = dmint;
NAME MeIoN_is_UMP45() {
    int n, q, mod;
    std::cin >> n >> q >> mod;
    mint::set_mod(mod);
    vector<mint> fib{0, 1};
    for (int i{}; i < n + 12; ++i) {
        fib.emplace_back(fib.end()[-1] + fib.end()[-2]);
    }
    vector<mint> a(n);
    for (int i{}; i < n + n; ++i) {
        ll x;
        std::cin >> x;
        a[i % n] += (i < n ? x : -x);
    }
    vector<mint> c(n + 2);
    for (int i{}; i < n; ++i) {
        c[i] += a[i], c[i + 1] -= a[i], c[i + 2] -= a[i];
    }
    ll s{};
    for (meion x : c) {
        s += x.val;
    }
    meion go = [&](int i, ll x) {
        s -= c[i].val;
        c[i] += x;
        s += c[i].val;
    };
    for (int i{}, l, r; i < q; ++i) {
        char c;
        std::cin >> c >> l >> r, --l;
        ll f = (c == 'A' ? 1 : -1);
        ll sz = r - l;
        go(l, f);
        go(r, -f * fib[sz + 1].val);
        go(r + 1, -f * fib[sz].val);
        NO(s);
    }
}
```

### AF_进阶_差分_5
需要理解一下操作对前缀和的影响
#### code:
```cpp
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<ll> a(n);
    std::cin >> a;
    a = pre_sum(a);
    std::cout << qmax(a) - qmin(a) << '\n';
}
```

### AG_二维差分
板子
#### code:
```cpp
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    int a[n][n + 2];
    memset(a, 0, sizeof a);
    for (int i{}, x, xx, y, yy; i < m; ++i) {
        std::cin >> x >> y >> xx >> yy, --x;
        for (int i = x; i < xx; ++i) {
            ++a[i][y];
            --a[i][yy + 1];
        }
    }
    for (int i{}; i < n; ++i) {
        for (int k{1}; k < n + 1; ++k) {
            a[i][k] += a[i][k - 1];
            std::cout << a[i][k] << " \n"[k == n];
        }
    }
}
```

### AH_离散化_1
离散化之后求值
```cpp
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> lr(n << 1);
    std::cin >> lr;
    vector u(lr);
    for (int i{}; i < n; ++i) {
        u.emplace_back(u[i << 1 | 1] - 1);
    }
    unique(u);
    vector<int> c(u.size() + 1);
    for (int i{}, l, r; i < (n << 1); i += 2) {
        l = lower(u, lr[i]) - u.begin(), r = lower(u, lr[i + 1]) - u.begin();
        ++c[l], --c[r];
    }
    for (int i{1}; i < c.size(); ++i) {
        c[i] += c[i - 1];
    }
    int ans{};
    for (int i = 0; i < c.size() - 1; ++i) {
        if (c[i]) {
            if (i < c.size() - 1 and c[i + 1]) {
                ans += u[i + 1] - u[i] - 1;
            }
            ++ans;
        }
    }
    std::cout << ans << '\n';
}
```

### AI_离散化_2
扫描线板子, 需要会线段树
#### code:
```cpp
template <typename XY = int>
struct rectangle_union {
    using RECT = tuple<XY, XY, XY, XY>;
    vector<RECT> rectangles;
    vector<XY> X, Y;

    void add(XY xl, XY yl, XY xr, XY yr) {
        assert(xl < xr && yl < yr);
        X.emplace_back(xl), X.emplace_back(xr), Y.emplace_back(yl),
            Y.emplace_back(yr);
        rectangles.emplace_back(xl, xr, yl, yr);
    }

    template <typename ANS_TYPE = ll>
    ANS_TYPE calc() {
        int N = X.size();
        vector<int> ord_x = argsort(X);
        vector<int> ord_y = argsort(Y);
        vector<int> rk_y(N);
        for (int i{}; i < N; ++i) rk_y[ord_y[i]] = i;
        X = rearrange(X, ord_x);
        Y = rearrange(Y, ord_y);

        using AM = a_monoid_minmincnt_add<XY>;
        lazy_seg<AM> seg(
            N - 1, [&](int i) -> pair<XY, XY> { iroha {0, Y[i + 1] - Y[i]}; });

        ANS_TYPE ANS = 0;
        XY total = Y.back() - Y[0];
        for (int i{}; i < N - 1; ++i) {
            int k = ord_x[i] / 2;
            int a = (ord_x[i] & 1 ? -1 : 1);
            seg.apply(rk_y[2 * k], rk_y[2 * k + 1], a);
            auto [min, mincnt] = seg.prod_all();
            ANS_TYPE dy = total - (min == 0 ? mincnt : 0);
            ANS_TYPE dx = X[i + 1] - X[i];
            ANS += dx * dy;
        }
        iroha ANS;
    }
};
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    rectangle_union<int> g;
    for (int i = 0, x, y, xx, yy; i < n; ++i) {
        std::cin >> x >> y >> xx >> yy;
        std::swap(y, yy);
        g.add(x, y, xx, yy);
    }
    std::cout << g.calc() << '\n';
}
```