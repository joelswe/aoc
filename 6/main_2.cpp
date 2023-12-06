#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <ranges>
#include <format>


int main()
{
  std::string str{};
  std::getline(std::cin, str);

  long t{};

  auto res = std::find_if(std::begin(str), std::end(str), [](unsigned char c){ return std::isdigit(c); });
  if (res != std::end(str))
  {
     auto newEnd = std::remove_if(res, std::end(str), isspace);
     t = std::stol(std::string{res, newEnd});
  }
  
  long d{};
  std::getline(std::cin, str);
  res = std::find_if(std::begin(str), std::end(str), [](unsigned char c){ return std::isdigit(c); });
  if (res != std::end(str))
  {
     auto newEnd = std::remove_if(res, std::end(str), isspace);
     d = std::stol(std::string{res, newEnd});
  }

  int solutions{};
  for (int hold_time{}; hold_time < t; hold_time++)
  {
    auto speed = hold_time;
    auto time_left = t - hold_time;
    auto dist_traveled = time_left * speed;

    if (dist_traveled > d)
    {
      solutions++;
    }
    else if ( solutions != 0)
    {
      break;
    }
  }

  std::cout << solutions << std::endl;
  return 0;
}
