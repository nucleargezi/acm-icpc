#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, M, R, G, B);
  VEC(PII, a, M);
  for (Z &[l, r] : a) --l;
  sort(a, [&](var a, var b) { return a.se - a.fi > b.se - b.fi; });
  string s(N, ' ');
  vc<pair<int, char>> st{{R, 'R'}, {G, 'G'}, {B, 'B'}};
  for (var [l, r] : a) {
    sort(st);
    int sz = r - l;
    Z &[x, c0] = st[0];
    Z &[y, c1] = st[2];
    if (x + y < r - l) {
      Z &[z, c2] = st[1];
      int d = min(sz, z);
      z -= d;
      sz -= d;
      y -= sz;
      if (y < 0) return print(-1);
      FOR(i, d) s[l + i] = c2;
      FOR(i, sz) s[l + i + d] = c1;
    } else {
      int d = min(sz, x);
      x -= d;
      sz -= d;
      y -= sz;
      FOR(i, d) s[l + i] = c0;
      FOR(i, sz) s[l + i + d] = c1;
    }
  }
  string rs;
  for (var [sz, c] : st) FOR(sz) rs += c;
  FOR(i, N) if (s[i] == ' ') s[i] = pop(rs);
  print(s);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}