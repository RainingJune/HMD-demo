//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
int center_x=217;
int center_y=308;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
//x,y是圆中心点的坐标,r1,r2分别是大小圆的半径,rad是aiming-reticle豁口弧度
void TForm4::DrawAimingReticle(int x,int y,int r1,int r2,double rad)
{
		Form4->Canvas->Pen->Color=clLime;
		Form4->Canvas->Pen->Width=1;

		//计算豁口长度
		int delta_1=tan(rad)*r1;
		int delta_2=tan(rad)*r2;
		Form4->Canvas->Arc(x-r1,y-r1,x+r1,y+r1,x+r1,y,x+r1,y+delta_1);
		Form4->Canvas->Arc(x-r2,y-r2,x+r2,y+r2,x+r2,y,x+r2,y+delta_2);   //画笔的方向是逆时针
}
//---------------------------------------------------------------------------
//x,y是“0刻度”所在的位置，long_length和short_length分别是长刻度长度和短刻度长度,gap是刻度间的间距
void TForm4::DrawKiasVelocities(int x,int y,int long_length,int short_length,int gap)
{
		 Form4->Canvas->Pen->Color=clLime;
		 Form4->Canvas->Pen->Width=1;
		 Form4->Canvas->MoveTo(x,y);
		 Form4->Canvas->LineTo(x-long_length,y);
		 for(int i=1;i<=9;i++){
			 y=y-gap;
			 Form4->Canvas->MoveTo(x,y);
			 Form4->Canvas->LineTo(x-short_length,y);
		 }
		 y=y-gap;
		 Form4->Canvas->MoveTo(x,y);
		 Form4->Canvas->LineTo(x-long_length,y);
		 y=y-gap;
		 Form4->Canvas->MoveTo(x,y);
		 Form4->Canvas->LineTo(x-short_length,y);
		 y=y-gap;
		 Form4->Canvas->MoveTo(x,y);
		 Form4->Canvas->LineTo(x-short_length,y);

}
//---------------------------------------------------------------------------
//x,y是“0刻度”所在的位置，long_length和short_length分别是长刻度长度和短刻度长度,gap是刻度间的间距
void TForm4::DrawAltitudeMSL(int x,int y,int long_length,int short_length,int gap)
{

		 for(int i=1;i<=9;i++){
			 Form4->Canvas->MoveTo(x,y);
			 Form4->Canvas->LineTo(x+short_length,y);
			 y=y-gap;
		 }
		 Form4->Canvas->MoveTo(x,y);
		 Form4->Canvas->LineTo(x+long_length,y);
		 y=y-gap;
		 for(int i=1;i<=9;i++){
			 Form4->Canvas->MoveTo(x,y);
			 Form4->Canvas->LineTo(x+short_length,y);
			 y=y-gap;
		 }
}
//---------------------------------------------------------------------------
//x,y是“0刻度”所在的位置，long_length和short_length分别是长刻度长度和短刻度长度,gap是刻度间的间距
void TForm4::DrawGyrocompass(int x,int y,int long_length,int short_length,int gap)
{
	   for(int i=1;i<=9;i++){
			 Form4->Canvas->MoveTo(x,y);
			 Form4->Canvas->LineTo(x,y+short_length);
			 x=x+gap;
		 }
		 Form4->Canvas->MoveTo(x,y);
		 Form4->Canvas->LineTo(x,y+long_length);
		 x=x+gap;

			for(int i=1;i<=9;i++){
			 Form4->Canvas->MoveTo(x,y);
			 Form4->Canvas->LineTo(x,y+short_length);
			 x=x+gap;
		 }
		 Form4->Canvas->MoveTo(x,y);
		 Form4->Canvas->LineTo(x,y+long_length);
		 x=x+gap;

		 for(int i=1;i<=9;i++){
			 Form4->Canvas->MoveTo(x,y);
			 Form4->Canvas->LineTo(x,y+short_length);
			 x=x+gap;
		 }
}
//---------------------------------------------------------------------------
//
void TForm4::DrawLadderPartA(int x,int y,int length)
{
		  Form4->Canvas->MoveTo(x,y);
		  Form4->Canvas->LineTo(x+length,y);
		  Form4->Canvas->MoveTo(x-20,y);
		  Form4->Canvas->LineTo(x-length,y);
}
//---------------------------------------------------------------------------
//x,y是菱形中心的坐标，long_length,short_length分别是两个菱形对应的边长
void TForm4::DrawLadderPartB(int x,int y,int long_length,int short_length)
{
		  Form4->Canvas->MoveTo(x,y-short_length);
		  Form4->Canvas->LineTo(x+short_length,y);

		  Form4->Canvas->MoveTo(x+short_length,y);
		  Form4->Canvas->LineTo(x,y+short_length);

		  Form4->Canvas->MoveTo(x,y+short_length);
		  Form4->Canvas->LineTo(x-short_length,y);

		  Form4->Canvas->MoveTo(x-short_length,y);
		  Form4->Canvas->LineTo(x,y-short_length);

		  Form4->Canvas->MoveTo(x,y-long_length);
		  Form4->Canvas->LineTo(x+long_length,y);
		  Form4->Canvas->LineTo(x,y+long_length);
		  Form4->Canvas->LineTo(x-long_length,y);
		  Form4->Canvas->LineTo(x,y-long_length);
}
//---------------------------------------------------------------------------
//
void TForm4::DrawLadderPartC(int x,int y,int gap)
{
	int x_1=x;
	for(int i=1;i<=4;i++){
		  Form4->Canvas->MoveTo(x_1,y);
		  x_1=x_1+gap;
		  Form4->Canvas->LineTo(x_1,y);
		  x_1=x_1+gap;
		  }
	int x_2=x;
	for(int i=1;i<=4;i++){
		  Form4->Canvas->MoveTo(x_2-gap*2,y);
		  x_2=x_2-gap;
		  Form4->Canvas->LineTo(x_2,y);
		  x_2=x_2-gap;
		  }
}
//---------------------------------------------------------------------------
// margin  边框距离数字的距离
void TForm4::DrawKiasEdge(int margin)
{
	  //int
	  int x=Label12->Left-margin;
	  int y=Label12->Top-margin;

	  Form4->Canvas->MoveTo(x,y);
	  Form4->Canvas->LineTo(x+6*margin,y);
	  Form4->Canvas->LineTo(x+8*margin,y+2*margin);
	  Form4->Canvas->LineTo(x+6*margin,y+4*margin);
	  Form4->Canvas->LineTo(x,y+4*margin);
	  Form4->Canvas->LineTo(x,y);
}
//---------------------------------------------------------------------------
// margin  边框距离数字的距离
void TForm4::DrawAltitudeEdge(int margin)
{
	  //int
	  int x=Label13->Left+4*margin;
	  int y=Label13->Top-margin;

	  Form4->Canvas->MoveTo(x,y);
	  Form4->Canvas->LineTo(x-6*margin,y);
	  Form4->Canvas->LineTo(x-8*margin,y+2*margin);
	  Form4->Canvas->LineTo(x-6*margin,y+4*margin);
	  Form4->Canvas->LineTo(x,y+4*margin);
	  Form4->Canvas->LineTo(x,y);
}
void __fastcall TForm4::FormPaint(TObject *Sender)
{
		  DrawAimingReticle(center_x,center_y,7,25,0.5);
		  DrawKiasVelocities(center_x-100,center_y+60,16,8,8);
		  DrawAltitudeMSL(center_x+100,center_y+60,16,8,8);
		  DrawLadderPartA(center_x-20,center_y+10,150);
		  DrawLadderPartB(center_x-25,center_y+15,12,5);
		  DrawGyrocompass(center_x-150,center_y+250,16,8,8);
		  DrawLadderPartC(center_x,center_y+100,8);
		  DrawKiasEdge(6);
		  DrawAltitudeEdge(6);
}
//---------------------------------------------------------------------------

