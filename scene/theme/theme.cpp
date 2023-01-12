#include "theme.hpp"

Theme::Theme() {}

Theme::~Theme() {}

themeColor Theme::getColor(int index) {
  themeColor red = {
    {83, 0, 6},
    {248, 166, 172},
    {166, 55, 63}
  };

  themeColor green = {
    {20, 73, 0},
    {165, 218, 145},
    {75, 145, 48}
  };

  themeColor blue = {
    {6, 19, 57},
    {121, 134, 172},
    {47, 64, 115}
  };

  themeColor colors[] = {green, red, blue};
  return colors[index];
}
