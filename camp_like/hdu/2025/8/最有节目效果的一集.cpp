#include <unordered_map>
#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/basic/queue.hpp"
#include "MeIoN_Lib/ds/basic/pbds.hpp"

#define tests
struct dat {
  int win, sc;
  string s;
};
void Yorisou() {
  INT(N, q);
  std::unordered_map<string, int> tid;
  std::unordered_map<string, int> to;
  vector<int> gpid(N * 3);
  vector<string> tname(N * 3);
  vector<dat> record(N * 3);
  RKT<tuple<int, int, string>> rk[3];
  for (int i = 0; i < N * 3; ++i) {
    IN(tname[i]);
    tid[tname[i]] = i;
    for (int j = 0; j < 5; ++j) {
      S(man);
      to[man] = i;
    }
    INT(x);
    --x;
    gpid[i] = x;
    record[i] = {0, 0, tname[i]};
    rk[x].insert({0, 0, tname[i]});
  }

  vector<T4<int>> mess;
  vector<u8> fake;
  vector cp(N * 3, vector(N * 3, queue<int>()));

  meion upd = [&](int tid, int dwin, int dsc) -> void {
    meion &[win, sc, s] = record[tid];
    int gp = gpid[tid];
    rk[gp].erase({-win, -sc, s});
    win += dwin;
    sc += dsc;
    rk[gp].insert({-win, -sc, s});
  };
  
  while (q--) {
    INT(op);
    if (op == 1) {
      string TA, TB, t;
      int A, B, taid, tbid;
      for (int i = 0; i < 14; ++i) {
        IN(t);
        if (i == 3) {
          t.pop_back();
          if (tid.contains(t)) {
            TA = t;
            taid = tid[TA];
          } else {
            taid = to[t];
            TA = tname[taid];
          }
        } else if (i == 11) {
          TB = t;
          tbid = tid[TB];
        } else if (i == 13) {
          A = t[0] - '0';
          B = t[2] - '0';
        }
      }
      if (gpid[taid] != gpid[tbid]) {
        mess.emplace_back();
        fake.emplace_back(1);
        continue;
      }
      if (taid > tbid) {
        swap(taid, tbid);
        swap(TA, TB);
        swap(A, B);
      }
      mess.emplace_back(taid, A, tbid, B);
      fake.emplace_back(0);
      cp[taid][tbid].emplace_back(len(mess) - 1);
      if (len(cp[taid][tbid]) == 1) {
        upd(taid, A > B, A - B);
        upd(tbid, B > A, B - A);
      }
    } else if (op == 2) {
      INT(id);
      --id;
      if (fake[id]) continue;
      fake[id] = 1;
      meion [taid, A, tbid, B] = mess[id];
      meion &q = cp[taid][tbid];
      int f = 0;
      while (not q.empty()) {
        meion mid = q.front();
        if (fake[mid]) {
          q.pop();
          if (not f) {
            f = 1;
            meion[taid, A, tbid, B] = mess[mid];
            upd(taid, A > B ? -1 : 0, B - A);
            upd(tbid, B > A ? -1 : 0, A - B);
          }
        } else {
          break;
        }
      }
      if (f and not q.empty()) {
        meion [taid, A, tbid, B] = mess[q.front()];
        upd(taid, A > B, A - B);
        upd(tbid, B > A, B - A);
      }
    } else {
      INT(id);
      --id;
      int gp = gpid[id];
      meion dat = record[id];
      UL(1 + (int)rk[gp].order_of_key({-dat.win, -dat.sc, dat.s}));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"