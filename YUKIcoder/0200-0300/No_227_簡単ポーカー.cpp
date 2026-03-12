#include "YRS/all.hpp"

void Yorisou() {
  map<int, int> c;
  FOR(5) {
    INT(x);
    ++c[x];
  }
  vc<int> a;
  for (PII x : c) a.ep(x.se);
  sort(a);
  if (a == vc<int>{2, 3}) print("FULL HOUSE");
  else if (count(all(a), 3)) print("THREE CARD");
  else if (count(all(a), 2) == 2) print("TWO PAIR");
  else if (count(all(a), 2)) print("ONE PAIR");
  else print("NO HAND");
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"