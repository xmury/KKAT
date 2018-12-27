from kivy.app import App
from serialDriver import serialDriver
import math

class board_fun(App):
    time = 0
    score1 = 0
    score2 = 0
    road = 1

    serial_enable = None
    timer_on = False

    secundes = 0 
    minutes  = 0

    team1 = {}
    team2 = {}
    tablo = {}

    def score_add1(self, instance): 
        if self.timer_on == True:
            if self.team1['add1'] == instance:
                self.score1 += 1; self.team1['l_score'].text = str(self.score1)
            else:
                self.score2 += 1; self.team2['l_score'].text = str(self.score2)

    def score_add2(self, instance): 
        if self.timer_on == True:
            if self.team1['add2'] == instance:
                self.score1 += 2; self.team1['l_score'].text = str(self.score1)
            else:
                self.score2 += 2; self.team2['l_score'].text = str(self.score2)

    def score_add3(self, instance): 
        if self.timer_on == True:
            if self.team1['add3'] == instance:
                self.score1 += 3; self.team1['l_score'].text = str(self.score1)
            else:
                self.score2 += 3; self.team2['l_score'].text = str(self.score2)

    def score_min1(self, instance): 
        if self.team1['minus'] == instance:
            if self.score1 > 0: 
                self.score1 +=-1
                self.team1['l_score'].text = str(self.score1)
        else:
            if self.score2 > 0: 
                self.score2 +=-1
                self.team2['l_score'].text = str(self.score2)

    def roadAdd(self, instance):
        if self.timer_on == True:
            if self.road == 9: pass
            else:  self.road += 1; self.tablo['l_road'].text = str(self.road)
    def roadMin(self, instance):
        if self.timer_on == True:        
            if self.road == 1: self.tablo['l_road'].text = str(9); self.road = 9
            else:  self.road -= 1; self.tablo['l_road'].text = str(self.road)

    def timer(self, incom):
        if self.timer_on == True:
            self.time += 1
            self.secundes = self.time % 60
            self.minutes = math.floor(self.time / 60 % 60)

            if self.minutes < 10:
                time_f = "0" + str(self.minutes) + " : "
            else:
                time_f = str(self.minutes) + " : "

            if self.secundes < 10:
                time_f += "0" + str(self.secundes)
            else:
                time_f += str(self.secundes)

            print(time_f)
            self.tablo['l_timer'].text = time_f

            # Отправка на табло значений
            if self.serial_enable != None: self.send()

    def timer_start(self, instance):
            self.timer_on = True

    def timer_pause(self, instance):
            self.timer_on = False

    def serialStart(self):
        text = self.getSerial.get('1.0', '10.0')
        text = text.rstrip()
        print(text)
        self.serial_enable = serialDriver(text)
        self.serial_enable.open()
        
        self.send()

    def send(self):
        # /dev/ttyACM3
        # S100X100X1X60X59
        text = 'S'
        # score1
        if   self.score1 > 99:  text +=        str(self.score1)
        elif self.score1 > 9:   text += '0'  + str(self.score1)
        else:                   text += '00' + str(self.score1)
        text += 'X'
        # score2
        if   self.score2 > 99:  text +=        str(self.score2)
        elif self.score2 > 9:   text += '0'  + str(self.score2)
        else:                   text += '00' + str(self.score2)
        # road
        text += 'X' + str(self.road) + 'X'
        # minutes
        if   self.minutes > 9:  text +=        str(self.minutes)
        else:                   text += '0'  + str(self.minutes)
        text += 'X'        
        # secundes
        if   self.secundes > 9: text +=        str(self.secundes)
        else:                   text += '0'  + str(self.secundes)

        print(text)
        self.serial_enable.write(text)