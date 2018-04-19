//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#include <stdio.h>
#include <winsock.h>
#include <conio.h>
#pragma hdrstop

#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
int center_x=350;           //×ø±êÔ­µã
int center_y=240;           //×ø±êÔ­µã
int loop_flag=1;            //ÊÇ·ñ¼ÌĞøÑ­»·½ÓÊÜÊı¾İµÄ±êÖ¾
int x_mark_v=211;           //"V"±ê¼ÇµÄºá×İ×ø±ê
int y_mark_v=533;
<<<<<<< HEAD
<<<<<<< HEAD
int x_mark_youjiantou=480;   //">"±ê¼ÇµÄºá×İ×ø±ê
int y_mark_youjiantou=236;
int x_mark_zuojiantou=216;    //"<"±ê¼ÇµÄºá×İ×ø±ê
int y_mark_zuojiantou=238;
int pre_kias=000;              //Ç°Ò»¸ökias,altitude
int pre_altitude=000;
=======
=======
>>>>>>> parent of ef427df... æˆç†Ÿç‰ˆæœ¬
int x_mark_youjiantou=302;   //">"±ê¼ÇµÄºá×İ×ø±ê
int y_mark_youjiantou=365;
int x_mark_zuojiantou=122;    //"<"±ê¼ÇµÄºá×İ×ø±ê
int y_mark_zuojiantou=365;
int pre_kias=111;              //Ç°Ò»¸ökias,altitude
int pre_altitude=666;
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> parent of ef427df... æˆç†Ÿç‰ˆæœ¬
=======
>>>>>>> parent of ef427df... æˆç†Ÿç‰ˆæœ¬
int pre_XOY_degree=0;
int pre_XOZ_degree=0;
=======
>>>>>>> parent of d412669... æˆç†Ÿçš„ç‰ˆæœ¬
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
//x,yÊÇÔ²ÖĞĞÄµãµÄ×ø±ê,r1,r2·Ö±ğÊÇ´óĞ¡Ô²µÄ°ë¾¶,radÊÇaiming-reticle»í¿Ú»¡¶È
void TForm4::DrawAimingReticle(int x,int y,int r1,int r2,double rad)
{
		Form4->Canvas->Pen->Color=clLime;
		Form4->Canvas->Pen->Width=1;

		//¼ÆËã»í¿Ú³¤¶È
		int delta_1=tan(rad)*r1;
		int delta_2=tan(rad)*r2;
		Form4->Canvas->Arc(x-r1,y-r1,x+r1,y+r1,x+r1,y,x+r1,y+delta_1);
		Form4->Canvas->Arc(x-r2,y-r2,x+r2,y+r2,x+r2,y,x+r2,y+delta_2);   //»­±ÊµÄ·½ÏòÊÇÄæÊ±Õë
}
//---------------------------------------------------------------------------
//x,yÊÇ¡°0¿Ì¶È¡±ËùÔÚµÄÎ»ÖÃ£¬long_lengthºÍshort_length·Ö±ğÊÇ³¤¿Ì¶È³¤¶ÈºÍ¶Ì¿Ì¶È³¤¶È,gapÊÇ¿Ì¶È¼äµÄ¼ä¾à
void TForm4::DrawKiasVelocities(int x,int y,int long_length,int short_length,int gap,int kias,long color)
{
<<<<<<< HEAD
<<<<<<< HEAD
		 DrawLabel(x+4,y-10,13,"<",clLime);
=======
>>>>>>> parent of ef427df... æˆç†Ÿç‰ˆæœ¬
=======
>>>>>>> parent of ef427df... æˆç†Ÿç‰ˆæœ¬
		 Form4->Canvas->Pen->Color=color;
		 Form4->Canvas->Pen->Width=1;
		 int x_ini=x;            //±£´æ×ø±ê³õÊ¼Öµ
		 int y_ini=y;
		 int bottom_value=kias/10;
		 int top_value=(bottom_value+1)*10;
		 bottom_value=bottom_value*10;
		 //ÏÂ·½´ı»®Ïß    ÏßÌõ×ÜÊıÎª20, label "<" ÉÏ·½ÓĞÊ®ÌõÏß,ÏÂ·½ÓĞÈıÊ®ÌõÏß
		 int bottom_line_number=kias-bottom_value;
		 int i=1;
		 for(i=1;i<=bottom_line_number;i++){
			Form4->Canvas->MoveTo(x,y);
			Form4->Canvas->LineTo(x-short_length,y);
			y=y+gap;
			}
		 //»­³¤ÏßÌõ²¢ÔÚ³¤ÏßÌõÏÂÌâ×Ö
		 Form4->Canvas->MoveTo(x,y);
		 Form4->Canvas->LineTo(x-long_length,y);
		 Canvas->Font->Color=color;         //Ê×ÏÈÉèÖÃ×ÖÌåÑÕÉ«
		 Canvas->TextOutA(x-long_length-10,y-5,IntToStr(bottom_value/10));
		 y=y+gap;
		 //»­ÏÂ·½Ê£ÓàµÄÏßÌõ
		 int remain_line_number=10-bottom_line_number-1;
		 for(i=1;i<=remain_line_number;i++){
			if(i==10){
				Form4->Canvas->MoveTo(x,y);
				Form4->Canvas->LineTo(x-long_length,y);
				Canvas->TextOutA(x-long_length-10,y-5,IntToStr((bottom_value-1)/10));
				y=y+gap;
				}
			Form4->Canvas->MoveTo(x,y);
			Form4->Canvas->LineTo(x-short_length,y);
			y=y+gap;
		 }

		 //»­ÉÏ·½µÄÏßÌõ
		 x=x_ini;
		 y=y_ini;	//È¡³õÊ¼Öµ
		 int top_line_number=top_value-kias;
		 y=y-gap;
		 for(i=1;i<=top_line_number-1;i++){    //±Èleft_lineÉÙ»­Ò»Ìõ
			Form4->Canvas->MoveTo(x,y);
			Form4->Canvas->LineTo(x-short_length,y);
			y=y-gap;
			}
		 //»­³¤ÏßÌõ²¢ÔÚ³¤ÏßÌõÏÂÌâ×Ö
		 Form4->Canvas->MoveTo(x,y);
		 Form4->Canvas->LineTo(x-long_length,y);
		 Canvas->TextOutA(x-long_length-10,y-5,IntToStr(top_value/10));
		 y=y-gap;
		 //»­ÉÏ·½Ê£ÓàµÄÏßÌõ
		 remain_line_number=10-top_line_number-1;
		 for(i=1;i<=remain_line_number;i++){
			if(i==10){
				Form4->Canvas->MoveTo(x,y);
				Form4->Canvas->LineTo(x+long_length,y);
				Canvas->TextOutA(x-long_length-10,y-5,IntToStr((top_value-1)/10));
				y=y-gap;
				}
			Form4->Canvas->MoveTo(x,y);
			Form4->Canvas->LineTo(x-short_length,y);
			y=y-gap;
		 }

}
//
void TForm4::DestroyKiasVelocities(int x,int y,int long_length,int short_length,int gap,int kias)
{
			DrawKiasVelocities(x,y,long_length,short_length,gap,kias,clBackground);
}
//---------------------------------------------------------------------------
//x,yÊÇ¡°>¡±ËùÔÚµÄÎ»ÖÃ£¬long_lengthºÍshort_length·Ö±ğÊÇ³¤¿Ì¶È³¤¶ÈºÍ¶Ì¿Ì¶È³¤¶È,gapÊÇ¿Ì¶È¼äµÄ¼ä¾à
void TForm4::DrawAltitudeMSL(int x,int y,int long_length,int short_length,int gap,int altitude,long color)
{
<<<<<<< HEAD
<<<<<<< HEAD
		 DrawLabel(x-10,y-12,13,">",clLime);
=======
>>>>>>> parent of ef427df... æˆç†Ÿç‰ˆæœ¬
=======
>>>>>>> parent of ef427df... æˆç†Ÿç‰ˆæœ¬
		 Form4->Canvas->Pen->Color=color;
		 Form4->Canvas->Pen->Width=1;
		 int x_ini=x;            //±£´æ×ø±ê³õÊ¼Öµ
		 int y_ini=y;
		 int bottom_value=altitude/1000;
		 int top_value=(bottom_value+1)*10;
		 bottom_value=bottom_value*10;
		 //ÏÂ·½´ı»®Ïß    ÏßÌõ×ÜÊıÎª20, label "v" ÉÏ·½ÓĞÊ®ÌõÏß,ÏÂ·½ÓĞÈıÊ®ÌõÏß
		 int bottom_line_number=altitude/100-bottom_value;
		 int i=1;
		 for(i=1;i<=bottom_line_number;i++){
			Form4->Canvas->MoveTo(x,y);
			Form4->Canvas->LineTo(x+short_length,y);
			y=y+gap;
			}
		 //»­³¤ÏßÌõ²¢ÔÚ³¤ÏßÌõÏÂÌâ×Ö
		 Form4->Canvas->MoveTo(x,y);
		 Form4->Canvas->LineTo(x+long_length,y);
		 Canvas->Font->Color=color;         //Ê×ÏÈÉèÖÃ×ÖÌåÑÕÉ«
		 Canvas->TextOutA(x+long_length+5,y-5,IntToStr(bottom_value/10));
		 y=y+gap;
		 //»­ÏÂ·½Ê£ÓàµÄÏßÌõ
		 int remain_line_number=10-bottom_line_number-1;
		 for(i=1;i<=remain_line_number;i++){
			if(i==10){
				Form4->Canvas->MoveTo(x,y);
				Form4->Canvas->LineTo(x+long_length,y);
				Canvas->TextOutA(x+long_length+5,y-5,IntToStr((bottom_value-1)/10));
				y=y+gap;
				}
			Form4->Canvas->MoveTo(x,y);
			Form4->Canvas->LineTo(x+short_length,y);
			y=y+gap;
		 }

		 //»­ÉÏ·½µÄÏßÌõ
		 x=x_ini;
		 y=y_ini;	//È¡³õÊ¼Öµ
		 int top_line_number=top_value-altitude/100;
		 y=y-gap;
		 for(i=1;i<=top_line_number-1;i++){    //±Èleft_lineÉÙ»­Ò»Ìõ
			Form4->Canvas->MoveTo(x,y);
			Form4->Canvas->LineTo(x+short_length,y);
			y=y-gap;
			}
		 //»­³¤ÏßÌõ²¢ÔÚ³¤ÏßÌõÏÂÌâ×Ö
		 Form4->Canvas->MoveTo(x,y);
		 Form4->Canvas->LineTo(x+long_length,y);
		 Canvas->TextOutA(x+long_length+5,y-5,IntToStr(top_value/10));
		 y=y-gap;
		 //»­ÉÏ·½Ê£ÓàµÄÏßÌõ
		 remain_line_number=10-top_line_number-1;
		 for(i=1;i<=remain_line_number;i++){
			if(i==10){
				Form4->Canvas->MoveTo(x,y);
				Form4->Canvas->LineTo(x+long_length,y);
				Canvas->TextOutA(x+long_length+5,y-5,IntToStr((top_value-1)/10));
				y=y-gap;
				}
			Form4->Canvas->MoveTo(x,y);
			Form4->Canvas->LineTo(x+short_length,y);
			y=y-gap;
		 }
}
//x,yÊÇ¡°>¡±ËùÔÚµÄÎ»ÖÃ£¬long_lengthºÍshort_length·Ö±ğÊÇ³¤¿Ì¶È³¤¶ÈºÍ¶Ì¿Ì¶È³¤¶È,gapÊÇ¿Ì¶È¼äµÄ¼ä¾à
void TForm4::DestroyAltitudeMSL(int x,int y,int long_length,int short_length,int gap,int altitude)
{
		   DrawAltitudeMSL(x,y,long_length,short_length,gap,altitude,clBackground);
}
//---------------------------------------------------------------------------
//x,yÊÇ±êÇ©Gyromarker ±êÇ©"v"ËùÔÚµÄÎ»ÖÃ£¬long_lengthºÍshort_length·Ö±ğÊÇ³¤¿Ì¶È³¤¶ÈºÍ¶Ì¿Ì¶È³¤¶È,gapÊÇ¿Ì¶È¼äµÄ¼ä¾à
void TForm4::DrawGyrocompass(int x,int y,int long_length,int short_length,int gap,int cur_deg)
{
		 Form4->Canvas->Pen->Color=clLime;
		 Form4->Canvas->Pen->Width=1;
		 int x_ini=x;            //±£´æ×ø±ê³õÊ¼Öµ
		 int y_ini=y;
		 int left_value=cur_deg/10;
		 int right_value=(left_value+1)*10;
		 left_value=left_value*10;
		 //×ó±ß´ı»®Ïß    (ÏßÌõ×ÜÊıÎª30,maker label "v" ×ó±ßÓĞÈıÊ®ÌõÏß,ÓÒ±ßÓĞÈıÊ®ÌõÏß
		 int left_line_number=cur_deg-left_value;
		 int i=1;
		 for(i=1;i<=left_line_number;i++){
			Form4->Canvas->MoveTo(x,y);
			Form4->Canvas->LineTo(x,y+short_length);
			x=x-gap;
			}
		 //»­³¤ÏßÌõ²¢ÔÚ³¤ÏßÌõÏÂÌâ×Ö
		 Form4->Canvas->MoveTo(x,y);
		 Form4->Canvas->LineTo(x,y+long_length);
		 Canvas->Font->Color=clLime;         //Ê×ÏÈÉèÖÃ×ÖÌåÑÕÉ«
		 Canvas->TextOutA(x,y+long_length+10,IntToStr(left_value/10));
		 x=x-gap;
		 //»­×ó±ßÊ£ÓàµÄÏßÌõ
		 int remain_line_number=15-left_line_number-1;
		 for(i=1;i<=remain_line_number;i++){
			if(i==10){
				Form4->Canvas->MoveTo(x,y);
				Form4->Canvas->LineTo(x,y+long_length);
				Canvas->TextOutA(x,y+long_length+10,IntToStr((left_value-1)/10));
				x=x-gap;
				}
			Form4->Canvas->MoveTo(x,y);
			Form4->Canvas->LineTo(x,y+short_length);
			x=x-gap;
		 }

		 //»­ÓÒ±ßµÄÏßÌõ
		 x=x_ini;
		 y=y_ini;	//È¡³õÊ¼Öµ
		 int right_line_number=right_value-cur_deg;
		 x=x+gap;
		 for(i=1;i<=right_line_number-1;i++){    //±Èleft_lineÉÙ»­Ò»Ìõ
			Form4->Canvas->MoveTo(x,y);
			Form4->Canvas->LineTo(x,y+short_length);
			x=x+gap;
			}
		 //»­³¤ÏßÌõ²¢ÔÚ³¤ÏßÌõÏÂÌâ×Ö
		 Form4->Canvas->MoveTo(x,y);
		 Form4->Canvas->LineTo(x,y+long_length);
		 Canvas->Font->Color=clLime;         //Ê×ÏÈÉèÖÃ×ÖÌåÑÕÉ«
		 Canvas->TextOutA(x,y+long_length+10,IntToStr(right_value/10));
		 x=x+gap;
		 //»­ÓÒ±ß±ßÊ£ÓàµÄÏßÌõ
		 remain_line_number=15-right_line_number-1;
		 for(i=1;i<=remain_line_number;i++){
			if(i==10){
				Form4->Canvas->MoveTo(x,y);
				Form4->Canvas->LineTo(x,y+long_length);
				Canvas->TextOutA(x,y+long_length+10,IntToStr((left_value-1)/10));
				x=x+gap;
				}
			Form4->Canvas->MoveTo(x,y);
			Form4->Canvas->LineTo(x,y+short_length);
			x=x+gap;
		 }
}
//---------------------------------------------------------------------------
//
void TForm4::DrawLadderPartA(int x,int y,int length)
{
		  Form4->Canvas->Pen->Color=clLime;
		  Form4->Canvas->Pen->Width=1;
		  Form4->Canvas->MoveTo(x,y);
		  Form4->Canvas->LineTo(x+length,y);
		  Form4->Canvas->MoveTo(x-20,y);
		  Form4->Canvas->LineTo(x-length,y);
}
//---------------------------------------------------------------------------
//x,yÊÇÁâĞÎÖĞĞÄµÄ×ø±ê£¬long_length,short_length·Ö±ğÊÇÁ½¸öÁâĞÎ¶ÔÓ¦µÄ±ß³¤
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
// margin  ±ß¿ò¾àÀëÊı×ÖµÄ¾àÀë
void TForm4::DrawKiasEdge(int margin)
{
<<<<<<< HEAD
<<<<<<< HEAD
	  Form4->Canvas->Pen->Color=clLime;
	  Form4->Canvas->Pen->Width=1;
	  x=x-margin;
	  y=y-margin;
=======
	  //int
	  int x=StaticText5->Left-margin;
	  int y=StaticText5->Top-margin;
>>>>>>> parent of ef427df... æˆç†Ÿç‰ˆæœ¬
=======
	  //int
	  int x=StaticText5->Left-margin;
	  int y=StaticText5->Top-margin;
>>>>>>> parent of ef427df... æˆç†Ÿç‰ˆæœ¬

	  Form4->Canvas->MoveTo(x,y);
	  Form4->Canvas->LineTo(x+6*margin,y);
	  Form4->Canvas->LineTo(x+8*margin,y+3*margin);
	  Form4->Canvas->LineTo(x+6*margin,y+6*margin);
	  Form4->Canvas->LineTo(x,y+6*margin);
	  Form4->Canvas->LineTo(x,y);
}
//---------------------------------------------------------------------------
// margin  ±ß¿ò¾àÀëÊı×ÖµÄ¾àÀë
void TForm4::DrawAltitudeEdge(int margin)
{
	  //int
	  int x=StaticText6->Left+8*margin;
	  int y=StaticText6->Top-margin;

	  Form4->Canvas->MoveTo(x,y);
	  Form4->Canvas->LineTo(x-8*margin,y);
	  Form4->Canvas->LineTo(x-10*margin,y+3*margin);
	  Form4->Canvas->LineTo(x-8*margin,y+6*margin);
	  Form4->Canvas->LineTo(x,y+6*margin);
	  Form4->Canvas->LineTo(x,y);
}
void __fastcall TForm4::FormPaint(TObject *Sender)
{
<<<<<<< HEAD
<<<<<<< HEAD
		  DrawLabel(72,18,13,pre_machNumber,clLime);
		  DrawLabel(612,84,13,pre_gs,clLime);
		  DrawLabel(72,84,13,pre_gload,clLime);
		  DrawLabel(612,18,13,pre_agl,clLime);
		  DrawLabel(128,220,13,pre_kias_vertical,clLime);
		  DrawLabel(560,220,13,pre_altitude_ft,clLime);
		  DrawLabel(340,360,13,pre_gyro_number,clLime);
		  DrawAimingReticle(center_x,center_y,7,25,0.5);
		  DrawKiasVelocities(x_mark_zuojiantou,y_mark_zuojiantou,16,8,8,pre_kias,clLime);
		  DrawAltitudeMSL(x_mark_youjiantou,y_mark_youjiantou,16,8,8,pre_altitude,clLime);
		  DrawLadderPartA(70,pre_XOY_degree,pre_XOZ_degree,100,100,36,clLime);
// //²»»­ÄÇ¸öÁâĞÎÁË°É ÄÇ¸öÁâĞÎÃ»ÓĞÒâÒå  	  DrawLadderPartB(center_x-25,center_y+15,12,5);
//		  DrawGyrocompass(x_mark_v,y_mark_v,16,8,8,64);
//		  DrawLadderPartC(center_x,center_y+100,8);
		  DrawKiasEdge(128,220,6);
		  DrawAltitudeEdge(560,220,6);
//		  DrawGyroEdge(195,480,6);
=======
		  DrawAimingReticle(center_x,center_y,7,25,0.5);
		  DrawKiasVelocities(x_mark_zuojiantou,y_mark_zuojiantou,16,8,8,pre_kias,clLime);
		  DrawAltitudeMSL(x_mark_youjiantou,y_mark_youjiantou,16,8,8,pre_altitude,clLime);
=======
		  DrawAimingReticle(center_x,center_y,7,25,0.5);
		  DrawKiasVelocities(x_mark_zuojiantou,y_mark_zuojiantou,16,8,8,pre_kias,clLime);
		  DrawAltitudeMSL(x_mark_youjiantou,y_mark_youjiantou,16,8,8,pre_altitude,clLime);
<<<<<<< HEAD
>>>>>>> parent of ef427df... æˆç†Ÿç‰ˆæœ¬
		  DrawLadderPartA(80,pre_XOY_degree,pre_XOZ_degree,100,100,36,clLime);
=======
		  DrawLadderPartA(center_x-20,center_y+10,150);
>>>>>>> parent of d412669... æˆç†Ÿçš„ç‰ˆæœ¬
		  DrawLadderPartB(center_x-25,center_y+15,12,5);
		  DrawGyrocompass(x_mark_v,y_mark_v,16,8,8,64);
		  DrawLadderPartC(center_x,center_y+100,8);
		  DrawKiasEdge(6);
		  DrawAltitudeEdge(6);
//		  char str[] = "aaa\nbbb\nccc\nddd\neee\nfff";
//		   const char * split = "\n";
//	   char * p;
//	   p = strtok (str,split);
//	   p = strtok(NULL,split);
//		p = strtok(NULL,split);
//	   Label3->Caption=p;

}
//---------------------------------------------------------------------------
>>>>>>> parent of ef427df... æˆç†Ÿç‰ˆæœ¬



		  WSADATA wsaData;                                   //Ö¸ÏòWinSocketĞÅÏ¢½á¹¹µÄÖ¸Õë
	SOCKET sockListener;
	SOCKADDR_IN sin, saClient;                          //ÉèÖÃÁ½¸öµØÖ·£¬sinÓÃÀ´°ó¶¨
	//saClientÓÃÀ´´Ó¹ã²¥µØÖ·½ÓÊÕÏûÏ¢
   //	char cRecvBuff[800];                               //¶¨Òå½ÓÊÕ»º³åÇø
	int nSize, nbSize;
	int iAddrLen = sizeof(saClient);
	if (WSAStartup(MAKEWORD(1, 1), &wsaData) != 0)           //½øĞĞWinSocketµÄ³õÊ¼»¯
		ShowMessage("Can't initiates windows socket!Program stop.\n");//³õÊ¼»¯Ê§°Ü·µ»Ø-1
	sockListener = socket(AF_INET, SOCK_DGRAM, 0);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(5500);             //·¢ËÍ¶ËÊ¹ÓÃµÄ·¢ËÍ¶Ë¿Ú£¬¿ÉÒÔ¸ù¾İĞèÒª¸ü¸Ä
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sockListener, (SOCKADDR FAR *)&sin, sizeof(sin)) != 0)
		ShowMessage("Can't bind socket to local port!Program stop.\n");//³õÊ¼»¯Ê§°Ü·µ»Ø-1
	while (loop_flag)
	{
		char* cRecvBuff=new char[800];
		nSize = sizeof (SOCKADDR_IN);
		if ((nbSize = recvfrom(sockListener, cRecvBuff, 800, 0,
			(SOCKADDR FAR *) &saClient, &nSize)) == SOCKET_ERROR) //Èô½ÓÊÕÊ§°ÜÔòÌáÊ¾´íÎó
		{
			ShowMessage("Recive Error");
			break;
		}
		cRecvBuff[nbSize] = '\0';                              //×Ö·û´®ÖÕÖ¹

		//½âÎö×Ö·û´®
		const char * split = "\n";
		char * p=new char[1024];
		//½âÎömach number
		p = strtok(cRecvBuff,split);
		StaticText1->Caption=Trim(p);   //Trim È¥µôÎ²²¿µÄ¿Õ¸ñ

		//½âÎöGround speed
		 p = strtok(NULL,split);
		StaticText2->Caption=Trim(p)+"kts";

		//½âÎöG load
		 p = strtok(NULL,split);
		StaticText3->Caption=String(p).c_str();

		//½âÎöAGL
		p = strtok(NULL,split);
		StaticText4->Caption=Trim(p);

		//½âÎöKIAS-vertical
		p = strtok(NULL,split);
		StaticText5->Caption=Trim(p);
		//ÖØ»æKias
		DestroyKiasVelocities(x_mark_zuojiantou,y_mark_zuojiantou,16,8,8,pre_kias);
		DrawKiasVelocities(x_mark_zuojiantou,y_mark_zuojiantou,16,8,8,StrToInt(Trim(p)),clLime);
		pre_kias=StrToInt(Trim(p));

		//½âÎöAltitude-ft
		p = strtok(NULL,split);
		StaticText6->Caption=Trim(p);
		//ÖØ»æaltitude
		DestroyAltitudeMSL(x_mark_youjiantou,y_mark_youjiantou,16,8,8,pre_altitude);
		DrawAltitudeMSL(x_mark_youjiantou,y_mark_youjiantou,16,8,8,StrToInt(Trim(p)),clLime);
		pre_altitude=StrToInt(Trim(p));

		//½âÎöGyro Heading Label
		p = strtok(NULL,split);
		StaticText7->Caption=Trim(p);
		//ÖØ»ægyrocompass
		//ÏÈÇå³ıÖ®Ç°»­µÄÍ¼
		Canvas->Brush->Color=clBlack;     //ÓÃ¾ØĞÎÖØĞÂ°Ñ±³¾°Í¿³ÉºÚÉ«¼´¿É
		Canvas->Pen->Color=clBlack;
		Canvas->Rectangle(0,533,400,580);
		DrawGyrocompass(x_mark_v,y_mark_v,16,8,8,StrToInt(Trim(p)));

		delete cRecvBuff;
	}
}
//---------------------------------------------------------------------------

