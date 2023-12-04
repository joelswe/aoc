#include <iostream>
#include <set>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <vector>
#include <iterator>



int main()
{

  std::string str{};
  int sum{};
  while (std::getline(std::cin, str))
  {
    auto a = str.find(":");

    auto delim = str.find("|", a);
    auto winners = str.substr(a + 1, (delim - 1 - a));
    auto ours = str.substr(delim + 1, std::string::npos);

    std::set<int> winnersSet{};
    std::set<int> oursSet{};
    std::stringstream ss{winners};
  
    int tmp{};
    while(ss >> tmp)
    {
      winnersSet.insert(tmp);
    }

    std::stringstream ss2{ours};
    while(ss2 >> tmp)
    {
      oursSet.insert(tmp);
    }

    std::vector<int> overlap{};
    overlap.reserve(std::max(oursSet.size(), winnersSet.size()));
    std::set_intersection(std::begin(winnersSet), std::end(winnersSet), std::begin(oursSet), std::end(oursSet), std::back_inserter(overlap));

    if (overlap.size() > 0)
    {
      sum += std::pow(2, overlap.size() - 1);
    }
  }
  std::cout << sum << std::endl;

  return 0;
}
