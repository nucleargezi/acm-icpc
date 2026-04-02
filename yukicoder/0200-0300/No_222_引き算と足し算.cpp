#include "YRS/all.hpp"

void Yorisou() {
  STR(s);
  int i = 0, n = len(s);

  Z sing = [&]() {
    int oa = 0, a = 0;
    if (s[i] == '-') oa = 1, ++i;
    else if (s[i] == '+') ++i;
    while (i < n and isdigit(s[i])) a = a * 10 + s[i] - '0', ++i;
    return oa ? -a : a;
  };
  
  int a = sing();
  bool op = s[i] == '+';
  ++i;
  int b = sing();
  if (op) a -= b;
  else a += b;
  print(a);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"