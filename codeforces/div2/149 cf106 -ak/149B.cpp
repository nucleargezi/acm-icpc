#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  STR(s);
  int x(s.find(':'));
  string a(s.substr(0, x)), b(s.substr(x + 1));
  for (char &c : a) c -= isdigit(c) ? '0' : 'A' - 10;
  for (char &c : b) c -= isdigit(c) ? '0' : 'A' - 10;
  
  Z f = [&](int bs) {
    for (int s = 0; int x : a) if ((s = s * bs + x) >= 24) return 0;
    for (int s = 0; int x : b) if ((s = s * bs + x) >= 60) return 0;
    return 1;
  };
  if (f(60)) return print(-1);
  int ma(QMAX(a)), mb(QMAX(b));
  vc<int> rs;
  FOR(i, max(ma, mb) + 1, 60) if (f(i)) rs.ep(i);
  if (rs.empty()) print(0);
  else print(rs);
}

int main() {
  Yorisou();
  return 0;
}