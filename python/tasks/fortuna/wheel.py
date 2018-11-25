import random

class fortuna(object):
    money = 0
    stage = 1

    bet = 0
    value = 0
    index = 0

    wheel = ['0','28','9','26','30','11','7','20','32','17','5','22','34','15','3','24','36','13','1','0','27','10','25','29','12','8','19','31','18','6','21','33','16','4','23','35','14','2']

    def run(self): # Длина, минимальное и максимальное значение
        self.index = random.randint(0 , 35)
        self.value = self.wheel[self.index]
        self.stage+=1
        return self.value

    def bet_in_num(self, bet, money):
        if self.money - money < 0: return "Error"
        self.bet = bet

        if bet == self.run():   
            self.money += money * 35
            return True
        else:                   
            self.money -= money
            return False

    def bet_in_split(self, bet, money):
        if self.money - money < 0: return "Error"
        self.bet = bet

        if bet[0] == self.run() or bet[1] == self.value:   
            self.money += money * 17
            return True
        else:                   
            self.money -= money
            return False

    def bet_in_care(self, bet, money):
        if self.money - money < 0: return "Error"
        self.bet = bet

        if bet[0] == self.run() or bet[1] == self.value or bet[2] == self.value or bet[3] == self.value:   
            self.money += money * 8
            return True
        else:                   
            self.money -= money
            return False

    # Принимает 1 (нечет) или 2 (чёт)
    def bet_in_color(self, bet, money):
        if self.money - money < 0: return "Error"
        self.bet = bet
        self.run()
        if (int(self.value) % 2 and 2 == bet) or (int(self.value) % 2 and 1 == bet):   
            self.money += money * 2
            return True
        else:                   
            self.money -= money
            return False

    # Принимает 0 (1-18) и 1 (19-36)
    def bet_in_half(self, bet, money):
        if self.money - money < 0: return "Error"
        self.bet = bet

        if (int(self.run()) <= 18 and bet == 0) or (int(self.value) > 18 and bet == 1):   
            self.money += money * 2
            return True
        else:                   
            self.money -= money
            return False

    def bet_in_zero(self, money):
        if self.money - money < 0: return "Error"
        self.bet = 0

        if self.run() == '0':   
            self.money += money * 40
            return True
        else:                   
            self.money -= money
            return False

# http://www.mycashed.com/post/pravila-igry-v-ruletku.html