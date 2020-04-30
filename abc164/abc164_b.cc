#include <iostream>

int main() {
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;
  bool first_win = true;
  bool turn = false;
  while (a > 0 && c > 0) {
    if (!turn) c -= b;
    else a -= d;
    if (a <= 0) first_win = false;
    else if (c <= 0) first_win = true;
    turn = !turn;
  }
  if (first_win) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  return 0;
}
