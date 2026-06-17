#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  STR(s);
  for (char &c : s) c -= '0';
  s = char{} + s;
  vc<int> ad, rm;
  int c = 0;
  while (si(s) > 1) {
    if (not s.back()) {
      pop(s);
      ++c;
      continue;
    }
    bool f = s.end()[-2];
    (f ? rm : ad).ep(c);
    pop(s), pop(s);
    c += 2;
    if (f) {
      int i = si(s) - 1;
      while (s[i]) s[i--] = 0;
      s[i] = 1;
    }
  }
  if (si(s) and s[0]) ad.ep(c);
  print(si(ad) + si(rm));
  for (int i : ad) print("+2^" + to_string(i));
  for (int i : rm) print("-2^" + to_string(i));
}

int main() {
  Yorisou();
  return 0;
}