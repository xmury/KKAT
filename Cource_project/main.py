from board_fun import board_fun

import kivy

# from kivy.app import App
from kivy.clock import Clock
from kivy.uix.button import Button
from kivy.uix.label import Label
from kivy.uix.boxlayout import BoxLayout

from kivy.uix.image import Image
from kivy.core.window import Window
from kivy.properties import StringProperty

class MyLabel(Image):
    # https://stackoverrun.com/ru/q/13108579 
    text = StringProperty('') 

    def on_text(self, *_): 
        l = Label(text=self.text) 
        l.font_size = '1000dp' 
        l.texture_update() 
        
        self.texture = l.texture 

class board_gui(board_fun):
    team_num = 1

    def build(self):
        layout = BoxLayout(orientation='horizontal')
        layout.add_widget(self.add_team_widget(self.team1))
        layout.add_widget(self.add_tablo())
        layout.add_widget(self.add_team_widget(self.team2))
        Clock.schedule_interval(self.timer, 1)

        return layout
        
    def add_team_widget(self, team):
        master = BoxLayout(orientation='vertical')

        team['l_team']  = MyLabel(text='  Команда ' + str(self.team_num) + '  ')#, #font_size='50', size_hint=(1,.4))
        self.team_num += 1
        # MyLabel(text='Test test test')
        
        slave2 = BoxLayout(orientation='vertical', padding = 20)
        team['l_score'] = MyLabel(text='0')
        team['test'] = Label(text='   ', size_hint=(1,.5))
        slave2.add_widget(team['l_score'])

        team['minus'] = Button(on_press=self.score_min1 ,text = "-1", size_hint=(1,.4))
        
        slave1 = BoxLayout(orientation='horizontal', size_hint=(1,.4))

        team['add1']  = Button(on_press=self.score_add1 ,text = "+1")
        team['add2']  = Button(on_press=self.score_add2 ,text = "+2")
        team['add3']  = Button(on_press=self.score_add3 ,text = "+3")
        slave1.add_widget(team['add1'])
        slave1.add_widget(team['add2'])
        slave1.add_widget(team['add3'])

        master.add_widget(team['l_team'] )
        master.add_widget(slave2)
        master.add_widget(team['test'] )
        master.add_widget(slave1)
        master.add_widget(team['minus'])

        return master

    def add_tablo(self):
        master = BoxLayout(orientation='vertical')

        self.tablo['l_road_text'] = MyLabel(text='   Период   ')#, font_size='50')        

        slave1 = BoxLayout(orientation='horizontal')

        self.tablo['plus']   = Button(on_press=self.roadAdd ,text = "+", size_hint=(.4,1))
        self.tablo['l_road'] = MyLabel(text=' 1 ')#, font_size='150', size_hint=(1,1))        
        self.tablo['minus']  = Button(on_press=self.roadMin ,text = "-", size_hint=(.4,1))

        slave1.add_widget(self.tablo['plus'])
        slave1.add_widget(self.tablo['l_road'])
        slave1.add_widget(self.tablo['minus'])

        self.tablo['l_timer'] = MyLabel(text=' 00:00 ')#, font_size='50')        

        slave2 = BoxLayout(orientation='horizontal', size_hint=(1,.4))
        self.tablo['pause'] = Button(on_press=self.timer_pause ,text = "Пауза")
        self.tablo['start'] = Button(on_press=self.timer_start ,text = "Старт")

        slave2.add_widget(self.tablo['pause'])
        slave2.add_widget(self.tablo['start'])

        master.add_widget(self.tablo['l_road_text'])
        master.add_widget(slave1)
        master.add_widget(self.tablo['l_timer'])
        master.add_widget(slave2)

        return master

if __name__ == "__main__":
	board_gui().run()