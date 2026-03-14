#include "YRS/all.hpp"

void Yorisou() {
  INT(T, y, x);
  vc<string> res;
  while ((x or y) and T) {
    string s;
    if (x) s += '>', --x;
    if (y) s += '^', --y;
    res.ep(s);
    --T;
  }
  if (not T and (x or y)) return NO();
  if (T & 1) {
    assert(not x and not y);
    if (res.empty()) {
      if (T == 1) return NO();
      T -= 3;
      res.ep(">");
      res.ep("^");
      res.ep("<v");
      while (T) T -= 2, res.ep(">"), res.ep("<");
    } else {
      if (len(res.back()) == 2) {
        string s = pop(res);
        res.ep(s.substr(0, 1));
        res.ep(s.substr(1, 1));
        --T;
        while (T) T -= 2, res.ep(">"), res.ep("<");
      } else {
        string s = pop(res);
        if (s == ">" or s == "<") s += '^', res.ep(s), res.ep("v");
        else s += '>', res.ep(s), res.ep("<");
        --T;
        while (T) T -= 2, res.ep(">"), res.ep("<");
      }
    }
  } else {
    while (T) T -= 2, res.ep(">"), res.ep("<");
  }
  YES();
  for (string s : res) print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"