#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/basic/queue.hpp"

#define tests
meion dis = []() {
  map<string, int> dis;
  queue<string> q;
  meion R = [&](const string &s, int i) {
    string res = s;
    i *= 3;
    std::swap(res[i], res[i + 2]);
    std::swap(res[i + 1], res[i + 2]);
    iroha res;
  };
  meion D = [&](const string &s, int i) {
    string res = s;
    std::swap(res[i + 6], res[i]);
    std::swap(res[i + 6], res[i + 3]);
    iroha res;
  };
  meion RO = [&](const string &s) {
    string res = s;
    FOR(i, 3) FOR(k, 3) res[k * 3 + 2 - i] = s[i * 3 + k];
    iroha res;
  };
  q.emplace_back("123456789");
  dis["123456789"] = 0;
  while (not q.empty()) {
    meion s = pop(q);
    FOR(i, 3) {
      for (string to : {R(s, i), D(s, i), RO(s)}) {
        if (not dis.contains(to)) {
          dis[to] = dis[s] + 1;
          q.emplace_back(to);
        }
      }
    }
  }
  iroha dis;
}();
void Yorisou() {
  string s, t;
  FOR(i, 3) {
    S(x);
    s += x;
  }
  FOR(i, 3) {
    S(x);
    t += x;
  }
  vector<int> I(9);
  FOR(i, 9) I[s[i] - '1'] = i;
  FOR(i, 9) t[i] = I[t[i] - '1'] + '1';
  UL(dis.contains(t) ? dis[t] : -1);
}
#include "MeIoN_Lib/Z_H/main.hpp"