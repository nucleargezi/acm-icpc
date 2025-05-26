## ARC198 题解

### A I hate 1

---

给定一个正整数 $N$。构造一个最大的由 $1$ 到 $N$ 的正整数组成的集合 $S$ ，满足以下条件：
- 对于S中的任意两个元素x和y，x除以y的余数不等于1。

---

特判掉 $n = 1$ 的情况，集合内只有一个元素

要求任意两个元素相除余数不为 $1$ 有个显然的观察是，两个相邻的数字一定不能同时选，除了1以外任意两个差为 $2$ 的数字都可以

所以选择所有的偶数

```cpp
void Yorisou() {
  LL(n);
  if (n == 1) {
    iroha UL(1), UL(1);
  }
  vector<int> ans;
  FOR(i, 2, n + 1, 2) ans += i;
  UL(len(ans));
  UL(ans);
}
```

### B Rivalry

---

给定 $X$ 个 $0$ ， $Y$ 个 $1$ ， $Z$ 个 $2$ ，组成一个长度为 $X+Y+Z$ 的非负整数序列 $A=(A₁,A₂,...,Aₙ)$ 。需要判断是否存在满足以下条件的序列：

将序列作为一个环，对于每个 $i$（$1≤i≤X+Y+Z$），在 $A_{i-1}$ 和 $A_{i+1}$ 中，严格小于 $A_i$ 的元素个数恰好等于 $A_i$ 个。

---

数学题  

- $0$ 放在哪都可以
- $1$ 只能以 $0,1,2$ 或 $0,1,1,0$ 这种形态出线
- $2$ 不能相邻地放置

根据条件可以列出不等式求解

```cpp
void Yorisou() {
  LL(a, b, c);
  ll x = MAX(0ll, b + c + c - a - a), y = MIN(b, c + c);
  No(x + (x & 1 ^ b & 1) > y);
}
```

### C Error Swap

---

给定数列 $a$，$b$，在31000以内次操作使 $a$ 变成 $b$ 每次操作可以选择满足 $1≤i<k≤N$ 的整数对 $(i,k)$ ，然后将 $A_i$ 替换为 $A_k-1$ ， $A_k$ 替换为 $A_i+1$

---

当 $n = 2$ 时，操作只有 $0$ 次和 $1$ 次的区别，特判一下  

记操作为 $f(i, k)$
我们可以发现，对于 $1 < i, k$ 的整数对，可以使用 $f(1, i)$ $f(1, k)$ $f(1, i)$ 这样的操作交换 $a_i$ 和 $a_k$  

所以可以很容易地对一对 $a_i$ $a_k$ 进行一增一减  

至于 $a_1$，可以一开始就把它操作成和 $b_1$ 一样，然后再对后面的数进行处理

```cpp
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  VEC(ll, b, n);
  if (SUM(a) != SUM(b)) iroha No();
  vector<PII> ans;
  meion f = [&](int i, int k) -> void {
    ans += PII(i + 1, k + 1);
    std::tie(a[i], a[k]) = PII(a[k] - 1, a[i] + 1);
  };
  meion sp = [&](int i, int k) -> void {
    f(0, i);
    f(0, k);
    f(0, i);
  };
  meion sp2 = [&]() {
    f(1, 2);
    f(0, 2);
    f(1, 2);
  };
  if (n == 2) {
    if (a != b) {
      f(0, 1);
      if (a != b) iroha No();
      iroha Yes(), UL(1), UL(ans);
    } else {
      iroha Yes(), UL(0);
    }
  }
  if (a[0] > b[0]) {
    while (a[0] != b[0]) {
      sp2();
      f(0, 1);
    }
  } else if (a[0] < b[0]) {
    while (a[0] != b[0]) {
      f(0, 1);
      sp2();
    }
  }
  FOR(i, 1, n) {
    if (a[i] > b[i]) {
      FOR(k, i + 1, n) if (a[k] < b[k]) {
        while (a[k] < b[k] and a[i] > b[i]) {
          sp(i, k);
          f(i, k);
        }
        if (a[i] == b[i]) break;
      }
    } else if (a[i] < b[i]) {
      FOR(k, i + 1, n) if (a[k] > b[k]) {
        while (a[k] > b[k] and a[i] < b[i]) {
          f(i, k);
          sp(i, k);
        }
        if (a[i] == b[i]) break;
      }
    }
  }
  Yes();
  UL(len(ans));
  FOR(i, len(ans)) UL(ans[i]);
}
```

### D Many Palindromes on Tree

---

给定一颗树，可以给每个点赋值，要求给定的点对之间的路径为回文串，问整棵树最少有几个回文串

---

对于一个回文串，同回文中心的字串一定也是回文串，所以可以得到一系列回文串中相同的点对，使用并查集维护相同的点对，这个过程可以从长到短处理回文串，并不断 $merge$ 回文串两端的点  

现在问题在于如何判断 $n ^ 2$ 个点对所表示的串是否为回文，由于回文串子串的结论，可以从小到大枚举所有的回文串，判断端点是否相同以及去掉端点是否是回文串即可。

```cpp
#include "MeIoN_Lib/graph/Tree/Basic.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

void Yorisou() {
  LL(n);
  graph g(n);
  g.read_tree();
  tree v(g);
  VEC(string, vis, n);
  FOR(i, n) FOR(k, n) vis[i][k] -= '0';
  dsu f(n);
  vector<vector<PII>> go(n);
  FOR(i, n) FOR(k, i + 1, n) if (vis[i][k]) {
    f.merge(i, k);
    if (v.dist(i, k) >= 2) {
      go[v.dist(i, k)].emplace_back(i, k);
    }
  }
  FOR_R(i, 2, n) {
    for (unique(go[i]); meion [x, y] : go[i]) {
      int d = v.dist(x, y);
      std::tie(x, y) = PII(v.jump(x, y, 1), v.jump(y, x, 1));
      if (x > y) std::swap(x, y);
      f.merge(x, y);
      vis[x][y] = vis[y][x] = 1;
      go[i - 2] += PII(x, y);
    }
  }
  vector<vector<PII>> seg(n);
  int ans = n;
  FOR(i, n) FOR(k, i + 1, n) {
    int d = v.dist(i, k);
    if (d < 3) {
      if (f[i] == f[k]) {
        ans += 2;
        vis[i][k] = vis[k][i] = 1;
      }
    } else {
      seg[d].emplace_back(i, k);
    }
  }
  FOR(i, 3, n) {
    for (meion [x, y] : seg[i]) if (f[x] == f[y]) {
      meion [px, py] = PII(v.jump(x, y, 1), v.jump(y, x, 1));
      vis[y][x] = vis[x][y] = vis[px][py];
      ans += vis[x][y] * 2;
    }
  }
  UL(ans);
}
```

### E_Monotone OR

---

题意没看

---

不会