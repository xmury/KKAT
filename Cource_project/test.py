import tkinter as tk
import math
from serial_driver import *

class Application(tk.Frame):
    time = 0
    timer_on = False
    score1 = 0
    score2 = 0
    road = 1
    test = None

    secundes = 0 
    minutes  = 0

    def __init__(self, master=None):
        tk.Frame.__init__(self, master)
        self.grid()
        self.createTablo()
        self.createPanel()

    def createTablo(self):
        self.now = tk.StringVar()
        self.time_b = tk.Button(self, text = '00:00')
        self.time_b["textvariable"] = self.now
        self.now.set('00:00')
        self.timer()

        self.getSerial =    tk.Text(self, height=1,width=20, font='Arial 10')
        self.serialStartT = tk.Button(self , text='COM', command=self.serialStart)

        self.save =         tk.Button(self , text='Сохранить игру')
        self.roadT =        tk.Button(self , text='Период: 1')
        self.roadAddT =     tk.Button(self , text='+', command=self.roadAdd)
        self.roadMinT =     tk.Button(self , text='-', command=self.roadMin)
        self.score1T =      tk.Button(self , text='0')
        self.score2T =      tk.Button(self , text='0')
        self.arrow1 =       tk.Button(self , text='>')
        self.arrow2 =       tk.Button(self , text='<')

        self.time_b.grid(column=3 , row=2, columnspan=3)
        
        self.serialStartT.grid(  column=2 , row=0, padx=5 , pady=5)
        self.getSerial.grid(     column=0 , row=0, padx=5 , pady=5, columnspan=2)

        self.save.grid(  column=7 , row=0, columnspan=2, padx=5 , pady=5)
        self.roadT.grid(  column=4 , row=0,               padx=5 , pady=5)
        self.roadAddT.grid(column=3 ,row=0)
        self.roadMinT.grid(column=5 ,row=0)
        self.score1T.grid(column=1, row=2,               padx=5 , pady=5)
        self.score2T.grid(column=7, row=2,               padx=5 , pady=5)
        self.arrow1.grid(column=2 , row=2)
        self.arrow2.grid(column=6 , row=2)

    def createPanel(self):
        # Для команды 1
        self.shadow1 = tk.Label(self, text='')
        self.shadow2 = tk.Label(self, text='')
        self.shadow1.grid(column=0 , row=1)
        self.shadow2.grid(column=0 , row=3)

        self.add11 = tk.Button(self , text='+1', command=self.score1_add1)
        self.add12 = tk.Button(self , text='+2', command=self.score1_add2)
        self.add13 = tk.Button(self , text='+3', command=self.score1_add3)
        self.min1  = tk.Button(self , text='-1', command=self.score1_min1)

        self.add11.grid(column=0 , row=4, padx=5 , pady=5)
        self.add12.grid(column=1 , row=4, padx=5 , pady=5)
        self.add13.grid(column=2 , row=4, padx=5 , pady=5)
        self.min1.grid( column=0 , row=5, columnspan=3, padx=5 , pady=5)
        # Для команды 2
        self.add21 = tk.Button(self , text='+1', command=self.score2_add1)
        self.add22 = tk.Button(self , text='+2', command=self.score2_add2)
        self.add23 = tk.Button(self , text='+3', command=self.score2_add3)
        self.min2  = tk.Button(self , text='-1', command=self.score2_min1)

        self.add21.grid(column=6 , row=4, padx=5 , pady=5)
        self.add22.grid(column=7 , row=4, padx=5 , pady=5)
        self.add23.grid(column=8 , row=4, padx=5 , pady=5)
        self.min2.grid( column=6 , row=5, columnspan=3, padx=5 , pady=5)

        # Старт и пауза
        self.start  = tk.Button(self , text='Старт', command=self.timer_start)
        self.pause  = tk.Button(self , text='Пауза', command=self.timer_pause)

        self.start.grid(column=4 , row=4, padx=5 , pady=5)
        self.pause.grid(column=4 , row=5, padx=5 , pady=5)

    # Не оптимально, но быстро
    def score1_add1(self): self.score1 += 1; self.score1T['text'] = self.score1
    def score1_add2(self): self.score1 += 2; self.score1T['text'] = self.score1
    def score1_add3(self): self.score1 += 3; self.score1T['text'] = self.score1
    def score1_min1(self): 
        if self.score1 > 0: 
            self.score1 +=-1
            self.score1T['text'] = self.score1
    
    def score2_add1(self): self.score2 += 1; self.score2T['text'] = self.score2
    def score2_add2(self): self.score2 += 2; self.score2T['text'] = self.score2
    def score2_add3(self): self.score2 += 3; self.score2T['text'] = self.score2
    def score2_min1(self): 
        if self.score2 > 0: 
            self.score2 +=-1
            self.score2T['text'] = self.score2

    def timer_start(self):
            self.timer_on = True
    def timer_pause(self):
            self.timer_on = False

    def roadAdd(self):
        if self.road == 9: self.roadT['text'] = 'Период: ' + str(1); self.road = 1
        else:  self.road += 1; self.roadT['text'] = 'Период: ' + str(self.road)
    def roadMin(self):
        if self.road == 1: self.roadT['text'] = 'Период: ' + str(9); self.road = 9
        else:  self.road -= 1; self.roadT['text'] = 'Период: ' + str(self.road)

    def timer(self):
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
            self.now.set(time_f)

            # Отправка на табло значений
            if self.test != None: self.send()
        self.after(1000, self.timer)

    def serialStart(self):
        text = self.getSerial.get('1.0', '10.0')
        text = text.rstrip()
        print(len(text))
        self.test = serialDriver(text)
        self.test.open()
        
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
        self.test.write(text)

root = tk.Tk()
root.geometry()
app = Application(master=root)

root.grid_columnconfigure((0, 1, 2), weight=1)
root.mainloop()