 #include <iostream>
 #include <vector>

 int main() {
   int64_t n;
   std::cin >> n;
   std::vector<int> digits;
   while (n > 0) {
     digits.emplace_back(n % 10);
     n /= 10;
   }

   int mark = 1 << digits.size();
   int min_erased = digits.size();
   for (int i = 1; i < mark; ++i) {
     int one_nums = 0, mod_3 = 0;
     for (int j = 0; j < digits.size(); ++j) {
       if ((i >> j) & 1) {
         ++one_nums;
         mod_3 = (mod_3 + digits[j]) % 3;
       }
     }
     int zero_nums = digits.size() - one_nums;
     if (mod_3 == 0 && zero_nums < min_erased) {
       min_erased = zero_nums;
     }
   }
   if (min_erased == digits.size()) {
     min_erased = -1;
   }

   std::cout << min_erased << std::endl;

   return 0;
 }