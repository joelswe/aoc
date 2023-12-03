#include <iostream>

static const int RED_MAX = 12;
static const int GREEN_MAX = 13;
static const int BLUE_MAX = 14;

int main()
{


  std::string str{};
  int sum = 0;
  while (std::getline(std::cin, str))
  {
    auto a = str.find(" ");
    auto b = str.find(":");
    int game = std::stoi(str.substr(a, b-a));

    auto oldDelim = b + 1;
    auto delim = str.find(";");

    bool greenOk = true;
    bool redOk = true;
    bool blueOk = true;

    int greenMax = 1;
    int blueMax = 1;
    int redMax = 1;

    while (delim != std::string::npos && (greenOk && redOk && blueOk))
    {
      auto newStr = str.substr(oldDelim, (delim - oldDelim));

      auto subDelim = newStr.find(",");
      auto oldSubDelim = 0;
      while (subDelim != std::string::npos && (greenOk && redOk && blueOk))
      {
        auto newNewStr = newStr.substr(oldSubDelim, (subDelim - oldSubDelim));

        auto space = newNewStr.find(" ");
        auto space2 = newNewStr.find(" ", space + 1);
        int value = std::stoi(newNewStr.substr(space, space2));
        auto color = newNewStr.substr(space2 + 1);
        if (color == "red")
        {
//            redOk &= (value <= RED_MAX);
            redMax = std::max(redMax, value);
        }
        else if (color == "green")
        {
//           greenOk &= (value <= GREEN_MAX);
            greenMax = std::max(greenMax, value);
        }
        else if (color == "blue")
        {
//          blueOk &= (value <= BLUE_MAX);
            blueMax = std::max(blueMax, value);
        }

        oldSubDelim = subDelim + 1;
        subDelim = newStr.find(",", subDelim + 1);
      }

      auto newNewStr = newStr.substr(oldSubDelim, std::string::npos);

      auto space = newNewStr.find(" ");
      auto space2 = newNewStr.find(" ", space + 1);
      int value = std::stoi(newNewStr.substr(space, space2));
      auto color = newNewStr.substr(space2 + 1);
      if (color == "red")
      {
//            redOk &= (value <= RED_MAX);
          redMax = std::max(redMax, value);
      }
      else if (color == "green")
      {
//           greenOk &= (value <= GREEN_MAX);
          greenMax = std::max(greenMax, value);
      }
      else if (color == "blue")
      {
//          blueOk &= (value <= BLUE_MAX);
          blueMax = std::max(blueMax, value);
      }

      oldDelim = delim + 1;
      delim = str.find(";", delim + 1);
    }
    auto newStr = str.substr(oldDelim, std::string::npos);

    auto subDelim = newStr.find(",");
    auto oldSubDelim = 0;
    while (subDelim != std::string::npos && (greenOk && redOk && blueOk))
    {
      auto newNewStr = newStr.substr(oldSubDelim, (subDelim - oldSubDelim));

      auto space = newNewStr.find(" ");
      auto space2 = newNewStr.find(" ", space + 1);
      int value = std::stoi(newNewStr.substr(space, space2));
      auto color = newNewStr.substr(space2 + 1);
      if (color == "red")
      {
        //            redOk &= (value <= RED_MAX);
        redMax = std::max(redMax, value);
      }
      else if (color == "green")
      {
        //           greenOk &= (value <= GREEN_MAX);
        greenMax = std::max(greenMax, value);
      }
      else if (color == "blue")
      {
        //          blueOk &= (value <= BLUE_MAX);
        blueMax = std::max(blueMax, value);
      }

      oldSubDelim = subDelim + 1;
      subDelim = newStr.find(",", subDelim + 1);
    }
    auto newNewStr = newStr.substr(oldSubDelim, std::string::npos);

    auto space = newNewStr.find(" ");
    auto space2 = newNewStr.find(" ", space + 1);
    int value = std::stoi(newNewStr.substr(space, space2));
    auto color = newNewStr.substr(space2 + 1);
    if (color == "red")
    {
      //            redOk &= (value <= RED_MAX);
      redMax = std::max(redMax, value);
    }
    else if (color == "green")
    {
      //           greenOk &= (value <= GREEN_MAX);
      greenMax = std::max(greenMax, value);
    }
    else if (color == "blue")
    {
      //          blueOk &= (value <= BLUE_MAX);
      blueMax = std::max(blueMax, value);
    }
    int power = redMax * blueMax * greenMax;
    sum += power;

//    if (greenOk && blueOk && redOk)
//    {
//      sum += game;
//    }

  }
  std::cout << sum << std::endl;
  return 0;
}
