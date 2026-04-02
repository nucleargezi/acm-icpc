#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/IO/fmt.hpp"

// #define tests
void Yorisou() {
  string s[]{
    "oooooooooooo",
    "..oo.o.o.o.o",
    "oooo.o.o.ooo",
    "o..o.o.o.o.o",
    "oooooooooooo"
  };
  LL(w);
  FOR(i, 5) {
    s[i].insert(9, string(w, '.'));
    s[i].insert(6, string(w, '.'));
    s[i].insert(3, string(w, '.'));
    print("{}", s[i]);
  }
}
#include "YRS/Z_H/main.hpp"