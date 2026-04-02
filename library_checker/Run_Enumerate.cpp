#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/string/runs.hpp"

// #define tests
void Yorisou() {
  STR(s);
  Z res = runs(s);
  for (Z &[l, r , p] : res) {
    swap(r, p);
    swap(l, r);
  }
  sort(res);
  print(len(res));
  for (Z [p, l, r] : res) {
    print(p, l, r);
  }
}
#include "YRS/Z_H/main.hpp"