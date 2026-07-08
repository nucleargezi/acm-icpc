#include "YRS/all.hpp"
#include "YRS/ds/basic/hashmap.hpp"

char s[20][20], cp[20][20];
vc<PII> mv[4]{
  {{0, 0}, {0, 1}, {0, 2}, {1, 1}, {2, 1}},
  {{0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 2}},
  {{0, 1}, {1, 1}, {2, 0}, {2, 1}, {2, 2}},
  {{0, 0}, {1, 0}, {1, 1}, {1, 2}, {2, 0}},
};

void pr(int c, int n, int m, Z s) {
  print(format("sc[{}][{}] = {};", n, m, c));
  print(format("mp[{}][{}] =", n, m), "{");
  FOR(i, n) {
    string str;
    FOR(k, m) str += s[i][k];
    print(format("  \"{}\",", str));
  }
  print("};");
}

ull hsh(int n, int m) {
  ull s = 0;
  FOR(i, n) FOR(k, m) if (::s[i][k] != '.') {
    s = (i128(131) * s + (i * n + k + 1)) % ((1ull << 61) - 1);
  }
  return s;
}

void gen(int n, int m) {
  FOR(i, n) FOR(k, m) s[i][k] = '.';
  if (min(n, m) < 3) return pr(0, n, m, s);
  int mx = 0, c = 0;
  hashmap<char> se(114514);
  Z f = [&](Z &f, int x, int y) -> void {
    if (si(se) >= 1'000'000'00) return;
    if (x + 2 < n and y + 2 < m) {
      FOR(d, 4) {
        bool ok = 1;
        FOR(i, 5) {
          var [a, b] = mv[d][i];
          int xx = a + x, yy = b + y;
          ok &= s[xx][yy] == '.';
        }
        if (not ok) continue;

        FOR(i, 5) {
          var [a, b] = mv[d][i];
          int xx = a + x, yy = b + y;
          s[xx][yy] = 'A' + c;
        }
        ++c;
        if (chmax(mx, c)) FOR(i, n) FOR(k, m) cp[i][k] = s[i][k];
        ull h = hsh(n, m);
        if (not se.contains(h)) {
          se[h] = 1;
          FOR(i, n) FOR(k, m) f(f, i, k);
        }
        FOR(i, 5) {
          var [a, b] = mv[d][i];
          int xx = a + x, yy = b + y;
          s[xx][yy] = '.';
        }
        --c;
      }
    }
  };
  f(f, 0, 0);
  pr(mx, n, m, cp);
}

void Yorisou() {
#ifdef YRS
FOR(i, 1, 10) FOR(k, 1, 10) gen(i, k);
#endif
  int sc[10][10];
  vc<string> mp[10][10];
  [&]() {
    sc[1][1] = 0;
    mp[1][1] = {
      ".",
    };
    sc[1][2] = 0;
    mp[1][2] = {
      "..",
    };
    sc[1][3] = 0;
    mp[1][3] = {
      "...",
    };
    sc[1][4] = 0;
    mp[1][4] = {
      "....",
    };
    sc[1][5] = 0;
    mp[1][5] = {
      ".....",
    };
    sc[1][6] = 0;
    mp[1][6] = {
      "......",
    };
    sc[1][7] = 0;
    mp[1][7] = {
      ".......",
    };
    sc[1][8] = 0;
    mp[1][8] = {
      "........",
    };
    sc[1][9] = 0;
    mp[1][9] = {
      ".........",
    };
    sc[2][1] = 0;
    mp[2][1] = {
      ".",
      ".",
    };
    sc[2][2] = 0;
    mp[2][2] = {
      "..",
      "..",
    };
    sc[2][3] = 0;
    mp[2][3] = {
      "...",
      "...",
    };
    sc[2][4] = 0;
    mp[2][4] = {
      "....",
      "....",
    };
    sc[2][5] = 0;
    mp[2][5] = {
      ".....",
      ".....",
    };
    sc[2][6] = 0;
    mp[2][6] = {
      "......",
      "......",
    };
    sc[2][7] = 0;
    mp[2][7] = {
      ".......",
      ".......",
    };
    sc[2][8] = 0;
    mp[2][8] = {
      "........",
      "........",
    };
    sc[2][9] = 0;
    mp[2][9] = {
      ".........",
      ".........",
    };
    sc[3][1] = 0;
    mp[3][1] = {
      ".",
      ".",
      ".",
    };
    sc[3][2] = 0;
    mp[3][2] = {
      "..",
      "..",
      "..",
    };
    sc[3][3] = 1;
    mp[3][3] = {
      "AAA",
      ".A.",
      ".A.",
    };
    sc[3][4] = 1;
    mp[3][4] = {
      "AAA.",
      ".A..",
      ".A..",
    };
    sc[3][5] = 2;
    mp[3][5] = {
      "AAA.B",
      ".ABBB",
      ".A..B",
    };
    sc[3][6] = 2;
    mp[3][6] = {
      "AAA.B.",
      ".ABBB.",
      ".A..B.",
    };
    sc[3][7] = 3;
    mp[3][7] = {
      "AAABCCC",
      ".A.B.C.",
      ".ABBBC.",
    };
    sc[3][8] = 3;
    mp[3][8] = {
      "AAA.BCCC",
      ".ABBB.C.",
      ".A..B.C.",
    };
    sc[3][9] = 4;
    mp[3][9] = {
      "AAABCCC.D",
      ".A.B.CDDD",
      ".ABBBC..D",
    };
    sc[4][1] = 0;
    mp[4][1] = {
      ".",
      ".",
      ".",
      ".",
    };
    sc[4][2] = 0;
    mp[4][2] = {
      "..",
      "..",
      "..",
      "..",
    };
    sc[4][3] = 1;
    mp[4][3] = {
      "AAA",
      ".A.",
      ".A.",
      "...",
    };
    sc[4][4] = 2;
    mp[4][4] = {
      "AAA.",
      ".AB.",
      ".AB.",
      ".BBB",
    };
    sc[4][5] = 2;
    mp[4][5] = {
      "AAA.B",
      ".ABBB",
      ".A..B",
      ".....",
    };
    sc[4][6] = 3;
    mp[4][6] = {
      "AAABBB",
      ".AC.B.",
      ".AC.B.",
      ".CCC..",
    };
    sc[4][7] = 4;
    mp[4][7] = {
      "AAABBB.",
      ".AC.BD.",
      ".AC.BD.",
      ".CCCDDD",
    };
    sc[4][8] = 4;
    mp[4][8] = {
      "AAA.BCCC",
      ".ABBBDC.",
      ".A..BDC.",
      "....DDD.",
    };
    sc[4][9] = 5;
    mp[4][9] = {
      "AAABBBCCC",
      ".AD.BE.C.",
      ".AD.BE.C.",
      ".DDDEEE..",
    };
    sc[5][1] = 0;
    mp[5][1] = {
      ".",
      ".",
      ".",
      ".",
      ".",
    };
    sc[5][2] = 0;
    mp[5][2] = {
      "..",
      "..",
      "..",
      "..",
      "..",
    };
    sc[5][3] = 2;
    mp[5][3] = {
      "AAA",
      ".A.",
      ".AB",
      "BBB",
      "..B",
    };
    sc[5][4] = 2;
    mp[5][4] = {
      "AAA.",
      ".AB.",
      ".AB.",
      ".BBB",
      "....",
    };
    sc[5][5] = 4;
    mp[5][5] = {
      "AAA.B",
      ".ABBB",
      "CA.DB",
      "CCCD.",
      "C.DDD",
    };
    sc[5][6] = 4;
    mp[5][6] = {
      "AAA.B.",
      ".ABBB.",
      ".AC.BD",
      "CCCDDD",
      "..C..D",
    };
    sc[5][7] = 5;
    mp[5][7] = {
      "AAA.B..",
      ".ABBBC.",
      "DA.EBC.",
      "DDDECCC",
      "D.EEE..",
    };
    sc[5][8] = 6;
    mp[5][8] = {
      "AAA.BCCC",
      ".ABBBDC.",
      "EA.FBDC.",
      "EEEFDDD.",
      "E.FFF...",
    };
    sc[5][9] = 7;
    mp[5][9] = {
      "AAA.BCCC.",
      ".ABBBDC..",
      "EA.FBDCG.",
      "EEEFDDDG.",
      "E.FFF.GGG",
    };
    sc[6][1] = 0;
    mp[6][1] = {
      ".",
      ".",
      ".",
      ".",
      ".",
      ".",
    };
    sc[6][2] = 0;
    mp[6][2] = {
      "..",
      "..",
      "..",
      "..",
      "..",
      "..",
    };
    sc[6][3] = 2;
    mp[6][3] = {
      "AAA",
      ".A.",
      ".AB",
      "BBB",
      "..B",
      "...",
    };
    sc[6][4] = 3;
    mp[6][4] = {
      "AAA.",
      ".AB.",
      ".AB.",
      "CBBB",
      "CCC.",
      "C...",
    };
    sc[6][5] = 4;
    mp[6][5] = {
      "AAA.B",
      ".ABBB",
      ".AC.B",
      "CCCD.",
      "..CD.",
      "..DDD",
    };
    sc[6][6] = 5;
    mp[6][6] = {
      "AAA.B.",
      ".ABBB.",
      ".A.CB.",
      "DCCCE.",
      "DDDCE.",
      "D..EEE",
    };
    sc[6][7] = 6;
    mp[6][7] = {
      "AAABCCC",
      ".A.B.C.",
      "DABBBCE",
      "DDDFEEE",
      "DFFF..E",
      "...F...",
    };
    sc[6][8] = 7;
    mp[6][8] = {
      "AAA.BCCC",
      ".ABBBDC.",
      ".AE.BDC.",
      "EEEFDDDG",
      "..EF.GGG",
      "..FFF..G",
    };
    sc[6][9] = 8;
    mp[6][9] = {
      "AAA.BCCC.",
      ".ABBB.C..",
      ".A.DBEC..",
      "FDDDGEEEH",
      "FFFDGEHHH",
      "F..GGG..H",
    };
    sc[7][1] = 0;
    mp[7][1] = {
      ".",
      ".",
      ".",
      ".",
      ".",
      ".",
      ".",
    };
    sc[7][2] = 0;
    mp[7][2] = {
      "..",
      "..",
      "..",
      "..",
      "..",
      "..",
      "..",
    };
    sc[7][3] = 3;
    mp[7][3] = {
      "AAA",
      ".A.",
      ".AB",
      "BBB",
      ".CB",
      ".C.",
      "CCC",
    };
    sc[7][4] = 4;
    mp[7][4] = {
      "AAA.",
      ".AB.",
      ".AB.",
      "CBBB",
      "CCCD",
      "CDDD",
      "...D",
    };
    sc[7][5] = 5;
    mp[7][5] = {
      "AAA.B",
      ".ABBB",
      ".AC.B",
      "CCCD.",
      ".ECD.",
      ".EDDD",
      "EEE..",
    };
    sc[7][6] = 6;
    mp[7][6] = {
      "AAA.B.",
      ".ABBB.",
      ".AC.BD",
      "CCCDDD",
      ".EC.FD",
      ".EFFF.",
      "EEE.F.",
    };
    sc[7][7] = 8;
    mp[7][7] = {
      "AAABCCC",
      ".A.B.C.",
      "DABBBCE",
      "DDDFEEE",
      "DG.F.HE",
      ".GFFFH.",
      "GGG.HHH",
    };
    sc[7][8] = 9;
    mp[7][8] = {
      "AAA.BBB.",
      ".ACCCBD.",
      ".AEC.BD.",
      "EEECFDDD",
      "G.EHFFFI",
      "GGGHFIII",
      "G.HHH..I",
    };
    sc[7][9] = 10;
    mp[7][9] = {
      "AAA.BC...",
      ".ABBBCCCD",
      "EA.FBCDDD",
      "EEEF.GGGD",
      "EHFFFIGJ.",
      ".H.IIIGJ.",
      "HHH..IJJJ",
    };
    sc[8][1] = 0;
    mp[8][1] = {
      ".",
      ".",
      ".",
      ".",
      ".",
      ".",
      ".",
      ".",
    };
    sc[8][2] = 0;
    mp[8][2] = {
      "..",
      "..",
      "..",
      "..",
      "..",
      "..",
      "..",
      "..",
    };
    sc[8][3] = 3;
    mp[8][3] = {
      "AAA",
      ".A.",
      ".AB",
      "BBB",
      ".CB",
      ".C.",
      "CCC",
      "...",
    };
    sc[8][4] = 4;
    mp[8][4] = {
      "AAA.",
      ".AB.",
      ".AB.",
      "CBBB",
      "CCCD",
      "CDDD",
      "...D",
      "....",
    };
    sc[8][5] = 6;
    mp[8][5] = {
      "AAA.B",
      ".ABBB",
      "CA.DB",
      "CCCD.",
      "CEDDD",
      ".EFFF",
      "EEEF.",
      "...F.",
    };
    sc[8][6] = 7;
    mp[8][6] = {
      "AAA.B.",
      ".ABBB.",
      ".AC.BD",
      "CCCDDD",
      "..CE.D",
      "FEEEG.",
      "FFFEG.",
      "F..GGG",
    };
    sc[8][7] = 9;
    mp[8][7] = {
      "AAAB..C",
      ".A.BCCC",
      "DABBBEC",
      "DDDEEE.",
      "DFFF.EG",
      ".HFIGGG",
      ".HFIIIG",
      "HHHI...",
    };
    sc[8][8] = 10;
    mp[8][8] = {
      "AAA.BCCC",
      ".ABBBDC.",
      "EA.FBDC.",
      "EEEFDDDG",
      "EHFFFGGG",
      ".HIII.JG",
      "HHHIJJJ.",
      "...I..J.",
    };
    sc[8][9] = 12;
    mp[8][9] = {
      "AAABBB..C",
      ".AD.BECCC",
      ".AD.BEEEC",
      "FDDDGEHHH",
      "FFFIGGGH.",
      "FJ.IGK.HL",
      ".JIIIKLLL",
      "JJJ.KKK.L",
    };
    sc[9][1] = 0;
    mp[9][1] = {
      ".",
      ".",
      ".",
      ".",
      ".",
      ".",
      ".",
      ".",
      ".",
    };
    sc[9][2] = 0;
    mp[9][2] = {
      "..",
      "..",
      "..",
      "..",
      "..",
      "..",
      "..",
      "..",
      "..",
    };
    sc[9][3] = 4;
    mp[9][3] = {
      "AAA",
      ".A.",
      ".AB",
      "BBB",
      "C.B",
      "CCC",
      "C.D",
      "DDD",
      "..D",
    };
    sc[9][4] = 5;
    mp[9][4] = {
      "AAA.",
      ".AB.",
      ".AB.",
      "CBBB",
      "CCCD",
      "CDDD",
      "EEED",
      ".E..",
      ".E..",
    };
    sc[9][5] = 7;
    mp[9][5] = {
      "AAA.B",
      ".ABBB",
      "CA.DB",
      "CCCD.",
      "CEDDD",
      ".EEEF",
      "GEFFF",
      "GGG.F",
      "G....",
    };
    sc[9][6] = 8;
    mp[9][6] = {
      "AAA.B.",
      ".ABBB.",
      ".AC.BD",
      "CCCDDD",
      "E.CF.D",
      "EEEF..",
      "EGFFFH",
      ".G.HHH",
      "GGG..H",
    };
    sc[9][7] = 10;
    mp[9][7] = {
      "AAA.B..",
      ".ABBBC.",
      ".AD.BC.",
      "DDDECCC",
      "F.DEEEG",
      "FFFEGGG",
      "FHIIIJG",
      ".H.I.J.",
      "HHHIJJJ",
    };
    sc[9][8] = 12;
    mp[9][8] = {
      "AAA.BCCC",
      ".ABBBDC.",
      "EA.FBDC.",
      "EEEFDDDG",
      "EHFFFGGG",
      ".HHHIIIG",
      "JHKKKIL.",
      "JJJK.IL.",
      "J..K.LLL",
    };
    sc[9][9] = 13;
    mp[9][9] = {
      "AAA.BCCC.",
      ".ABBB.CD.",
      ".AE.BFCD.",
      "EEEFFFDDD",
      "G.E.HFIII",
      "GGGJHHHI.",
      "GK.JHL.IM",
      ".KJJJLMMM",
      "KKK.LLL.M",
    };
  }();
  INT(a, b);
  print(sc[a][b]);
  FOR(i, a) print(mp[a][b][i]);
}

int main() {
  Yorisou();
  return 0;
}