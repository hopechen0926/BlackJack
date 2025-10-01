# BlackJack

一個以 C++ 撰寫的 21點 (BlackJack) 遊戲範例程式。

## 目錄

- [專案說明](#專案說明)  
- [功能](#功能)  
- [程式結構](#程式結構)  
- [安裝與建置](#安裝與建置)  

## 專案說明

這是一個簡單的21點撲克牌遊戲實作，包括發牌、玩家與莊家比點、勝負判定等邏輯。主要用於學習 C++ 類別設計與遊戲邏輯實作。

## 功能

目前已實作的功能包括：

- 洗牌、發牌  
- 玩家可以要牌（Hit）或停牌（Stand）
- 玩家在發牌後可以選擇投降 (Surrender)
- 莊家遵循固定規則自動出牌  
- 判定勝負（玩家勝 / 莊家勝 / 平手 / 爆牌等）  
- 支援多局遊戲

## 程式結構

- `game.h` / `game.cpp`：遊戲流程、玩家與莊家的控制邏輯  
- `poker.h` / `poker.cpp`：有關牌組、點數／花色計算、洗牌、抽牌等  
- `main.cpp`：負責與使用者互動、啟動遊戲循環

## 安裝與建置

假設你已經安裝了 C++ 編譯器（如 g++）：

```bash
# 從 GitHub clone 下來
git clone https://github.com/hopechen0926/BlackJack.git
cd BlackJack

# 編譯（以下是示例編譯命令，可依你的實作修改）
g++ main.cpp game.cpp poker.cpp -o blackjack

# 執行
./blackjack

