#include <iostream>
#include "poker.h"
using namespace std;
void poker::Frame()
{
    cout << "*********************";
}
void poker::Spade(){
  switch(row){
    case 0:
      Frame();
      break;
    case 1:
      HeadNumber();
      break;
    case 2:
      cout << "*                   *";
      break;
    case 3:
      cout << "*         *         *";
      break;
    case 4:
      cout << "*        ***        *";
      break;
    case 5:
      cout << "*       *****       *";
      break;
    case 6:
      cout << "*      *******      *";
      break;
    case 7:
      cout << "*    ***********    *";
      break;
    case 8:
      cout << "*   *************   *";
      break;
    case 9:
      cout << "*    ***********    *";
      break;
    case 10:
      cout << "*        ***        *";
      break;
    case 11:
      cout << "*       *****       *";
      break;
    case 12:
      cout << "*                   *";
      break;
    case 13:
      TailNumber();
      break;
    case 14:
      Frame();
      break;
    default:
      break;
  }
}

void poker::Heart(){
  switch (row) {
    case 0:
      Frame();
      break;
    case 1:
      HeadNumber();
      break;
    case 2:
      cout << "*                   *";
      break;
    case 3:
      cout << "*     ***   ***     *";
      break;
    case 4:
      cout << "*    ***** *****    *";
      break;
    case 5:
      cout << "*   *************   *";
      break;
    case 6:
      cout << "*   *************   *";
      break;
    case 7:
      cout << "*    ***********    *";
      break;
    case 8:
      cout << "*     *********     *";
      break;
    case 9:
      cout << "*      *******      *";
      break;
    case 10:
      cout << "*        ***        *";
      break;
    case 11:
      cout << "*         *         *";
      break;
    case 12:
      cout << "*                   *";
      break;
    case 13:
      TailNumber();
      break;
    case 14:
      Frame();
      break;
    default:
      break;
  }
}

void poker::Diamond(){
  switch (row) {
    case 0:
      Frame();
      break;
    case 1:
      HeadNumber();
      break;
    case 2:
      cout << "*                   *";
      break;
    case 3:
      cout << "*         *         *";
      break;
    case 4:
      cout << "*        ***        *";
      break;
    case 5:
      cout << "*       *****       *";
      break;
    case 6:
      cout << "*      *******      *";
      break;
    case 7:
      cout << "*     *********     *";
      break;
    case 8:
      cout << "*      *******      *";
      break;
    case 9:
      cout << "*       *****       *";
      break;
    case 10:
      cout << "*        ***        *";
      break;
    case 11:
      cout << "*         *         *";
      break;
    case 12:
      cout << "*                   *";
      break;
    case 13:
      TailNumber();
      break;
    case 14:
      Frame();
      break;
    default:
      break;
  }
}

void poker::Club(){
  switch(row){
    case 0:
        Frame();
        break;
    case 1:
        HeadNumber();
        break;
    case 2:
      cout << "*                   *";
      break;
    case 3:
      cout << "*        ***        *";
      break;
    case 4:
      cout << "*       *****       *";
      break;
    case 5:
      cout << "*        ***        *";
      break;
    case 6:
      cout << "*    *** *** ***    *";
      break;
    case 7:
      cout << "*   *************   *";
      break;
    case 8:
      cout << "*    *** *** ***    *";
      break;
    case 9:
      cout << "*        ***        *";
      break;
    case 10:
      cout << "*       *****       *";
      break;
    case 11:
      cout << "*      *******      *";
      break;
    case 12:
      cout << "*                   *";
      break;
    case 13:
        TailNumber();
        break;
    case 14:
        Frame();
        break;
    default:
      break;
  }
}
void poker::HeadNumber()
{
  //string num[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
  if(num[n] == "10"){
    cout << "* " << num[n] << "                *";
  }
  else cout << "* " << num[n] << "                 *";
}
void poker::TailNumber(){
  if(num[n] == "10"){
    cout << "*                " << num[n] << " *";
  }
  else cout << "*                 " << num[n] << " *";
}
void poker::Show(int card, int r)
{
  row = r;
  n = card / 4;
  suits = card % 4;
  if(suits == 0)
    Spade();
  else if(suits == 1)
    Heart();
  else if(suits == 2)
    Diamond();
  else if(suits == 3)
    Club();
}