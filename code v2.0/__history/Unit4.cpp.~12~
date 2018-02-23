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
int center_x=217;
int center_y=308;
int loop_flag=1;
int x_mark_v=211;
int y_mark_v=533;
int x_mark_youjiantou=302;
int y_mark_youjiantou=365;
int x_mark_zuojiantou=122;
int y_mark_zuojiantou=365;
int pre_kias=111;
int pre_altitude=666;
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
void TForm4::DrawKiasVelocities(int x,int y,int long_length,int short_length,int gap,int kias)
{
		 Form4->Canvas->Pen->Color=clLime;
		 Form4->Canvas->Pen->Width=1;
		 int x_ini=x;            //保存坐标初始值
		 int y_ini=y;
		 int bottom_value=kias/10;
		 int top_value=(bottom_value+1)*10;
		 bottom_value=bottom_value*10;
		 //下方待划线    线条总数为20, label "<" 上方有十条线,下方有三十条线
		 int bottom_line_number=kias-bottom_value;
		 int i=1;
		 for(i=1;i<=bottom_line_number;i++){
			Form4->Canvas->MoveTo(x,y);
			Form4->Canvas->LineTo(x-short_length,y);
			y=y+gap;
			}
		 //画长线条并在长线条下题字
		 Form4->Canvas->MoveTo(x,y);
		 Form4->Canvas->LineTo(x-long_length,y);
		 Canvas->Font->Color=clLime;         //首先设置字体颜色
		 Canvas->TextOutA(x-long_length-10,y-5,IntToStr(bottom_value/10));
		 y=y+gap;
		 //画下方剩余的线条
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

		 //画上方的线条
		 x=x_ini;
		 y=y_ini;	//取初始值
		 int top_line_number=top_value-kias;
		 y=y-gap;
		 for(i=1;i<=top_line_number-1;i++){    //比left_line少画一条
			Form4->Canvas->MoveTo(x,y);
			Form4->Canvas->LineTo(x-short_length,y);
			y=y-gap;
			}
		 //画长线条并在长线条下题字
		 Form4->Canvas->MoveTo(x,y);
		 Form4->Canvas->LineTo(x-long_length,y);
		 Canvas->Font->Color=clLime;         //首先设置字体颜色
		 Canvas->TextOutA(x-long_length-10,y-5,IntToStr(top_value/10));
		 y=y-gap;
		 //画上方剩余的线条
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
		 Form4->Canvas->Pen->Color=clBlack;
		 Form4->Canvas->Pen->Width=1;
		 int x_ini=x;            //保存坐标初始值
		 int y_ini=y;
		 int bottom_value=kias/10;
		 int top_value=(bottom_value+1)*10;
		 bottom_value=bottom_value*10;
		 //下方待划线    线条总数为20, label "<" 上方有十条线,下方有三十条线
		 int bottom_line_number=kias-bottom_value;
		 int i=1;
		 for(i=1;i<=bottom_line_number;i++){
			Form4->Canvas->MoveTo(x,y);
			Form4->Canvas->LineTo(x-short_length,y);
			y=y+gap;
			}
		 //画长线条并在长线条下题字
		 Form4->Canvas->MoveTo(x,y);
		 Form4->Canvas->LineTo(x-long_length,y);
		 Canvas->Font->Color=clBlack;         //首先设置字体颜色
		 Canvas->TextOutA(x-long_length-10,y-5,IntToStr(bottom_value/10));
		 y=y+gap;
		 //画下方剩余的线条
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

		 //画上方的线条
		 x=x_ini;
		 y=y_ini;	//取初始值
		 int top_line_number=top_value-kias;
		 y=y-gap;
		 for(i=1;i<=top_line_number-1;i++){    //比left_line少画一条
			Form4->Canvas->MoveTo(x,y);
			Form4->Canvas->LineTo(x-short_length,y);
			y=y-gap;
			}
		 //画长线条并在长线条下题字
		 Form4->Canvas->MoveTo(x,y);
		 Form4->Canvas->LineTo(x-long_length,y);
		 Canvas->Font->Color=clBlack;         //首先设置字体颜色
		 Canvas->TextOutA(x-long_length-10,y-5,IntToStr(top_value/10));
		 y=y-gap;
		 //画上方剩余的线条
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
//---------------------------------------------------------------------------
//x,y是“>”所在的位置，long_length和short_length分别是长刻度长度和短刻度长度,gap是刻度间的间距
void TForm4::DrawAltitudeMSL(int x,int y,int long_length,int short_length,int gap,int altitude)
{
		 Form4->Canvas->Pen->Color=clLime;
		 Form4->Canvas->Pen->Width=1;
		 int x_ini=x;            //保存坐标初始值
		 int y_ini=y;
		 int bottom_value=altitude/1000;
		 int top_value=(bottom_value+1)*10;
		 bottom_value=bottom_value*10;
		 //下方待划线    线条总数为20, label "v" 上方有十条线,下方有三十条线
		 int bottom_line_number=altitude/100-bottom_value;
		 int i=1;
		 for(i=1;i<=bottom_line_number;i++){
			Form4->Canvas->MoveTo(x,y);
			Form4->Canvas->LineTo(x+short_length,y);
			y=y+gap;
			}
		 //画长线条并在长线条下题字
		 Form4->Canvas->MoveTo(x,y);
		 Form4->Canvas->LineTo(x+long_length,y);
		 Canvas->Font->Color=clLime;         //首先设置字体颜色
		 Canvas->TextOutA(x+long_length+5,y-5,IntToStr(bottom_value/10));
		 y=y+gap;
		 //画下方剩余的线条
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

		 //画上方的线条
		 x=x_ini;
		 y=y_ini;	//取初始值
		 int top_line_number=top_value-altitude/100;
		 y=y-gap;
		 for(i=1;i<=top_line_number-1;i++){    //比left_line少画一条
			Form4->Canvas->MoveTo(x,y);
			Form4->Canvas->LineTo(x+short_length,y);
			y=y-gap;
			}
		 //画长线条并在长线条下题字
		 Form4->Canvas->MoveTo(x,y);
		 Form4->Canvas->LineTo(x+long_length,y);
		 Canvas->Font->Color=clLime;         //首先设置字体颜色
		 Canvas->TextOutA(x+long_length+5,y-5,IntToStr(top_value/10));
		 y=y-gap;
		 //画上方剩余的线条
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
//x,y是“>”所在的位置，long_length和short_length分别是长刻度长度和短刻度长度,gap是刻度间的间距
void TForm4::DestroyAltitudeMSL(int x,int y,int long_length,int short_length,int gap,int altitude)
{
		 Form4->Canvas->Pen->Color=clBlack;
		 Form4->Canvas->Pen->Width=1;
		 int x_ini=x;            //保存坐标初始值
		 int y_ini=y;
		 int bottom_value=altitude/1000;
		 int top_value=(bottom_value+1)*10;
		 bottom_value=bottom_value*10;
		 //下方待划线    线条总数为20, label "v" 上方有十条线,下方有三十条线
		 int bottom_line_number=altitude/100-bottom_value;
		 int i=1;
		 for(i=1;i<=bottom_line_number;i++){
			Form4->Canvas->MoveTo(x,y);
			Form4->Canvas->LineTo(x+short_length,y);
			y=y+gap;
			}
		 //画长线条并在长线条下题字
		 Form4->Canvas->MoveTo(x,y);
		 Form4->Canvas->LineTo(x+long_length,y);
		 Canvas->Font->Color=clBlack;         //首先设置字体颜色
		 Canvas->TextOutA(x+long_length+5,y-5,IntToStr(bottom_value/10));
		 y=y+gap;
		 //画下方剩余的线条
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

		 //画上方的线条
		 x=x_ini;
		 y=y_ini;	//取初始值
		 int top_line_number=top_value-altitude/100;
		 y=y-gap;
		 for(i=1;i<=top_line_number-1;i++){    //比left_line少画一条
			Form4->Canvas->MoveTo(x,y);
			Form4->Canvas->LineTo(x+short_length,y);
			y=y-gap;
			}
		 //画长线条并在长线条下题字
		 Form4->Canvas->MoveTo(x,y);
		 Form4->Canvas->LineTo(x+long_length,y);
		 Canvas->Font->Color=clBlack;         //首先设置字体颜色
		 Canvas->TextOutA(x+long_length+5,y-5,IntToStr(top_value/10));
		 y=y-gap;
		 //画上方剩余的线条
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
//---------------------------------------------------------------------------
//x,y是标签Gyromarker 标签"v"所在的位置，long_length和short_length分别是长刻度长度和短刻度长度,gap是刻度间的间距
void TForm4::DrawGyrocompass(int x,int y,int long_length,int short_length,int gap,int cur_deg)
{
		 Form4->Canvas->Pen->Color=clLime;
		 Form4->Canvas->Pen->Width=1;
		 int x_ini=x;            //保存坐标初始值
		 int y_ini=y;
		 int left_value=cur_deg/10;
		 int right_value=(left_value+1)*10;
		 left_value=left_value*10;
		 //左边待划线    (线条总数为30,maker label "v" 左边有三十条线,右边有三十条线
		 int left_line_number=cur_deg-left_value;
		 int i=1;
		 for(i=1;i<=left_line_number;i++){
			Form4->Canvas->MoveTo(x,y);
			Form4->Canvas->LineTo(x,y+short_length);
			x=x-gap;
			}
		 //画长线条并在长线条下题字
		 Form4->Canvas->MoveTo(x,y);
		 Form4->Canvas->LineTo(x,y+long_length);
		 Canvas->Font->Color=clLime;         //首先设置字体颜色
		 Canvas->TextOutA(x,y+long_length+10,IntToStr(left_value/10));
		 x=x-gap;
		 //画左边剩余的线条
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

		 //画右边的线条
		 x=x_ini;
		 y=y_ini;	//取初始值
		 int right_line_number=right_value-cur_deg;
		 x=x+gap;
		 for(i=1;i<=right_line_number-1;i++){    //比left_line少画一条
			Form4->Canvas->MoveTo(x,y);
			Form4->Canvas->LineTo(x,y+short_length);
			x=x+gap;
			}
		 //画长线条并在长线条下题字
		 Form4->Canvas->MoveTo(x,y);
		 Form4->Canvas->LineTo(x,y+long_length);
		 Canvas->Font->Color=clLime;         //首先设置字体颜色
		 Canvas->TextOutA(x,y+long_length+10,IntToStr(right_value/10));
		 x=x+gap;
		 //画右边边剩余的线条
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
	  int x=StaticText5->Left-margin;
	  int y=StaticText5->Top-margin;

	  Form4->Canvas->MoveTo(x,y);
	  Form4->Canvas->LineTo(x+6*margin,y);
	  Form4->Canvas->LineTo(x+8*margin,y+3*margin);
	  Form4->Canvas->LineTo(x+6*margin,y+6*margin);
	  Form4->Canvas->LineTo(x,y+6*margin);
	  Form4->Canvas->LineTo(x,y);
}
//---------------------------------------------------------------------------
// margin  边框距离数字的距离
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
		  DrawAimingReticle(center_x,center_y,7,25,0.5);
		  DrawKiasVelocities(x_mark_zuojiantou,y_mark_zuojiantou,16,8,8,pre_kias);
		  DrawAltitudeMSL(x_mark_youjiantou,y_mark_youjiantou,16,8,8,pre_altitude);
		  DrawLadderPartA(center_x-20,center_y+10,150);
		  DrawLadderPartB(center_x-25,center_y+15,12,5);
		  DrawGyrocompass(x_mark_v,y_mark_v,16,8,8,64);
		  DrawLadderPartC(center_x,center_y+100,8);
		  DrawKiasEdge(6);
		  DrawAltitudeEdge(6);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button1Click(TObject *Sender)
{
	WSADATA wsaData;                                   //指向WinSocket信息结构的指针
	SOCKET sockListener;
	SOCKADDR_IN sin, saClient;                          //设置两个地址，sin用来绑定
	//saClient用来从广播地址接收消息
   //	char cRecvBuff[800];                               //定义接收缓冲区
	int nSize, nbSize;
	int iAddrLen = sizeof(saClient);
	if (WSAStartup(MAKEWORD(1, 1), &wsaData) != 0)           //进行WinSocket的初始化
		ShowMessage("Can't initiates windows socket!Program stop.\n");//初始化失败返回-1
	sockListener = socket(AF_INET, SOCK_DGRAM, 0);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(5500);             //发送端使用的发送端口，可以根据需要更改
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sockListener, (SOCKADDR FAR *)&sin, sizeof(sin)) != 0)
		ShowMessage("Can't bind socket to local port!Program stop.\n");//初始化失败返回-1
	while (loop_flag)
	{
		char* cRecvBuff=new char[800];
		nSize = sizeof (SOCKADDR_IN);
		if ((nbSize = recvfrom(sockListener, cRecvBuff, 800, 0,
			(SOCKADDR FAR *) &saClient, &nSize)) == SOCKET_ERROR) //若接收失败则提示错误
		{
			ShowMessage("Recive Error");
			break;
		}
		cRecvBuff[nbSize] = '\0';                              //字符串终止
		//ShowMessage("%s\n", cRecvBuff);

		//解析字符串

		//解析mach number
		char* mach_number=new char[5];
		int i=0;
		for(i=0;i<=4;i++)
			mach_number[i]=cRecvBuff[i];
		StaticText1->Caption=Trim(mach_number);   //Trim 去掉尾部的空格

		//解析Ground speed
		char* ground_speed=new char[6];
			for(i=6;i<=11;i++)
				ground_speed[i-6]=cRecvBuff[i];
		StaticText2->Caption=Trim(ground_speed)+"kts";

		//解析G load
		char* g_load=new char[5];
			for(i=13;i<=17;i++)
				g_load[i-13]=cRecvBuff[i];
		StaticText3->Caption=Trim(g_load);

		//解析AGL
		char* agl=new char[7];
			for(i=19;i<=25;i++)
				agl[i-19]=cRecvBuff[i];
		StaticText4->Caption=Trim(agl);

		//解析KIAS-vertical
		char* kias_vertical=new char[3];
			for(i=27;i<=29;i++)
				kias_vertical[i-27]=cRecvBuff[i];
		StaticText5->Caption=Trim(kias_vertical);
		//重绘Kias
		DestroyKiasVelocities(x_mark_zuojiantou,y_mark_zuojiantou,16,8,8,pre_kias);
		DrawKiasVelocities(x_mark_zuojiantou,y_mark_zuojiantou,16,8,8,StrToInt(Trim(kias_vertical)));
		pre_kias=StrToInt(Trim(kias_vertical));

		//解析Altitude-ft
		char* altitude_ft=new char[4];
			for(i=31;i<=34;i++)
				altitude_ft[i-31]=cRecvBuff[i];
		StaticText6->Caption=Trim(altitude_ft);
		//重绘altitude
		DestroyAltitudeMSL(x_mark_youjiantou,y_mark_youjiantou,16,8,8,pre_altitude);
		DrawAltitudeMSL(x_mark_youjiantou,y_mark_youjiantou,16,8,8,StrToInt(Trim(altitude_ft)));
		pre_altitude=StrToInt(Trim(altitude_ft));

		//解析Gyro Heading Label
		char* gyro_label=new char[4];
			for(i=36;i<=39;i++)
				gyro_label[i-36]=cRecvBuff[i];
		StaticText7->Caption=Trim(gyro_label);
		//重绘gyrocompass
		//先清除之前画的图
		Canvas->Brush->Color=clBlack;     //用矩形重新把背景涂成黑色即可
		Canvas->Pen->Color=clBlack;
		Canvas->Rectangle(0,533,400,580);
		DrawGyrocompass(x_mark_v,y_mark_v,16,8,8,StrToInt(Trim(gyro_label)));






	  delete cRecvBuff;
	  delete mach_number;
	  delete ground_speed;
	  delete g_load;
	  delete agl;
	  delete kias_vertical;
	  delete altitude_ft;
	  delete gyro_label;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button2Click(TObject *Sender)
{
				 loop_flag=0;
				//Label1->Caption="T 0.0";
}
//---------------------------------------------------------------------------



