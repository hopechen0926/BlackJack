#ifndef POKER_H
#define POKER_H
#include <iostream>
using namespace std;
class poker{
private:
  int row, n, suits;
  string num[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
public:
  void Frame();
  void HeadNumber();
  void TailNumber();
  void Spade();
  void Heart();
  void Diamond();
  void Club();
  void Show(int, int);
};

#endif
