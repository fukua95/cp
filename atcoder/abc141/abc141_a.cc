#include <iostream>
#include <string>
#include <map>

int main() {
  std::map<std::string, int> s_to_num;
  std::map<int, std::string> num_to_s;
  s_to_num["Sunny"] = 0;
  s_to_num["Cloudy"] = 1;
  s_to_num["Rainy"] = 2;
  num_to_s[0] = "Sunny";
  num_to_s[1] = "Cloudy";
  num_to_s[2] = "Rainy";

  std::string str;
  std::cin >> str;
  std::cout << num_to_s[(s_to_num[str] + 1) % 3] << std::endl;
  
  return 0;
}
