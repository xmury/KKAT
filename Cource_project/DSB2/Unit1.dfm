object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 437
  ClientWidth = 696
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 193
    Height = 437
    Align = alLeft
    AutoSize = True
    TabOrder = 0
    object Label1: TLabel
      Left = 1
      Top = 1
      Width = 191
      Height = 40
      Align = alTop
      Alignment = taCenter
      Caption = #1050#1086#1084#1072#1085#1076#1072' 1'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -33
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      ExplicitWidth = 158
    end
    object team1: TLabel
      Left = 1
      Top = 41
      Width = 191
      Height = 305
      Align = alClient
      Alignment = taCenter
      Caption = '0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -200
      Font.Name = 'DS-Digital'
      Font.Style = []
      ParentFont = False
      Layout = tlCenter
      ExplicitWidth = 98
      ExplicitHeight = 198
    end
    object Panel7: TPanel
      Left = 1
      Top = 346
      Width = 191
      Height = 90
      Align = alBottom
      AutoSize = True
      TabOrder = 0
      object add11: TButton
        Left = 1
        Top = 1
        Width = 62
        Height = 43
        Align = alLeft
        Caption = '+1'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -40
        Font.Name = 'DS-Digital'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        OnClick = add11Click
      end
      object add12: TButton
        Left = 63
        Top = 1
        Width = 65
        Height = 43
        Align = alClient
        Caption = '+2'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -40
        Font.Name = 'DS-Digital'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = add12Click
      end
      object penalty1: TButton
        Left = 1
        Top = 44
        Width = 189
        Height = 45
        Align = alBottom
        Caption = '-1'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -40
        Font.Name = 'DS-Digital'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        OnClick = penalty1Click
      end
      object add13: TButton
        Left = 128
        Top = 1
        Width = 62
        Height = 43
        Align = alRight
        Caption = '+2'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -40
        Font.Name = 'DS-Digital'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        OnClick = add13Click
      end
    end
  end
  object Panel2: TPanel
    Left = 193
    Top = 0
    Width = 310
    Height = 437
    Align = alClient
    AutoSize = True
    TabOrder = 1
    object Panel4: TPanel
      Left = 1
      Top = 1
      Width = 308
      Height = 193
      Align = alTop
      AutoSize = True
      TabOrder = 0
      object Label6: TLabel
        Left = 1
        Top = 1
        Width = 306
        Height = 33
        Align = alTop
        Alignment = taCenter
        Caption = #1055#1077#1088#1080#1086#1076
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        ExplicitWidth = 92
      end
      object round_score: TLabel
        Left = 34
        Top = 34
        Width = 239
        Height = 158
        Align = alClient
        Alignment = taCenter
        Caption = '1'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -133
        Font.Name = 'DS-Digital'
        Font.Style = []
        ParentFont = False
        Layout = tlCenter
        ExplicitWidth = 35
        ExplicitHeight = 132
      end
      object round_plus: TButton
        Left = 1
        Top = 34
        Width = 33
        Height = 158
        Align = alLeft
        Caption = '+'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -40
        Font.Name = 'DS-Digital'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        OnClick = round_plusClick
      end
      object round_min: TButton
        Left = 273
        Top = 34
        Width = 34
        Height = 158
        Align = alRight
        Caption = '-'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -40
        Font.Name = 'DS-Digital'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = round_minClick
      end
    end
    object Panel5: TPanel
      Left = 1
      Top = 250
      Width = 308
      Height = 186
      Align = alBottom
      AutoSize = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      object time_score: TLabel
        Left = 1
        Top = 1
        Width = 306
        Height = 143
        Align = alClient
        Alignment = taCenter
        Caption = '00:00'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -120
        Font.Name = 'DS-Digital'
        Font.Style = []
        ParentFont = False
        Layout = tlCenter
        ExplicitWidth = 262
        ExplicitHeight = 118
      end
      object Panel6: TPanel
        Left = 1
        Top = 144
        Width = 306
        Height = 41
        Align = alBottom
        AutoSize = True
        TabOrder = 0
        object start: TButton
          Left = 190
          Top = 1
          Width = 115
          Height = 39
          Align = alRight
          Caption = #1057#1090#1072#1088#1090
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -20
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          OnClick = startClick
        end
        object pause: TButton
          Left = 1
          Top = 1
          Width = 115
          Height = 39
          Align = alLeft
          Caption = #1055#1072#1091#1079#1072
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -20
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          OnClick = Button9Click
        end
      end
    end
  end
  object Panel3: TPanel
    Left = 503
    Top = 0
    Width = 193
    Height = 437
    Align = alRight
    AutoSize = True
    TabOrder = 2
    object Label3: TLabel
      Left = 1
      Top = 1
      Width = 191
      Height = 40
      Align = alTop
      Alignment = taCenter
      Caption = #1050#1086#1084#1072#1085#1076#1072' 2'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -33
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      ExplicitWidth = 158
    end
    object team2: TLabel
      Left = 1
      Top = 41
      Width = 191
      Height = 305
      Align = alClient
      Alignment = taCenter
      Caption = '0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -200
      Font.Name = 'DS-Digital'
      Font.Style = []
      ParentFont = False
      Layout = tlCenter
      ExplicitWidth = 98
      ExplicitHeight = 198
    end
    object Panel8: TPanel
      Left = 1
      Top = 346
      Width = 191
      Height = 90
      Align = alBottom
      AutoSize = True
      TabOrder = 0
      object add21: TButton
        Left = 1
        Top = 1
        Width = 62
        Height = 43
        Align = alLeft
        Caption = '+1'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -40
        Font.Name = 'DS-Digital'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        OnClick = add21Click
      end
      object penalty2: TButton
        Left = 1
        Top = 44
        Width = 189
        Height = 45
        Align = alBottom
        Caption = '-1'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -40
        Font.Name = 'DS-Digital'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = penalty2Click
      end
      object add22: TButton
        Left = 63
        Top = 1
        Width = 65
        Height = 43
        Align = alClient
        Caption = '+2'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -40
        Font.Name = 'DS-Digital'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        OnClick = add22Click
      end
      object add23: TButton
        Left = 128
        Top = 1
        Width = 62
        Height = 43
        Align = alRight
        Caption = '+2'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -40
        Font.Name = 'DS-Digital'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        OnClick = add23Click
      end
    end
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 65533
    Top = 48
  end
  object ComPort1: TComPort
    Connected = True
    BaudRate = br9600
    Port = 'COM6'
    Parity.Bits = prNone
    StopBits = sbOneStopBit
    DataBits = dbEight
    Events = [evRxChar, evTxEmpty, evRxFlag, evRing, evBreak, evCTS, evDSR, evError, evRLSD, evRx80Full]
    FlowControl.OutCTSFlow = False
    FlowControl.OutDSRFlow = False
    FlowControl.ControlDTR = dtrDisable
    FlowControl.ControlRTS = rtsDisable
    FlowControl.XonXoffOut = False
    FlowControl.XonXoffIn = False
    StoredProps = [spBasic]
    TriggersOnRxChar = True
    Top = 104
  end
  object MainMenu1: TMainMenu
    Left = 1
    Top = 160
    object N1: TMenuItem
      Caption = #1058#1080#1087' '#1087#1086#1076#1082#1083#1102#1095#1077#1085#1080#1103
      object test1: TMenuItem
        Caption = 'COM'
        OnClick = test1Click
      end
      object test21: TMenuItem
        Caption = 'WIFI'
      end
    end
  end
end