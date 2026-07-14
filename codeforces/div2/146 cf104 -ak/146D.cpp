#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(a, b, c, d);
  string s;

  Z f = [&](char f, int x, int y) {
    if (a < x or b < y) return;
    string t;
    t.reserve(a + b);
    int p = 0, q = 0;
    FOR(x + y) {
      if (f == '4') {
        int g = 1;
        if (p == 0) g += a - x;
        t += string(g, '4');
        ++p;
      } else {
        int g = 1;
        if (q == y - 1) g += b - y;
        t += string(g, '7');
        ++q;
      }
      f = (f == '4' ? '7' : '4');
    }
    if (s.empty() or t < s) s = t;
  };

  if (c == d) {
    f('4', c + 1, c), f('7', c, c + 1);
  } else if (c == d + 1) {
    f('4', c, c);
  } else if (d == c + 1) {
    f('7', d, d);
  }
  if (s.empty()) print(-1);
  else print(s);
}

int main() {
  Yorisou();
  return 0;
}