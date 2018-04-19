object Form4: TForm4
  Left = 0
  Top = 0
  Caption = 'Form4'
  ClientHeight = 617
  ClientWidth = 638
  Color = clBackground
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnMouseDown = FormMouseDown
  OnMouseUp = FormMouseUp
  OnPaint = FormPaint
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 432
    Top = 0
    Width = 410
    Height = 617
    Caption = 'tex'
    TabOrder = 0
    object Button1: TButton
      Left = 16
      Top = 128
      Width = 75
      Height = 25
      Caption = #24320#22987#25509#25910
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 128
      Top = 128
      Width = 75
      Height = 25
      Caption = #20572#27490#25509#25910
      TabOrder = 1
      OnClick = Button2Click
    end
  end
end
