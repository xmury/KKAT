import tkinter as tk
import math

class Application(tk.Frame):
    time = 0
    timer_on = False

    
    def __init__(self, master=None):
        tk.Frame.__init__(self, master)
        self.grid()
        self.createWidgets()




    def createWidgets(self):
        self.now = tk.StringVar()
        self.time_b = tk.Button(self, text = '00:00', command=self.timer_go)
        self.time_b.grid(column=2, row=0)
        self.time_b["textvariable"] = self.now
        self.now.set('00:00')
        self.timer()

        self.b1 = tk.Button(self ,  text='счёт1')
        self.b2 = tk.Button(self ,  text='общ1')
        self.arrow1 = tk.Button(self ,  text='стрелка1')
        self.arrow2 = tk.Button(self ,  text='стрелка2')
        self.b3 = tk.Button(self ,  text='счёт2')
        self.b4 = tk.Button(self ,  text='общ2')
        self.b5 = tk.Button(self ,  text='раунд')
        
        self.b1.grid(column=0 , padx=5 , pady=5 , row=0)
        self.b2.grid(column=1 , padx=5 , pady=5 , row=0)
        self.b3.grid(column=3 , padx=5 , pady=5 , row=0)
        self.b4.grid(column=4 , padx=5 , pady=5 , row=0)
        self.b5.grid(column=2 , padx=5 , pady=5 , row=1)
        self.arrow1.grid(columnspan=2, column=0 , padx=5 , pady=5 , row=1)
        self.arrow2.grid(columnspan=2,column=3 , padx=5 , pady=5 , row=1)

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

class Application2(tk.Frame):
    time = 0
    timer_on = False

    
    def __init__(self, master=None):
        tk.Frame.__init__(self, master)
        self.grid()
        self.createWidgets()

    def createWidgets(self):
        self.vol = tk.Button(self ,  text='Волейбол')
        self.bas = tk.Button(self ,  text='Баскетбол')
        self.fut = tk.Button(self ,  text='Футбол')
        self.back = tk.Button(self ,  text='Отменить')
        
        self.vol.grid(column=1 , padx=5 , pady=5 , row=0)
        self.bas.grid(column=2 , padx=5 , pady=5 , row=0)
        self.fut.grid(column=3 , padx=5 , pady=5 , row=0)
        self.back.grid(column=2 , padx=5 , pady=5 , row=4)
        
        i = 1; 
        self.key = [0,0,0,0,0,0,0,0,0,0]
        for cn in range(1,4):
            for rw in range(1,4):
                self.key[i] = tk.Button(self ,  text=i)
                self.key[i].grid(column=cn , padx=5 , pady=5 , row=rw)
                i += 1           

        self.fine1 = tk.Button(self ,  text='Штраф')
        self.fine2 = tk.Button(self ,  text='Штраф')

        self.fine1.grid(column=0 , padx=5 , pady=5 , row=3)
        self.fine2.grid(column=4 , padx=5 , pady=5 , row=3)

        self.prize1 = tk.Button(self ,  text='Добавить очки')
        self.prize2 = tk.Button(self ,  text='Добавить очки')

        self.prize1.grid(column=0 , padx=5 , pady=5 , row=4)
        self.prize2.grid(column=4 , padx=5 , pady=5 , row=4)


root = tk.Tk()
root.geometry()
app = Application(master=root)
app2 = Application2(master=root)

root.grid_columnconfigure((0, 1, 2), weight=1)




# app2 = Application(master=root)

root.mainloop()