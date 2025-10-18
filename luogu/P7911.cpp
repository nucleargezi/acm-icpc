#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
bool check(const string &s) {
  string dot;
  for (char c : s) if (c == '.' or c == ':') dot += c;
  if (dot != "...:") return false;
  string n;
  for (char c : s) {
    if (c == '.' or c == ':') {
      if (n.empty()) return false;
      if (len(n) > 5) return false;
      int x = std::stoi(n);
      if (to_s(x) != n) return false;
      if (x < 0 or x > 255) return false;
      n.clear();
    } else {
      n += c;
    }
  }
  if (len(n) > 5 or n.empty()) return false;
  int x = std::stoi(n);
  if (to_s(x) != n) return false;
  if (x < 0 or x > 65535) return false;
  return true;
}
void Yorisou() {
  INT(N);
  map<string, int> mp;
  FOR(i, N) {
    STR(op, s);
    if (not check(s)) {
      print("ERR");
    } else if (op[0] == 'S') {
      if (mp.contains(s)) print("FAIL");
      else print("OK"), mp[s] = i + 1;
    } else {
      if (mp.contains(s)) print(mp[s]);
      else print("FAIL");
    }
  }
}
#include "YRS/Z_H/main.hpp"