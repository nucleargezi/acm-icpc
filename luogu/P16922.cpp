#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/run_length.hpp"

map<char, int> mp;
void Yorisou() {
  vc<int> f;
  FOR(17) {
    STR(s);
    if (si(s) == 1) {
      if (isdigit(s[0])) f.ep(s[0] - '0');
      else f.ep(mp[s[0]]);
    } else if (s == "10") f.ep(10);
  }
  unique(f);
  if (si(f) and f[0] == 2) f.erase(bg(f));
  FOR_R(i, si(f)) f[i] -= i ? f[i - 1] : f[i];
  int rs = 0;
  for (var [a, b] : run_length(f)) {
    if (a == 1 and b + 1 > 4) chmax(rs, b + 1);
  }
  print(rs);
}

int main() {
  mp['J'] = 11;
  mp['Q'] = 12;
  mp['K'] = 13;
  mp['A'] = 14;
  INT(T);
  FOR(T) Yorisou();
  return 0;
}