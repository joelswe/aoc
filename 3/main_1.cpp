#include <iostream>
#include <array>
#include <algorithm>

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
  T res{};
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

bool isSymbol(char c)
{
  return c != '.';
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
      auto startIter = std::find_if(prevStart, std::end(row), [](unsigned char c){ return std::isdigit(c); });
      if (startIter == std::end(row))
      {
        break;
      }

      auto endIter = std::find_if_not(startIter, std::end(row), [](unsigned char c){ return std::isdigit(c); });
      prevStart = endIter;
      std::string number{startIter, endIter};
      int partNumber = std::stoi(number);

      // Left of current number
      if (startIter != std::begin(row))
      {
        if (isSymbol(*(startIter - 1)))
        {
          sum += partNumber;
          continue;
        }
      }

      // Right of current
      if (endIter != std::end(row))
      {
        if (isSymbol(*(endIter)))
        {
          sum += partNumber;
          continue;
        }
      }

      // Figure out the offset from the start of the row
      int startOffset = 0;
      if (startIter < std::begin(row) + 1)
      {
          startOffset = 0;
      }
      else
      {
        startOffset = startIter - std::begin(row) - 1;
      }

      int endOffset = 0;
      if (endIter == std::end(row))
      {
        endOffset = (endIter - 1) - std::begin(row);
      }
      else if (endIter + 1 == std::end(row))
      {
        endOffset = endIter - std::begin(row);
      }
      else
      {
        endOffset = (endIter + 1) - std::begin(row);
      }

      auto checkRow = [&input, startOffset, endOffset](int index)->bool {
        auto& newRow = input[index];
        auto newStartIter = std::begin(newRow) + startOffset;
        auto newEndIter = std::begin(newRow) + endOffset;
       return std::any_of(newStartIter, newEndIter, isSymbol);
      };

      // Row above
      if (rowIndex != 0)
      {
        if (checkRow(rowIndex - 1))
        {
          sum += partNumber;
          continue;
        }
      }
      
      // Row below
      if (rowIndex < input.size() - 2)
      {
        if (checkRow(rowIndex + 1))
        {
          sum += partNumber;
          continue;
        }
      }
    }
    rowIndex++;
  }

  std::cout << sum << std::endl;

//  printArray(input);
}

int main()
{
  std::string str{};

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
