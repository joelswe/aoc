#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <ranges>
#include <format>


int main()
{
  std::vector<int> time{};
  std::vector<int> dist{};

  std::string str{};
  std::getline(std::cin, str);

  auto res = std::find_if(std::begin(str), std::end(str), [](unsigned char c){ return std::isdigit(c); });
  if (res != std::end(str))
  {
    std::stringstream ss{std::string{res, std::end(str)}};

    int tmp{};
    while (ss >> tmp)
    {
      time.push_back(tmp);
    }
  }
  
  std::getline(std::cin, str);
  res = std::find_if(std::begin(str), std::end(str), [](unsigned char c){ return std::isdigit(c); });
  if (res != std::end(str))
  {
    std::stringstream ss{std::string{res, std::end(str)}};

    int tmp{};
    while (ss >> tmp)
    {
      dist.push_back(tmp);
    }
  }

  int answer{1};
  for (auto [t, d] : std::views::zip(time, dist))
  {
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
    answer *= solutions;
  }

  std::cout << answer << std::endl;

  return 0;
}
