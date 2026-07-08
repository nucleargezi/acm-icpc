#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  STR(s);
  int N = si(s);
  FOR(i, N) s[i] -= 'a';
  INT(K, L, R);
  vc<T3<int>> ops(K);
  FOR(i, K) {
    CH(op);
    op -= 'a';
    INT(l, r);
    ++r;
    ops[i] = {op, l, r};
  }
  vc<int> v[26];
  FOR(i, N) v[(int)s[i]].ep(i);
  FOR(i, 26) v[i].ep(N);

  vc<int> c(N + 1);
  static bitset<1'000'01> se;
  ll rs = 0;
  int of[26]{};
  FOR(i, N) {
    FOR(k, 26) if (v[k][of[k]] < i) ++of[k];
    Z f = [&](int c, int n) -> int {
      if (n == 0) return i;
      return v[c][min(of[c] + n - 1, int(si(v[c]) - 1))];
    };
    for (var [ch, l, r] : ops) {
      int a = f(ch, l), b = f(ch, r);
      ++c[a], --c[b];
      se.set(a), se.set(b);
    }
    se.set(N);
    for (int n = 0, p = i; p < N; ) {
      int t = se._Find_next(p - 1);
      se.reset(t);
      if (L <= n and n <= R) rs += t - p;
      p = t, n += c[p], c[p] = 0;
    }
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}