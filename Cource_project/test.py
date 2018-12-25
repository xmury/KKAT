import tkinter as tk
import math
from serial_driver import *

class Application(tk.Frame):
    time = 0
    timer_on = False
    
    def __init__(self, master=None):
        tk.Frame.__init__(self, master)
        self.grid()
        self.createTablo()
        self.createPanel()

    def createTablo(self):
        self.now = tk.StringVar()
        self.time_b = tk.Button(self, text = '00:00', command=self.timer_go)
        self.time_b["textvariable"] = self.now
        self.now.set('00:00')
        self.timer()

        self.load =     tk.Button(self , text='Загрузить игру')
        self.save =     tk.Button(self , text='Сохранить игру')
        self.road =     tk.Button(self , text='Период: 0')
        self.score1 =   tk.Button(self , text='0')
        self.score2 =   tk.Button(self , text='0')
        self.arrow1 =   tk.Button(self , text='>')
        self.arrow2 =   tk.Button(self , text='<')

        self.time_b.grid(column=3 , row=2, columnspan=3)
        
        self.load.grid(  column=0 , row=0, columnspan=2, padx=5 , pady=5)
        self.save.grid(  column=7 , row=0, columnspan=2, padx=5 , pady=5)
        self.road.grid(  column=4 , row=0,               padx=5 , pady=5)
        self.score1.grid(column=1 , row=2,               padx=5 , pady=5)
        self.score2.grid(column=7 , row=2,               padx=5 , pady=5)
        self.arrow1.grid(column=2 , row=2)
        self.arrow2.grid(column=6 , row=2)

    def createPanel(self):
        # Для команды 1
        self.shadow1 = tk.Label(self, text='')
        self.shadow2 = tk.Label(self, text='')
        self.shadow1.grid(column=0 , row=1)
        self.shadow2.grid(column=0 , row=3)

        self.add11 = tk.Button(self , text='+1')
        self.add12 = tk.Button(self , text='+2')
        self.add13 = tk.Button(self , text='+3')
        self.min1  = tk.Button(self , text='-1')

        self.add11.grid(column=0 , row=4, padx=5 , pady=5)
        self.add12.grid(column=1 , row=4, padx=5 , pady=5)
        self.add13.grid(column=2 , row=4, padx=5 , pady=5)
        self.min1.grid( column=0 , row=5, columnspan=3, padx=5 , pady=5)
        # Для команды 2
        self.add21 = tk.Button(self , text='+1')
        self.add22 = tk.Button(self , text='+2')
        self.add23 = tk.Button(self , text='+3')
        self.min2  = tk.Button(self , text='-1')

        self.add21.grid(column=6 , row=4, padx=5 , pady=5)
        self.add22.grid(column=7 , row=4, padx=5 , pady=5)
        self.add23.grid(column=8 , row=4, padx=5 , pady=5)
        self.min2.grid( column=6 , row=5, columnspan=3, padx=5 , pady=5)

        # Старт и пауза
        self.start  = tk.Button(self , text='Старт')
        self.pause  = tk.Button(self , text='Пауза')

        self.start.grid(column=4 , row=4, padx=5 , pady=5)
        self.pause.grid(column=4 , row=5, padx=5 , pady=5)


    def timer_go(self):
        if self.timer_on:
            self.timer_on = False
        else:
            self.timer_on = True

    def timer(self):
        if self.timer_on == True:
            self.time += 1
            secundes = self.time % 60
            minutes = math.floor(self.time / 60 % 60)

            if minutes < 10:
                time_f = "0" + str(minutes) + " : "
            else:
                time_f = str(minutes) + " : "

            if secundes < 10:
                time_f += "0" + str(secundes)
            else:
                time_f += str(secundes)

            print(time_f)
            self.now.set(time_f)
        self.after(1000, self.timer)

root = tk.Tk()
root.geometry()
app = Application(master=root)

root.grid_columnconfigure((0, 1, 2), weight=1)
root.mainloop()