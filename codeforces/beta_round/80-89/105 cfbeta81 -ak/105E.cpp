#include "YRS/all.hpp"
#include "YRS/ds/basic/hashmap.hpp"

struct dat {
  array<char, 3> a;
  array<char, 3> nx, pr;
  bitset<9> vis;

  bool operator<(const dat &p) const {
    return hsh() < p.hsh();
  }

  int f() const { return QMAX(a); }

  int hd(int i) const {
    while (pr[i] != -1) i = pr[i];
    return i;
  }

  int bk(int i) const {
    while (nx[i] != -1) i = nx[i];
    return i;
  }

  void lk(int i, int k) {
    pr[k] = -1;
    i = bk(i);
    nx[i] = k;
    pr[k] = i;
  }

  int find(int s) const {
    FOR(i, 3) if (s == a[i]) return hd(i);
    return -1;
  }

  bool contains(int s) const {
    FOR(i, 3) if (a[i] == s) return 1;
    return 0;
  }

  int size(int i) const {
    while (pr[i] != -1) i = pr[i];
    int s = 0;
    while (i != -1) ++s, i = nx[i];
    return s;
  }

  ull hsh() const {
    static constexpr ull P = (1ull << 61) - 1;
    u128 s = 0;
    FOR(i, 3) s = (s * 123 + a[i] + 10) % P;
    FOR(i, 3) s = (s * 123 + nx[i] + 10) % P;
    FOR(i, 3) s = (s * 123 + pr[i] + 10) % P;
    s = (s * 123 + vis.to_ullong()) % P;
    return s;
  }
};
void Yorisou() {
  char a[3][3];
  FOR(i, 3) FOR(k, 3) {
    INT(x);
    a[i][k] = x;
  }
  vc<dat> q;
  q.reserve(3'000'00);
  hashmap<char> se(3'000'00);
  dat st = {{a[0][0], a[1][0], a[2][0]}, 
           {-1, -1, -1}, {-1, -1, -1}, {}};
  st.vis.set();
  int rs = 0;

  Z upd = [&](const dat &x) -> void {
    ull h = x.hsh();
    if (se.contains(h)) return;
    se[h] = 1;
    q.ep(x);
    chmax(rs, x.f());
  };
  upd(st);

  while (si(q)) {
    Z st = pop(q);
    FOR(t, 9) if (st.vis[t]) {
      int i = t / 3, k = t % 3, p = st.a[i], r = a[i][1], th = a[i][2];
      if (k == 0) {
        if (st.size(i) != 1) {
          ;
        } else {
          FOR(j, p - r, p + r + 1) if (j >= 0 and not st.contains(j)) {
            dat ne = st;
            ne.a[i] = j;
            ne.vis.reset(t);
            upd(ne);
          }
        }
      } else if (k == 1) {
        if (st.hd(i) != i or st.bk(i) != i) {
          ;
        } else {
          for (int ge : {p - 1, p + 1}) if (st.contains(ge)) {
            Z ne = st;
            ne.lk(ne.bk(i), ne.find(ge));
            for (int x = ne.hd(i); x != -1; x = ne.nx[x]) ne.a[x] = p;
            ne.vis.reset(t);
            upd(ne);
          }
        }
      } else {
        if (st.hd(i) != i or st.size(i) == 1) {
          ;
        } else {
          FOR(j, p - th, p + th + 1) if (j >= 0 and not st.contains(j)) {
            Z ne = st;
            int n = ne.nx[i];
            ne.pr[n] = -1;
            ne.nx[i] = -1;
            for (int x = ne.hd(n); x != -1; x = ne.nx[x]) ne.a[x] = j;
            ne.vis.reset(t);
            upd(ne);
          }
        }
      }
    }
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}