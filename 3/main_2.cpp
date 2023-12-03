#include <iostream>
#include <array>
#include <algorithm>
#include <optional>
#include <vector>
#include <format>

template<typename T>
void printArray(T array)
{
  for (auto outer : array)
  {
    for (auto inner : outer)
    {
      std::cout << inner;
    }
    std::cout << std::endl;
  }
}

template<typename T>
T parseInput()
{
  int row = 0;
  T res;
  std::string str;
  while (std::getline(std::cin, str))
  {
    int column = 0;
    for (const auto c : str)
    {
        res[row][column] = c;
        column++;
    }
    row++;
  }
  return res;
}

int getNumber(const auto& row, auto startIter, auto endIter)
{
  auto resIter = std::find_if(startIter, endIter, [](unsigned char c){ return std::isdigit(c); });
  if (resIter == endIter)
  {
    return 0;
  }

  auto lastIter = std::find_if_not(resIter, endIter, [](unsigned char c){ return std::isdigit(c); });
  std::string number{resIter, lastIter};
  return std::stoi(number);
}

template<typename T>
int getNumber(const auto& row, std::reverse_iterator<T> startIter, std::reverse_iterator<T> endIter)
{
  auto resIter = std::find_if(startIter, endIter, [](unsigned char c){ return std::isdigit(c); });
  if (resIter == endIter)
  {
    return 0;
  }

  auto lastIter = std::find_if_not(resIter, endIter, [](unsigned char c){ return std::isdigit(c); });
  std::string number{resIter, lastIter};
  std::string numberReversed{std::rbegin(number), std::rend(number)};
  return std::stoi(numberReversed);
}

std::vector<int> checkRow(const auto& row, int offset)
{
  auto prevStart = std::begin(row);
  std::vector<int> res{};
  while (prevStart != std::end(row))
  {
    auto startIter = std::find_if(prevStart, std::end(row), [](unsigned char c){ return std::isdigit(c); });
    if (startIter == std::end(row))
    {
      break;
    }

    auto endIter = std::find_if_not(startIter, std::end(row), [](unsigned char c){ return std::isdigit(c); });
    prevStart = endIter;

    const int startOffset = startIter - std::begin(row);
    const int endOffset = endIter - std::begin(row) - 1;
    std::string number{startIter, endIter};
    int num = std::stoi(number);

    if (startOffset - 1 <= offset && startOffset + 1 >= offset)
    {
      res.push_back(num);
    }
    else if (endOffset -1 <= offset && endOffset + 1 >= offset)
    {
      res.push_back(num);
    }
  }
  return res;
}

template<typename T>
void solve()
{
  T input = parseInput<T>();
  int sum = 0;
  int rowIndex = 0;
  for (auto& row : input)
  {
    auto prevStart = std::begin(row);

    while (prevStart != std::end(row))
    {
      auto startIter = std::find_if(prevStart, std::end(row), [](unsigned char c){ return c == '*'; });
      if (startIter == std::end(row))
      {
        break;
      }

      auto endIter = startIter + 1;
      prevStart = startIter + 1;


      std::vector<int> partNumbers{};
      // Left of current number
      if (startIter != std::begin(row))
      {
        if (std::isdigit(*(startIter - 1)))
        {
          partNumbers.push_back(getNumber(row, std::make_reverse_iterator(startIter), std::rend(row)));
        }
      }

      // Right of current
      if (endIter != std::end(row))
      {
        if (std::isdigit(*(endIter)))
        {
          partNumbers.push_back(getNumber(row, endIter, std::end(row)));
        }
      }

      // Figure out the offset from the start of the row
      int offset = startIter - std::begin(row);

      // Row above
      if (rowIndex != 0)
      {
        auto tmp = checkRow(input[rowIndex - 1], offset);
        partNumbers.insert(std::end(partNumbers), std::begin(tmp), std::end(tmp));;
      }
      
      // Row below
      if (rowIndex < input.size() - 1)
      {
        auto tmp = checkRow(input[rowIndex + 1], offset);
        partNumbers.insert(std::end(partNumbers), std::begin(tmp), std::end(tmp));;
      }

      if (partNumbers.size() == 2)
      {
        sum += partNumbers[0] * partNumbers[1];
      }
    }
    rowIndex++;
  }

  std::cout << sum << std::endl;

//  printArray(input);
}

int main()
{
  std::string str;

  // Check if test data or real data. Don't wanna recompile to change, and don't wanna hardcode different paths in the solver
  std::streampos sp = std::cin.tellg();
  std::getline(std::cin, str);
  std::cin.seekg(sp);

  if (str.length() == 10)
  {
    solve<std::array<std::array<char, 10>, 10>>();
  }
  else
  {
    solve<std::array<std::array<char, 140>, 140>>();
  }
  return 0;
}
