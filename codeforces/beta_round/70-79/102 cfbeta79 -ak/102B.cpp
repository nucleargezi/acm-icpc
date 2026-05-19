#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  STR(s);
  vc<int> a(all(s));
  for (int &x : a) x -= '0';
  int rs = 0;
  while (si(a) > 1) {
    ++rs;
    int s = SUM<int>(a);
    a.clear();
    while (s) a.ep(s % 10), s /= 10;
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}