#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

using T = bitset<64>;
void Yorisou() {
  INT(N, M, K);
  T mp{}, a[8]{};
  int n[8]{}, m[8]{}, sz[8]{};
  FOR(i, N) {
    STR(s);
    FOR(k, M) if (s[k] == '#') mp.set(i * 8 + k);
  }
  int B = N * M - mp.count();

  FOR(t, K) {
    IN(n[t], m[t]);
    FOR(i, n[t]) {
      STR(s);
      FOR(k, m[t]) if (s[k] == '#') a[t].set(i * 8 + k);
    }
    sz[t] = a[t].count();
  }

  vc<int> f;
  Z hs = [&]() {
    sort(f);
    ull s = 0;
    for (int a : f) s = (s * 123 + a + 10);
    return s;
  };

  Z ck = [&](int i, int x, int y) { return n[i] + x <= N and m[i] + y <= M; };
  Z tr = [&](int i, int x, int y) { return a[i] << (x * 8 + y); };
  Z me = [&](T a, T b) { return not (a & b).any(); };

  vc<int> I;
  vc<ull> rs;
  FOR(s, 1 << K) {
    I.clear();
    int sm = 0;
    FOR(k, K) if (s >> k & 1) sm += sz[k], I.ep(k);
    if (sm != B) continue;
    do {
      T c = mp;
      f.clear();
      for (int i : I) {
        FOR(x, N) FOR(y, M) if (ck(i, x, y)) {
          T g = tr(i, x, y);
          if (me(c, g)) {
            c |= g, f.ep(i << 24 | x << 12 | y);
            goto MyGO;
          }
        }
        goto MyGo;
      MyGO:;
      }
      rs.ep(hs());
    MyGo:;
    } while (next_permutation(all(I)));
  }
  unique(rs); 
  print(si(rs));
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}