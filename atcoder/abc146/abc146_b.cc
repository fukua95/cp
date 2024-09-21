#include <string>
#include <iostream>

int main() {
  int n;
  std::string input;
  std::cin >> n;
  std::cin >> input;
  for (int i = 0; i < input.length(); ++i) {
    char cur = input[i];
    input[i] = ((cur - 'A') + n) % 26 + 'A';
  }
  std::cout << input << std::endl;
  return 0;
}
