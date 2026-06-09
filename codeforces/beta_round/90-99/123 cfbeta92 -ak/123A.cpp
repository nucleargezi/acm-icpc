#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/un/dsu.hpp"
#include "YRS/pr/ptable.hpp"

void Yorisou() {
  STR(s);
  int N = si(s);
  vc<int> c(26);
  for (char x : s) c[x - 'a'] += 1;
  dsu g(N);
  for (int x : ptable(N)) {
    FOR(i, x - 1, N - x, x) {
      g.merge(i, i + x);
    }
  }
  Z f = g.group();
  sort(f, [&](var a, var b) { return si(a) > si(b); });
  for (var v : f) {
    int t = -1;
    for (int i : argsort(c)) {
      if (c[i] >= si(v)){
        c[i] -= si(v);
        t = i;
        break;
      }
    }
    if (t == -1) return NO();
    for (int i : v) s[i] = t + 'a';
  }
  YES();
  print(s);
}

int main() {
  Yorisou();
  return 0;
}