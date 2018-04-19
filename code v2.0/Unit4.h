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
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
	TButton *Button1;
	TButton *Button2;
	TStaticText *StaticText1;
	TStaticText *StaticText2;
	TStaticText *StaticText3;
	TStaticText *StaticText4;
	TStaticText *StaticText5;
	TStaticText *StaticText6;
	TStaticText *StaticText7;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
<<<<<<< HEAD
>>>>>>> parent of ef427df... 成熟版本
=======
>>>>>>> parent of ef427df... 成熟版本
=======
>>>>>>> parent of 17c2791... Revert "成熟版本"
=======
>>>>>>> parent of 17c2791... Revert "成熟版本"
=======
>>>>>>> parent of 17c2791... Revert "成熟版本"
=======
>>>>>>> parent of 17c2791... Revert "成熟版本"
	void __fastcall FormPaint(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm4(TComponent* Owner);
	void DrawLabel(int x,int y,int size,String labelName,long color);
	void DrawAimingReticle(int x,int y,int r1,int r2,double rad);
	void DrawKiasVelocities(int x,int y,int long_length,int short_length,int gap,int kias,long color);
	void DrawAltitudeMSL(int x,int y,int long_length,int short_length,int gap,int altitude,long color);
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
	void DestroyAltitudeMSL(int x,int y,int long_length,int short_length,int gap,int altitude);
	void DrawLadderPartA(int x,int y,int length);
=======
	void DrawLadderPartA(int length,int XOY_degree,int XOZ_degree,int height,int bottom,int jianju,long color);
>>>>>>> parent of 17c2791... Revert "成熟版本"
=======
	void DrawLadderPartA(int length,int XOY_degree,int XOZ_degree,int height,int bottom,int jianju,long color);
>>>>>>> parent of 17c2791... Revert "成熟版本"
=======
	void DrawLadderPartA(int length,int XOY_degree,int XOZ_degree,int height,int bottom,int jianju,long color);
>>>>>>> parent of 17c2791... Revert "成熟版本"
=======
	void DrawLadderPartA(int length,int XOY_degree,int XOZ_degree,int height,int bottom,int jianju,long color);
>>>>>>> parent of 17c2791... Revert "成熟版本"
	void DrawLadderPartB(int x,int y,int long_length,int short_length);
	void DrawGyrocompass(int x,int y,int long_length,int short_length,int gap,int cur_deg);
	void DrawLadderPartC(int x,int y,int gap);
	void DrawKiasEdge(int x,int y,int margin);
	void DrawAltitudeEdge(int x,int y,int margin);
	void DrawGyroEdge(int x,int y,int margin);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
