#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  STR(s);
  ull p = s.find('.');
  if (p == -1ull) s += ".00", p = s.find('.');
  string ls(s.substr(0, p)), rs(s.substr(p + 1));
  while (si(rs) > 2) pop(rs);
  while (si(rs) < 2) rs += '0';
  bool f = s[0] == '-';
  ls = ls.substr(f);
  int n = si(ls);
  string ans;
  FOR(i, n) {
    ans += ls[i];
    if ((n - i - 1) % 3 == 0) ans += ',';
  }
  ans.back() = '.';
  ans = "$" + ans + rs;
  if (f) ans = "(" + ans + ")";
  print(ans);
}

int main() {
  Yorisou();
  return 0;
}