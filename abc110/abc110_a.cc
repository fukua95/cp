#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (c > b) {
    swap(c, b);
  }
  if (a < b) {
    swap(a, b);
    if (b < c)
      swap(b, c);
  }
  cout << a * 10 + b + c << endl;
  return 0;
}
