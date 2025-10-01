#include "game.h"
#include "poker.h"
using namespace std;

Game::Game(){
    shuffle();
    cout << "How many players?" << endl;
    cin >> player_num;
    while(1){
        if(player_num >= 2)
            break;
        else
            cout << "The number of players must >= 2." << endl;
    }
    gaming();
}
// void Game::first_gaming(){
//     for(int i = 0; i < player_num; i++)
//         player_account[i] = 10000;
// }


void Game::gaming(){
//初始化每個玩家的金額, 寫round迴圈
    cout << "Every player starts with initial amount $10000 and the ante $3000." << endl;
    for(int i = 0; i < player_num; i++){
        player_account[i] = 10000;
    }
//抽第一局的莊家
    srand(time(NULL));
    banker = rand() % player_num;
    cout << "This round's banker: Player_" << banker + 1 << endl;
//下注    
    for(int i = 0; i < player_num; i++)
        bet(i);
//發牌
    for(int i = 0; i < player_num; i++){
        serve(i);
        serve(i);
    }

//第一局印牌：
//印第一局莊家的第一張明牌
    cout << "This round banker: Player_" << banker + 1 << endl;
    for(int row = 0; row < 15; row++){
        Poker.Show(player_card[banker][0], row);
        cout << endl;
    }
//印其他玩家兩張明牌
    for(int i = 0; i < player_num; i++){
        if(i != banker){
            show_card(i);
            count_card_point(i);
        }
    }
//閒家加牌    
    for(int i = 0; i < player_num; i++){
        if(i != banker){
            show_card(i);
            count_card_point(i);
            if(player_card[banker][0] / 4 == 0)
                insurance(i);
            if(!surrender(i)){
                double_down(i);
                add_card(i);
            }
        }
    }
    
//印莊家的兩張牌
    show_card(banker);
    count_card_point(banker);
    while(count_point[banker] < 17){
        serve(banker);
        show_card(banker);
        count_card_point(banker);
        if(exploded(banker))
            break;
    }
    add_card(banker);

    // 算錢
    if(!exploded(banker)){
        for(int i = 0; i < player_num; i++){
            if(i != banker){
                if(!exploded(i)){
                    count_money(i);
                }
                else{
                    // banker wins
                    player_account[banker] += player_bet[i];
                    player_account[i] -= player_bet[i];
                }
            }
        }
    }
    else{
        // return all money
        for(int i = 0; i < player_num; i++){
            if(i != banker){
                if(!exploded(i)){
                    // i wins
                    if(card_special(i)){
                        player_account[i] += (player_bet[i] * 3);
                        player_account[banker] -= (player_bet[i] * 3);
                    }
                    else{
                        player_account[i] += player_bet[i];
                        player_account[banker] -= player_bet[i];
                    }
                }
                else
                    count_money(i);
            }
        }
    }
    for(int i = 0; i < player_num; i++)
        cout << "Player_" << i + 1 << "'s money: " << player_account[i] << endl;
    cout << "Rank:" << endl;
    rank();
}

void Game::serve(int p)
{
    player_card[p][count_player_card[p]] = deck[count_now];
    count_now++;
    count_player_card[p]++;
}

void Game::shuffle(){
    srand(time(NULL));
    bool c_deck[52] = {0};
    for(int i = 0; i < 52; i++)
    {
    here:
        int ran;
        ran = rand() % 52;
        if(c_deck[ran])
            goto here;
        deck[i] = ran;
        c_deck[ran] = 1;
    }
}

void Game::show_card(int p){
    //cout << "Player_" << i + 1 << ": " << player_card[i][0] << " " << player_card[i][1] << endl;
    cout << "Player_" << p + 1 << endl;
    for(int row = 0; row < 15; row++){
        for (int j = 0; j < count_player_card[p]; j++){
            Poker.Show(player_card[p][j], row);
        }
        cout << endl;
    }
}

int Game::card_point(int card_num, int p){
    (card_num /= 4)++;
    switch(card_num){
         case 1: // "A"
            if(count_point[p] <= 21)
                return 11;
            else
                return 1;
        case 11: case 12: case 13:
            return 10;
        default:
            return card_num;
    }
}

void Game::add_card(int p){
    if(p != banker){
        // show_card(p);
        // count_card_point(p);
        while(!exploded(p)){
            cout << "Do you want to add a new card?" << endl;
            cout << "0. No" << endl << "1. Yes" << endl;
            bool choice = 1;
            cin >> choice;
            if(choice){
                serve(p);
                show_card(p);
                count_card_point(p);
                if(exploded(p))
                    break;
            }
            else
                break;
        }
    }
    else{
        if(count_point[banker] >= 17){
            while(!exploded(p)){
            cout << "Do you want to add a new card?" << endl;
            cout << "0. No" << endl << "1. Yes" << endl;
            bool choice = 1;
            cin >> choice;
            if(choice){
                serve(p);
                show_card(p);
                count_card_point(p);
                if(exploded(p))
                    break;
            }
            else
                break;
        }
        }
    }
}

void Game::count_card_point(int p)
{
    count_point[p] = 0;
    for(int j = 0; j < count_player_card[p]; j++)
        count_point[p] += card_point(player_card[p][j], p);
    cout << "Points: " << count_point[p] << endl;
}

bool Game::exploded(int p){
    if(count_point[p] > 21)
        return true;
    else
        return false;
}

void Game::bet(int p){
    player_bet[p] = 0;
    if(p != banker){
        cout << "How much money do you want to bet?" << endl;
        cout << "Player_" << p + 1 << ": ";
        cin >> player_bet[p];
        if(player_bet[p] < 3000){
            cout << "Your blind bet must greater than ante $3000." << endl;
        }
    }
}

bool Game::bankrupt(int p)
{
    if(player_account[p] <= 0)
        return false;
    else
        return true;
}

void Game::double_down(int p){
    if(p != banker && count_point[p] == 11){
        cout << "Do you want to double down?" << endl;
        cout << "0. No" << endl << "1. Yes" << endl;
        bool choice = 1;
        cin >> choice;
        if(choice){
            player_account[p] -= player_bet[p];
            player_bet[p] *= 2;
            cout << "Player_" << p + 1 << "'s new bet: " << player_bet[p] << endl;
        }
    }
}

bool Game::surrender(int p){
    cout << "Do you want to surrender?" << endl;
    cout << "0. No" << endl << "1. Yes" << endl;
    bool choice = 1;
    cin >> choice;
    if (choice){
        player_bet[p] *= 0.5;
        return true;
    }
    return false;
}

void Game::insurance(int p){
    player_insurance[p] = 0;
    
    //if(p != banker){
        cout << "Do you want to buy insurance?" << endl;
        cout << "0. No" << endl << "1. Yes" << endl;
        bool choice = 1;
        cin >> choice;
        if(choice){
            player_insurance[p] = player_bet[p] * 0.5;
            player_account[p] -= player_insurance[p];
            if(count_point[banker] == 21){
                cout << "Player_" << p + 1 << " get insurance money $" << 2 * player_insurance[p] << endl;
                player_account[p] = player_account[p] + 2 * player_insurance[p];
                player_insurance[p] = 0;
            }
            else{
                player_insurance[p] = 0;
            }
        }
    //}
}

bool Game::card_special(int p){
//過五關||順(6, 7, 8)
    if((count_point[p] <= 21 && count_player_card[p] == 5) || (count_point[p] == 21 && player_card[p][0] == 6 && player_card[p][1] == 7 && player_card[p][2] == 8))
        return true;
    else
        return false;
}
void Game::count_money(int p){
    if(card_special(banker)){
        if(card_special(p)){
            if(count_point[banker] >= count_point[p]){
                player_account[p] -= player_bet[p];
                player_account[banker] += player_bet[p];
            }
            else{
                player_account[p] += (player_bet[p] * 3);
                player_account[banker] -= (player_bet[p] * 3);
            }
        }
        else{
            player_account[p] -= player_bet[p];
            player_account[banker] += player_bet[p];
        }
    }
    else{
        if(card_special(p)){
            player_account[p] += (player_bet[p] * 3);
            player_account[banker] -= (player_bet[p] * 3);
        }
        else{
            if(count_point[banker] >= count_point[p]){
                player_account[p] -= player_bet[p];
                player_account[banker] += player_bet[p];
            }
            else{
                player_account[p] += (player_bet[p] * 2);
                player_account[banker] -= (player_bet[p] * 2);
            }
        }
    }
}

void Game::rank(){
    for (int i = 0; i < player_num; i++){
        player_rank[i] = i;
    }
    for(int i = 0; i < player_num; i++){
        for (int j = i; j < player_num; j++){
            if (player_account[i] < player_account[j])
                swap(player_rank[i], player_rank[j]);
        }
    }
    for (int i = 0; i < player_num; i++){
        cout << "Player_"  << i + 1 << "'s rank is " << player_rank[i] + 1 << endl;
    }
}
