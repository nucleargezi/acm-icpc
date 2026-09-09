#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"

bool f(const string &s) {
  string t(s);
  reverse(t);
  return s == t;
}

void Yorisou() {
  STR(s);
  int n = si(s), m = (n - 1) / 2;
  Yes(f(s) and f(s.substr(0, m)) and f(s.substr(n - m)));
}

int main() { Yorisou(); }