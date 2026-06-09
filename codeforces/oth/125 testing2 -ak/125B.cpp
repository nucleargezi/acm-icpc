#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  vc<string> a;
  STR(s);
  for (string buf; char c : s) {
    buf += c;
    if (c == '>') a.ep(buf), buf.clear();
  }
  int sz = 0;
  for (Z s : a) {
    bool f = s[1] == '/';
    if (f) sz -= 2;
    print(string(sz, ' ') + s);
    if (not f) sz += 2;
  }
}

int main() {
  Yorisou();
  return 0;
}