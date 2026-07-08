#include "YRS/all.hpp"

void Yorisou() {
  cin.tie(0)->sync_with_stdio(0);
  string rs, s;
  for (string s; cin >> s; ) {
    if (isalpha(s[0])) {
      if (not rs.empty()) rs += ' ';
    }
    rs += s;
  }
  for (char c : rs) {
    if (c == ' ') {
      if (not s.empty() and s.back() == ' ') continue;
      s += c;
    } else if (not isalpha(c)) {
      s += c;
      s += ' ';
    } else {
      s += c;
    }
  }
  while (si(s) and s.back() == ' ') pop(s);
  print(s);
}

int main() {
  Yorisou();
  return 0;
}