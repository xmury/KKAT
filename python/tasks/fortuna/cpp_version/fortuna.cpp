#include "stdafx.h"

extern int money = 0;
extern int stage = 0;
extern int bet = 0;
extern int value = 0;
extern int index = 0;

extern int wheel[36] = {0,28,9,26,30,11,7,20,32,17,5,22,34,15,3,24,36,13,1,0,27,10,25,29,12,8,19,31,18,6,21,33,16,4,23,35,14,2};

int run() {
        index = rand() % 37;
        value = wheel[index];
        stage++;
        return value;
}

bool bet_in_num(int bet,int money) {
    if (money - money < 0) { return "Error" } 
    bet = bet

    if bet == run():   
        money += money * 35
        return True
    else:                   
        money -= money
        return False
}

    def bet_in_split(self, bet, money):
        if self.money - money < 0: return "Error"
        self.bet = bet

        if bet[0] == self.run() or bet[1] == self.value:   
            self.money += money * 17
            return True
        else:                   
            self.money -= money
            return False

bool bet_in_care(int bet,int money) {
    
}
// Принимает 1 (нечет) или 2 (чёт)
bool bet_in_color(int bet,int money) {
    
}
// Принимает 0 (1-18) и 1 (19-36)
bool bet_in_half(int bet,int money) {
    
}

bool bet_in_zero(int bet,int money) {
    
}

// http://www.mycashed.com/post/pravila-igry-v-ruletku.html
