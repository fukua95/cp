#include <iostream>
#include <string>
#include <map>

int main() {
  std::map<std::string, int> m;
  m["SUN"] = 7;
  m["MON"] = 6;
  m["TUE"] = 5;
  m["WED"] = 4;
  m["THU"] = 3;
  m["FRI"] = 2;
  m["SAT"] = 1;
  
  std::string input;
  std::cin >> input;
  std::cout << m[input] << std::endl;
  return 0;
}
