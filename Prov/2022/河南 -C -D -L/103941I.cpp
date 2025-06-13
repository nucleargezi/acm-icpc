#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
struct tra {
  ll op, i, x, y, z;
  vector<int> in;
};
struct go {
  ll id, t, x, y, z, xx, yy, zz;
};
void Yorisou() {
  LL(n, m, h, M);
  n, m, h;
  vector<tra> a;
  FOR(i, M) {
    LL(op, x, y, z);
    --x, --y, --z;
    a += tra{op, i, x, y, z, {}};
  }
  LL(N);
  vector<go> b;
  vector<u8> f(N);
  vector<u8> kd(N);
  vector<int> inc(N);
  FOR(i, N) {
    LL(t, x, y, z, xx, yy, zz);
    --x, --y, --z, --xx, --yy, --zz;
    b += go{i, t, x, y, z, xx, yy, zz};
    if (not kd[i] and x == xx) ++kd[i];
    if (kd[i] == 1 and y == yy) ++kd[i];
  }
  int tot = 0;
  int t = 0;
  while (tot != N) {
    ++t;
    vector<tuple<ll, ll, ll, ll, ll>> up, d;
    for (meion &[op, i, x, y, z, in] : a) {
      if (op == 0) {
        ++x;
        for (int id : in) {
          b[id].x++;
          b[id].x %= n;
        }
      }
      if (op == 1) {
        ++y;
        for (int id : in) {
          b[id].y++;
          b[id].y %= m;
        }
      }
      if (op == 2) {
        ++z;
        for (int id : in) {
          b[id].z++;
          b[id].z %= h;
        }
      }
      x %= n, y %= m, z %= h;
    }
    FOR(i, N) {
      if (not f[i]) {
        if (kd[i] == 3 or t < b[i].t) continue;
        for (meion &[op, id, x, y, z, in] : a) {
          if (x == b[i].x and y == b[i].y and z == b[i].z and op == kd[i]) {
            f[i] = op + 1;
            inc[i] = id;
            a[id].in.emplace_back(i);
            up.emplace_back(id, b[i].id, x, y, z);
            break;
          }
        }
      } else {
        if ((f[i] == 1 and b[i].x == b[i].xx) or
            (f[i] == 2 and b[i].y == b[i].yy) or
            (f[i] == 3 and b[i].z == b[i].zz)) {
          int cid = inc[i];
          d.emplace_back(cid, b[i].id, b[i].x, b[i].y, b[i].z);
          a[cid].in.erase(std::find(a[cid].in.begin(), a[cid].in.end(), i));
          inc[i] = 0;
          f[i] = 0;
          if (not kd[i] and b[i].x == b[i].xx) ++kd[i];
          if (kd[i] == 1 and b[i].y == b[i].yy) ++kd[i];
          if (kd[i] == 2 and b[i].z == b[i].zz) ++kd[i];
          if (kd[i] == 3) ++tot;
        }
      }
    }
    vector<tuple<ll, bool, ll, ll, ll, ll>> out;
    for (meion[x, y, a, b, c] : up) {
      out.emplace_back(x, 1, y, a, b, c);
    }
    for (meion[x, y, a, b, c] : d) {
      out.emplace_back(x, 0, y, a, b, c);
    }
    sort(out);
    for (meion [x, ok, y, a ,b, c] : out) {
      std::cout << std::format(
          "[{}s] Person {} {} Elevator {} at ({}, {}, {})\n", t, y + 1,
          (ok ? "IN" : "OUT"), x + 1, a + 1, b + 1, c + 1);
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"