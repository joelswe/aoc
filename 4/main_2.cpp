#include <iostream>
#include <numeric>
#include <set>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <vector>
#include <iterator>
#include <format>



int main()
{

  std::string str{};
  int sum{};
  std::vector<int> copies{};
  copies.insert(std::begin(copies), 194, 0);
  std::vector<int> numberOfCards{};
  numberOfCards.insert(std::begin(numberOfCards), 194, 0);

  while (std::getline(std::cin, str))
  {
    auto a = str.find(" ");
    auto b = str.find(":");
    int card = std::stoi(str.substr(a, b-a));
    int index = card - 1;
    numberOfCards[index] = 1 + copies[index];

    auto delim = str.find("|", b);
    auto winners = str.substr(b + 1, (delim - 1 - b));
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

    for (int i{}; i < overlap.size(); i++)
    {
      copies[index + i + 1] += numberOfCards[index];
    }
  }

  std::cout << std::accumulate(std::begin(numberOfCards), std::end(numberOfCards), 0) << std::endl;

  return 0;
}
