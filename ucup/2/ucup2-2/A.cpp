#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/subseq.hpp"

void Yorisou() {
  INT(N);
  STR(s);
  map<int, vc<int>> se;
  FOR(i, N) se[s[i]].ep(i);
  for (Z &[a, b] : se) b.ep(N), b.insert(bg(b), -1);
  Z gl = [&](char c, int x) -> int {
    var s = se[c];
    return s[lb(s, x) - 1];
  };
  Z gr = [&](char c, int x) -> int {
    var s = se[c];
    return s[ub(s, x)];
  };
  int rs = inf<int>;
  for (int c : se['b']) if (c != N and c != -1) {
    int a, b, d, e;
    b = gl('p', c);
    if (b == -1) continue;
    a = gl('s', b);
    if (a == -1) continue;
    d = gr('s', c);
    if (d == N) continue;
    e = gr('u', d);
    if (e == N) continue;
    chmin(rs, b - a - 1 + 2 * (c - b - 1 + d - c - 1) + e - d - 1);
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}