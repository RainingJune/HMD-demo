//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <pngimage.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TButton *Button1;
	TButton *Button2;
	void __fastcall FormPaint(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall FormMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);

private:	// User declarations
public:		// User declarations
	__fastcall TForm4(TComponent* Owner);
	void DrawLabel(int x,int y,int size,String labelName,long color);
	void DrawAimingReticle(int x,int y,int r1,int r2,double rad);
	void DrawKiasVelocities(int x,int y,int long_length,int short_length,int gap,int kias,long color);
	void DrawAltitudeMSL(int x,int y,int long_length,int short_length,int gap,int altitude,long color);
	void DrawLadderPartA(int length,int XOY_degree,int XOZ_degree,int height,int bottom,int jianju,long color);
	void DrawGyrocompass(int x,int y,int long_length,int short_length,int gap,int cur_deg);
	void DrawKiasEdge(int x,int y,int margin);
	void DrawAltitudeEdge(int x,int y,int margin);
	void DrawGyroEdge(int x,int y,int margin);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
