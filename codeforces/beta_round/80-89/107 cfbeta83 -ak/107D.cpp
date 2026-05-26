#include "YRS/all.hpp"
#include "YRS/ds/basic/hashmap.hpp"
#include "YRS/mod/binom.hpp"
#include "YRS/line/mat.hpp"

using mint = mint_t<12345>;
void Yorisou() {
  LL(N);
  INT(M);
  vc<vc<int>> v(26);
  FOR(M) {
    CH(c);
    INT(x);
    v[c - 'A'].ep(x);
  }
  sort(v, [&](var a, var b) { return si(a) > si(b); });
  Z cp = v;
  while (si(v) and si(v.back()) == 0) pop(v);
  int sz = si(v);
  vc<int> g(sz, 1);
  FOR(i, sz) for (int x : v[i]) g[i] *= x;
  v.clear();

  vc<int> st;
  Z f = [&](Z &f, int p) -> void {
    if (p == sz) return v.ep(st), void();
    FOR(i, g[p]) st.ep(i), f(f, p + 1), pop(st);
  };
  f(f, 0);
  int B = si(v);

  Z hsh = [&](const vc<int> &a) -> ull {
    u128 s = 0;
    for (ull x : a) s = (s * 131 + x + 10) % ((1ull << 61) - 1);
    return s;
  };
  hashmap<int> mp(B);
  FOR(i, B) mp[hsh(v[i])] = i;
  Z gi = [&](vc<int> s) -> int {
    FOR(i, sz) s[i] %= g[i];
    return mp[hsh(s)];
  };

  mat<mint> a(B);
  FOR(i, B) {
    Z &f = v[i];
    FOR(k, sz) {
      ++f[k];
      a[i][gi(f)] += 1;
      --f[k];
    }
  }
  a = a.pow(N);
  mint rs;
  FOR(i, B) {
    mint x = a[0][i];
    var s = v[i];
    FOR(k, sz) {
      for (int x : cp[k]) if (s[k] % x == 0) goto ok;
      goto fl;
    ok:;
    }
    rs += x;
  fl:;
  }
  print(rs);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  Yorisou();
  return 0;
}