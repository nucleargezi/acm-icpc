#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  vector<string> s;
  string e;
  while (IN(e)) {
    if (len(e) and e.back() == 'n') e += 'g';
    s.ep(e);
  }
  print(s);
}
#include "YRS/Z_H/main.hpp"