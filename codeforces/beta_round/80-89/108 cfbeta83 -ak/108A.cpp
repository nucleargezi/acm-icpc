#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

string to(int x) {
  string s = to_string(x);
  while (si(s) < 2) s = '0' + s;
  return s;
}
string rev(string s) { return reverse(s), s; }
void Yorisou() {
  STR(s);
  FOR(i, 5) s[i] -= '0';
  int a = s[0] * 10 + s[1], b = s[3] * 10 + s[4];
  while (1) {
    ++b;
    if (b > 59) b -= 60, ++a;
    if (a > 23) a -= 24;
    if (to(a) == rev(to(b))) return put(to(a), ":", to(b));
  }
}

int main() {
  Yorisou();
  return 0;
}