#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/runs.hpp"

void Yorisou() {
  STR(s);
  Z res = runs(s);
  for (Z &[l, r , p] : res) {
    swap(r, p);
    swap(l, r);
  }
  sort(res);
  print(si(res));
  for (Z [p, l, r] : res) {
    print(p, l, r);
  }
}

int main() {
  Yorisou();
  return 0;
}