unit Unit1;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, Vcl.ExtCtrls, CPort,
  Vcl.Menus;

type
  TForm1 = class(TForm)
    Panel1: TPanel;
    Panel2: TPanel;
    Label1: TLabel;
    team1: TLabel;
    add11: TButton;
    penalty1: TButton;
    add12: TButton;
    add13: TButton;
    Panel3: TPanel;
    Label3: TLabel;
    team2: TLabel;
    add21: TButton;
    penalty2: TButton;
    add22: TButton;
    add23: TButton;
    Panel4: TPanel;
    time_score: TLabel;
    Panel5: TPanel;
    start: TButton;
    round_plus: TButton;
    Label6: TLabel;
    round_score: TLabel;
    round_min: TButton;
    Panel6: TPanel;
    Panel7: TPanel;
    Panel8: TPanel;
    pause: TButton;
    Timer1: TTimer;
    ComPort1: TComPort;
    MainMenu1: TMainMenu;
    N1: TMenuItem;
    test1: TMenuItem;
    test21: TMenuItem;
    procedure send(Sender: TObject);
    procedure add11Click(Sender: TObject);
    procedure add12Click(Sender: TObject);
    procedure add13Click(Sender: TObject);
    procedure penalty1Click(Sender: TObject);
    procedure add21Click(Sender: TObject);
    procedure add22Click(Sender: TObject);
    procedure add23Click(Sender: TObject);
    procedure penalty2Click(Sender: TObject);
    procedure round_plusClick(Sender: TObject);
    procedure round_minClick(Sender: TObject);
    procedure Button9Click(Sender: TObject);
    procedure startClick(Sender: TObject);
    procedure Timer1Timer(Sender: TObject; test: TForm1);
    procedure test1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

  score1, score2: Integer;
  coins: Integer = 1;
  round: Integer = 1;
  timer: Integer = 0;

  minutes, seconds: Integer;

  time, serial_out: String;

implementation

{$R *.dfm}

procedure TForm1.send(Sender: TObject);
begin
  serial_out := 'S';

  if score1 < 100 then
  begin
    serial_out := Concat(serial_out, '0');
    if score1 < 10 then
    begin
      serial_out := Concat(serial_out, '0', IntToStr(score1), 'X');
    end
    else serial_out := Concat(serial_out, IntToStr(score1), 'X');
  end
  else serial_out := Concat(serial_out, IntToStr(score1), 'X');

  if score2 < 100 then
  begin
    serial_out := Concat(serial_out, '0');
    if score2 < 10 then
    begin
      serial_out := Concat(serial_out, '0', IntToStr(score2), 'X');
    end
    else serial_out := Concat(serial_out, IntToStr(score2), 'X');
  end
  else serial_out := Concat(serial_out, IntToStr(score2), 'X');

  serial_out := Concat(serial_out, IntToStr(round), 'X');

  if minutes < 10 then
  begin
    serial_out := Concat(serial_out, '0', IntToStr(minutes), 'X');
  end
  else serial_out := Concat(serial_out, IntToStr(minutes), 'X');

  if seconds < 10 then
  begin
    serial_out := Concat(serial_out, '0', IntToStr(seconds));
  end
  else serial_out := Concat(serial_out, IntToStr(seconds));
  ComPort1.WriteStr(serial_out);
end;

procedure TForm1.startClick(Sender: TObject);
begin
  Timer1.Enabled:=True;
end;

procedure TForm1.test1Click(Sender: TObject);
begin
  ComPort1.ShowSetupDialog;
  ComPort1.Open;
end;

procedure TForm1.Timer1Timer(Sender: TObject; test: TForm1);
begin
  timer := seconds + 1;
  seconds := timer mod 60;
  minutes := timer div 60 mod 60;

  if (minutes < 10) and (seconds < 10) then
  begin
    time := Concat('0', IntToStr(minutes), ':0', IntToStr(seconds));
  end
  else
  begin
    if minutes < 10  then
    begin
      time := Concat('0', IntToStr(minutes), ':', IntToStr(seconds));
    end;
    if seconds < 10 then
    begin
      time := Concat(IntToStr(minutes),  ':0', IntToStr(seconds));
    end;
    if (minutes > 9) and (seconds > 9) then time := Concat(IntToStr(minutes), ':', IntToStr(seconds));
  end;

  time_score.Caption := time;
  test.send(TObject);
end;

procedure TForm1.round_plusClick(Sender: TObject;);
begin
  if round < 9 then
  begin
    round := round + 1;
    round_score.Caption := IntToStr(round);
  end
  else
  begin
    round := 0;
    round_score.Caption := IntToStr(round);
  end;
end;

procedure TForm1.round_minClick(Sender: TObject);
begin
  if round > 0 then
  begin
    round := round - 1;
    round_score.Caption := IntToStr(round);
  end;
end;

procedure TForm1.add11Click(Sender: TObject);
begin
  score1 := score1 + 1;
  team1.Caption := IntToStr(score1);
end;

procedure TForm1.add12Click(Sender: TObject);
begin
  score1 := score1 + 2;
  team1.Caption := IntToStr(score1);
end;

procedure TForm1.penalty1Click(Sender: TObject);
begin
  if score1 > 0 then
  begin
    score1 := score1 - coins;
    team1.Caption := IntToStr(score1);
  end;
end;

procedure TForm1.add13Click(Sender: TObject);
begin
  score1 := score1 + 3;
  team1.Caption := IntToStr(score1);
end;

procedure TForm1.add21Click(Sender: TObject);
begin
  score2 := score2 + 1;
  team2.Caption := IntToStr(score2);
end;

procedure TForm1.penalty2Click(Sender: TObject);
begin
  if score2 > 0 then
  begin
    score2 := score2 - coins;
    team2.Caption := IntToStr(score2);
  end;
end;

procedure TForm1.add22Click(Sender: TObject);
begin
  score2 := score2 + 2;
  team2.Caption := IntToStr(score2);
end;

procedure TForm1.add23Click(Sender: TObject);
begin
  score2 := score2 + 3;
  team2.Caption := IntToStr(score2);
end;

procedure TForm1.Button9Click(Sender: TObject);
begin
  Timer1.Enabled:=False;
end;

end.
