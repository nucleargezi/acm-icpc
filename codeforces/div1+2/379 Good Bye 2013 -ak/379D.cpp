#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

string ge(int n, int c, int fs, int ls) {
  string s;
  if (fs) s += 'C';
  FOR(c) s += "AC";
  while (si(s) < n - ls) s += 'B';
  if (ls) s += 'A';
  return s;
}

void Yorisou() {
  INT(k, x, n, m);
  FOR(a, ceil(n + 1, 2)) FOR(b, ceil(m + 1, 2)) {
    FOR(f1, 2) FOR(l1, 2) {
      if (2 * a + f1 + l1 > n) continue;
      FOR(f2, 2) FOR(l2, 2) {
        if (2 * b + f2 + l2 > m) continue;
        ll c[50]{a, b};
        int fs[50]{f1, f2}, ls[50]{l1, l2};
        FOR(i, 2, k) {
          c[i] = c[i - 2] + c[i - 1] + ls[i - 2] * fs[i - 1];
          fs[i] = fs[i - 2], ls[i] = ls[i - 1];
        }
        if (c[k - 1] == x) {
          return print(ge(n, a, f1, l1)), print(ge(m, b, f2, l2));
        }
      }
    }
  }
  print("Happy new year!");
}

int main() {
  Yorisou();
  return 0;
}