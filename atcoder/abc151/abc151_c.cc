#include <iostream>
#include <string>

const int MAXN = (int)1e5 + 1;

bool is_ac[MAXN];
int wa_num[MAXN];

int main() {
  int n, m;
  std::cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    is_ac[i] = false;
    wa_num[i] = 0;
  }
  int p;
  std::string s;
  int ac_num = 0;
  int pen = 0;
  for (int i = 0; i < m; ++i) {
    std::cin >> p >> s;
    if (is_ac[p]) continue;
    if (s == "AC") {
      is_ac[p] = true;
      ++ac_num;
      pen += wa_num[p];
    } else {
      ++wa_num[p];
    }
  }
  std::cout << ac_num << " " << pen << std::endl;
  return 0;
}
