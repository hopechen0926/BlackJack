#include <iostream>
#include <string>
#include <vector>
#include "poker.h"
using namespace std;
class Game{
private:
    int deck[52] = {0};
    int now_player = 0;  //現在輪到的玩家
    int player_card[4][6] = {0};  //[第幾個玩家][第幾張牌]
    int count_player_card[4] = {0};  //[第幾個玩家]現在有幾張牌
    int count_now = 0; // 現在牌堆發的第幾張
    int count_point[4] = {0};  //點數
    int player_num;  //玩家數
    int banker;  //莊家編號
    int bankroll = 10000;  //底注 = 10000
    int player_account[4] = {0};  //[第幾個玩家][帳戶金額]
    int player_bet[4] = {0};
    int ante = 3000;
    int player_insurance[4] = {0};  //[第幾個玩家][保險金]
    bool special = 1;  //判斷是否為特殊牌型
    int player_rank[4] = {0};

    poker Poker;
public:
    Game();
    //~Game(){};
    void first_gaming();  //第一局
    void gaming();  //後面的局
    void serve(int);  //發牌
    void shuffle();  //洗牌
    void show_card(int);  //
    int card_point(int, int);  //換算卡片各自的點數(A return 1)
    int card_point_2(int);  //換算卡片各自的點數(A return 11)
    void add_card(int);
    void count_card_point(int);  //計算第幾個玩家的總點數
    bool exploded(int);  //判斷爆了沒爆
    void bet(int);  //玩家下注
    bool bankrupt(int);  //判斷是否破產
    void double_down(int);  //雙倍下注
    bool surrender(int);  //投降
    void insurance(int);  //保險
    bool card_special(int);  //判斷特殊牌型
    void count_money(int);  //判斷輸贏
    void rank();  //判斷排名
};

