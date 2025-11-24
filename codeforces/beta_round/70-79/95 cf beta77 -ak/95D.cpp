#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/bigint/big.hpp"
#include "YRS/ds/basic/hashmap.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
using B = bigint;
using mint = M17;
hash_map<mint> mem, mp;
void Yorisou() {
  LL(T, k);
  vector<mint> bs(1'001, 1);
  FOR(i, 1, 1'001) bs[i] = bs[i - 1] * 10;
  static constexpr ull mod = (1ull << 61) - 1;
  Z f = [&](const B &x) -> mint {
    u128 h = 0;
    for (int x : x.to_string()) {
      x -= '0';
      h = h * 10 + x;
      h %= mod;
    }
    if (mp.contains(h)) return mp[h];

    string s = x.to_string();
    reverse(s);
    int sz = len(s);
    FOR(i, sz) s[i] -= '0';
    vector<mint> go(sz);
    FOR(i, sz) go[i] = s[i];
    FOR(i, 1, sz) go[i] = go[i - 1] + go[i] * bs[i];
    Z f = [&](Z &f, int p, bool ck, int dis, bool c) -> mint {
      if (not p) return c;
      if (c) return ck ? go[p - 1] + 1 : bs[p];
      ull h = (ull(p) << 30) | (dis << 2) | (ull(ck) << 1) | c;
      if (not ck and mem.contains(h)) return mem[h];
      int u = ck ? s[p - 1] : 9, d = 0, t[4]{};
      mint s = 0;
      FOR(i, d, u + 1) {
        int F = i == 4 or i == 7, FF = i == u and ck;
        ++t[F << 1 | FF];
      }
      FOR(i, 4) if (t[i]) {
        int F = i >> 1, FF = i & 1;
        s += f(f, p - 1, FF, F ? 0 : dis + 1, c | (F and dis < k)) * t[i];
      }
      if (not ck) mem[h] = s;
      return s;
    };
    return mp[h] = f(f, sz, 1, k + 1, 0);
  };
  B l, r;
  FOR(T) {
    STR(s, t);
    l = s, r = t;
    print((f(r) - f(l - 1)).val);
  }
}
#include "YRS/Z_H/main.hpp"