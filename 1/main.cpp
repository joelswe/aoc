#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string_view>
std::map<std::string, int> lookup = 
{
  { "1", 1},
  { "2", 2},
  { "3", 3},
  { "4", 4},
  { "5", 5},
  { "6", 6},
  { "7", 7},
  { "8", 8},
  { "9", 9},
  { "one", 1},
  { "two", 2},
  { "three", 3},
  { "four", 4},
  { "five", 5},
  { "six", 6},
  { "seven", 7},
  { "eight", 8},
  { "nine", 9},
};

std::vector<std::string> values = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};


int main()
{
#if 0 // first part
  std::string s{};
  int res{};
  while (std::cin >> s)
  {
    for (auto l : s)
    {
      if (std::isdigit(l))
      {
        tmp.push_back((l - 48));
      }
    }
    if (tmp.size() > 1)
    {
      res += 10 * tmp.front() + tmp.back();
    }
    else if (tmp.size() == 1)
    {
      res += 10 * tmp.front() + tmp.front();
    }
  }
  std::cout << res << std::endl;
#else
  std::string s{};
  int res{};
  while (std::cin >> s)
  {
    std::vector<int> tmp{};
    for (int i{}; i < s.size(); i++)
    {
      auto subStr = s.substr(i);
      for (auto test : values)
      {
        if (subStr.starts_with(test))
        {
          tmp.push_back(lookup[test]);
        }
      }
    }
    if (tmp.size() > 1)
    {
      auto value = 10 * tmp.front() + tmp.back();
      res += value;
    }
    else if (tmp.size() == 1)
    {
      auto value = 10 * tmp.front() + tmp.front();
      res += value;
    }

  }
  std::cout << res << std::endl;
#endif 
  return 0;
}
