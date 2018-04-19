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
#define pi 3.1415926
TForm4 *Form4;
int center_x=217;           //坐标原点
int center_y=308;           //坐标原点
int loop_flag=1;            //是否继续循环接受数据的标志
int x_mark_v=211;           //"V"标记的横纵坐标
int y_mark_v=533;
int x_mark_youjiantou=322;   //">"标记的横纵坐标
int y_mark_youjiantou=365;
int x_mark_zuojiantou=100;    //"<"标记的横纵坐标
int y_mark_zuojiantou=365;
int pre_kias=000;              //前一个kias,altitude
int pre_altitude=000;
int pre_XOY_degree=0;
int pre_XOZ_degree=0;
String pre_machNumber="M 0.0";
String pre_agl="AGL 6";
String pre_gload="G 1.0";
String pre_gs="GS: 0kts";
String pre_kias_vertical="000";
String pre_altitude_ft="0000";
String pre_gyro_number="000";
int origin_x=0;
int origin_y=0;
int size=13;
int m_x=72;
int m_y=48;
int m_flag=0;
int gs_x=312;
int gs_y=114;
int gs_flag=0;
int gload_x=72;
int gload_y=114;
int gload_flag=0;
int agl_x=312;
int agl_y=48;
int agl_flag=0;
int kias_left_x=20;
int kias_right_x=104;
int kias_top_y=280;  //gap=8 ，线条数共20
int kias_bottom_y=440;
int kias_flag=0;



//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
//
void TForm4::DrawLabel(int x,int y,int size,String labelName,long color)
{
		Canvas->Font->Color=color;         //首先设置字体颜色
		Canvas->Font->Size=size;
		Canvas->TextOutA(x,y,labelName);
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
void TForm4::DrawKiasVelocities(int x,int y,int long_length,int short_length,int gap,int kias,long color)
{
		 DrawLabel(x+4,y-10,size,"<",clLime);
		 Form4->Canvas->Pen->Color=color;
		 Form4->Canvas->Pen->Width=1;
		 int x_ini=x;            //保存坐标初始值
		 int y_ini=y;
		 int bottom_value=kias/10;
		 int top_value=(bottom_value+1)*10;
		 bottom_value=bottom_value*10;
		 //下方待划线    线条总数为20, label "<" 上方有十条线,下方有十条线
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
		 Canvas->Font->Color=color;         //首先设置字体颜色
		 Canvas->TextOutA(x-long_length-20,y-5,IntToStr(bottom_value/10));
		 y=y+gap;
		 //画下方剩余的线条
		 int remain_line_number=10-bottom_line_number-1;
		 for(i=1;i<=remain_line_number;i++){
			if(i==10){
				Form4->Canvas->MoveTo(x,y);
				Form4->Canvas->LineTo(x-long_length,y);
				Canvas->TextOutA(x-long_length-20,y-5,IntToStr((bottom_value-1)/10));
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
		 Canvas->TextOutA(x-long_length-20,y-5,IntToStr(top_value/10));
		 y=y-gap;
		 //画上方剩余的线条
		 remain_line_number=10-top_line_number-1;
		 for(i=1;i<=remain_line_number;i++){
			if(i==10){
				Form4->Canvas->MoveTo(x,y);
				Form4->Canvas->LineTo(x+long_length,y);
				Canvas->TextOutA(x-long_length-20,y-5,IntToStr((top_value-1)/10));
				y=y-gap;
				}
			Form4->Canvas->MoveTo(x,y);
			Form4->Canvas->LineTo(x-short_length,y);
			y=y-gap;
		 }

}
//---------------------------------------------------------------------------
//x,y是“>”所在的位置，long_length和short_length分别是长刻度长度和短刻度长度,gap是刻度间的间距
void TForm4::DrawAltitudeMSL(int x,int y,int long_length,int short_length,int gap,int altitude,long color)
{
		 DrawLabel(x-10,y-11,13,">",clLime);
		 Form4->Canvas->Pen->Color=color;
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
		 Canvas->Font->Color=color;         //首先设置字体颜色
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
		 DrawLabel(x-6,y-20,13,"V",clLime);
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
void TForm4::DrawLadderPartA(int length,int XOY_degree,int XOZ_degree,int height,int bottom,int jianju,long color)
{
	   Form4->Canvas->Pen->Color=color;
	   Form4->Canvas->Pen->Width=1;
	   if(XOZ_degree<0)
			XOZ_degree=-XOZ_degree;	//将flightgear实际输出值 与函数里的输入值对应
	   else
			XOZ_degree=360-XOZ_degree;     //输入的degree均为角度，在后面的代码中要变成弧度使用
	   int degree[2]={0};
	   for(int i=0;i<=1;i++){
			degree[i]=(XOY_degree/10+i+1)*10;
			int gap=(degree[i]-XOY_degree)*5;
			if(gap<=height){
				//过靶心直线上将要描点的位置(center_x+gap*cos(XOZ_degree),center_y-gap*sin(XOZ_degree)
				int ini_point_x=center_x+gap*sin(XOZ_degree*pi/180);
				int ini_point_y=center_y-gap*cos(XOZ_degree*pi/180);
				//画左边的线条
				Form4->Canvas->MoveTo(ini_point_x-jianju*cos(XOZ_degree*pi/180),ini_point_y-jianju*sin(XOZ_degree*pi/180));
				Form4->Canvas->LineTo(ini_point_x-length*cos(XOZ_degree*pi/180),ini_point_y-length*sin(XOZ_degree*pi/180));

				//输出文字
				Canvas->Font->Color=color;
				LOGFONT lf;
				GetObject(Canvas->Font->Handle,sizeof (LOGFONT),&lf);
				lf.lfEscapement =(360-XOZ_degree)*10;   //set to 450 to make 45 degree angle
				lf.lfOrientation =(360-XOZ_degree)*10;
				lf.lfOutPrecision = OUT_TT_ONLY_PRECIS;
				Canvas->Font->Handle = CreateFontIndirect (&lf);
				Canvas->TextOutA(ini_point_x-(length+12)*cos(XOZ_degree*pi/180),ini_point_y-(length+12)*sin(XOZ_degree*pi/180),IntToStr(degree[i]));

				//画右边的线条
				Form4->Canvas->MoveTo(ini_point_x+jianju*cos(XOZ_degree*pi/180),ini_point_y+jianju*sin(XOZ_degree*pi/180));
				Form4->Canvas->LineTo(ini_point_x+length*cos(XOZ_degree*pi/180),ini_point_y+length*sin(XOZ_degree*pi/180));
				//输出文字
				Canvas->TextOutA(ini_point_x+length*cos(XOZ_degree*pi/180),ini_point_y+length*sin(XOZ_degree*pi/180),IntToStr(degree[i]));

				//恢复正常字体
				lf.lfEscapement =0;   //set to 450 to make 45 degree angle
				lf.lfOrientation =0;
				lf.lfOutPrecision = OUT_TT_ONLY_PRECIS;
				Canvas->Font->Handle = CreateFontIndirect (&lf);
			}
	   }
	   degree[0]=0;
	   degree[1]=0;
	   for(int i=0;i<=1;i++){
			degree[i]=(XOY_degree/10-i)*10;
			int gap=(XOY_degree-degree[i])*5;
			if(gap<=bottom){
				//过靶心直线上将要描点的位置(center_x+gap*cos(XOZ_degree),center_y-gap*sin(XOZ_degree)
				int ini_point_x=center_x-gap*sin(XOZ_degree*pi/180);
				int ini_point_y=center_y+gap*cos(XOZ_degree*pi/180);
				//画左边的线条
				Form4->Canvas->MoveTo(ini_point_x-jianju*cos(XOZ_degree*pi/180),ini_point_y-jianju*sin(XOZ_degree*pi/180));
				Form4->Canvas->LineTo(ini_point_x-length*cos(XOZ_degree*pi/180),ini_point_y-length*sin(XOZ_degree*pi/180));

				//输出文字
				Canvas->Font->Color=color;
				LOGFONT lf;
				GetObject(Canvas->Font->Handle,sizeof (LOGFONT),&lf);
				lf.lfEscapement =(360-XOZ_degree)*10;   //set to 450 to make 45 degree angle
				lf.lfOrientation =(360-XOZ_degree)*10;
				lf.lfOutPrecision = OUT_TT_ONLY_PRECIS;
				Canvas->Font->Handle = CreateFontIndirect (&lf);
				Canvas->TextOutA(ini_point_x-(length+12)*cos(XOZ_degree*pi/180),ini_point_y-(length+12)*sin(XOZ_degree*pi/180),IntToStr(degree[i]));

				//画右边的线条
				Form4->Canvas->MoveTo(ini_point_x+jianju*cos(XOZ_degree*pi/180),ini_point_y+jianju*sin(XOZ_degree*pi/180));
				Form4->Canvas->LineTo(ini_point_x+length*cos(XOZ_degree*pi/180),ini_point_y+length*sin(XOZ_degree*pi/180));
				//输出文字
				Canvas->TextOutA(ini_point_x+length*cos(XOZ_degree*pi/180),ini_point_y+length*sin(XOZ_degree*pi/180),IntToStr(degree[i]));

				//恢复正常字体
				lf.lfEscapement =0;   //set to 450 to make 45 degree angle
				lf.lfOrientation =0;
				lf.lfOutPrecision = OUT_TT_ONLY_PRECIS;
				Canvas->Font->Handle = CreateFontIndirect (&lf);
			}
	   }
}
//---------------------------------------------------------------------------
void TForm4::DrawKiasEdge(int x,int y,int margin)
{
	  x=x-margin;
	  y=y-margin;

	  Form4->Canvas->MoveTo(x,y);
	  Form4->Canvas->LineTo(x+6*margin,y);
	  Form4->Canvas->LineTo(x+8*margin,y+3*margin);
	  Form4->Canvas->LineTo(x+6*margin,y+6*margin);
	  Form4->Canvas->LineTo(x,y+6*margin);
	  Form4->Canvas->LineTo(x,y);
}
//---------------------------------------------------------------------------
// margin  边框距离数字的距离   怎样使左右两个边框对称成为了一个问题
void TForm4::DrawAltitudeEdge(int x,int y,int margin)
{
	  y=y-margin;
	  Form4->Canvas->MoveTo(x,y);
	  Form4->Canvas->LineTo(x-2*margin,y+3*margin);
	  Form4->Canvas->LineTo(x,y+6*margin);
	  Form4->Canvas->LineTo(x+8*margin,y+6*margin);
	  Form4->Canvas->LineTo(x+8*margin,y);
	  Form4->Canvas->LineTo(x,y);
}
//---------------------------------------------------------------------------
// margin  边框距离数字的距离   怎样使左右两个边框对称成为了一个问题
void TForm4::DrawGyroEdge(int x,int y,int margin)
{
	  y=y-margin;
	  x=x-margin;
	  Form4->Canvas->MoveTo(x,y);
	  Form4->Canvas->LineTo(x+6*margin,y);
	  Form4->Canvas->LineTo(x+6*margin,y+6*margin);
	  Form4->Canvas->LineTo(x,y+6*margin);
	  Form4->Canvas->LineTo(x,y);
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormPaint(TObject *Sender)
{
		  DrawLabel(m_x,m_y,size,pre_machNumber,clLime);
		  DrawLabel(gs_x,gs_y,size,pre_gs,clLime);
		  DrawLabel(gload_x,gload_y,size,pre_gload,clLime);
		  DrawLabel(agl_x,agl_y,size,pre_agl,clLime);
		  DrawLabel(kias_left_x,(kias_top_y+kias_bottom_y)/2,size,pre_kias_vertical,clLime);
		  DrawLabel(376,360,13,pre_altitude_ft,clLime);
		  DrawLabel(195,480,13,pre_gyro_number,clLime);
		  DrawAimingReticle(center_x,center_y,7,25,0.5);
		  DrawKiasVelocities(x_mark_zuojiantou,y_mark_zuojiantou,16,8,8,pre_kias,clLime);
		  DrawAltitudeMSL(x_mark_youjiantou,y_mark_youjiantou,16,8,8,pre_altitude,clLime);
		  DrawLadderPartA(70,pre_XOY_degree,pre_XOZ_degree,100,100,36,clLime);
		  DrawGyrocompass(x_mark_v,y_mark_v,16,8,8,64);
		//  DrawLadderPartC(center_x,center_y+100,8);
		  DrawKiasEdge(kias_left_x,(kias_top_y+kias_bottom_y)/2,6);
		  DrawAltitudeEdge(376,360,6);
		  DrawGyroEdge(195,480,6);
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

		//解析字符串
		const char * split = "\n";
		char * p=new char[1024];
		//解析mach number
		p = strtok(cRecvBuff,split);
		DrawLabel(72,48,13,pre_machNumber,clBackground);
		DrawLabel(72,48,13,Trim(p),clLime);
		pre_machNumber=Trim(p);

		//解析Ground speed
		 p = strtok(NULL,split);
		 DrawLabel(312,114,13,pre_gs,clBackground);
		 DrawLabel(312,114,13,Trim(p)+"kts",clLime);
		 pre_gs=Trim(p)+"kts";

		//解析G load
		 p = strtok(NULL,split);
		 DrawLabel(72,114,13,pre_gload,clBackground);
		 //G load  显示有误，字符最后一位显示乱码
		 char* gload=new char[strlen(p)];
		 strcpy(gload,p);
		 if(int(gload[strlen(p)])>9||int(gload[strlen(p)])<0)
				 gload[strlen(p)]=' ';
		 DrawLabel(72,114,13,gload,clLime);
		 pre_gload=gload;

		//解析AGL
		p = strtok(NULL,split);
		DrawLabel(312,48,13,pre_agl,clBackground);
		DrawLabel(312,48,13,Trim(p),clLime);
		pre_agl=Trim(p);

		//解析KIAS-vertical
		p = strtok(NULL,split);
		DrawLabel(20,355,13,pre_kias_vertical,clBackground);
		DrawLabel(20,355,13,Trim(p),clLime);
		pre_kias_vertical=Trim(p);

		//重绘Kias
		DrawKiasVelocities(x_mark_zuojiantou,y_mark_zuojiantou,16,8,8,pre_kias,clBackground);
		DrawKiasVelocities(x_mark_zuojiantou,y_mark_zuojiantou,16,8,8,StrToInt(Trim(p)),clLime);
		pre_kias=StrToInt(Trim(p));


		//解析Altitude-ft
		p = strtok(NULL,split);
		DrawLabel(376,360,13,pre_altitude_ft,clBackground);
		DrawLabel(376,360,13,Trim(p),clLime);
		DrawAltitudeEdge(376,360,6);
		//重绘altitude
		DrawAltitudeMSL(x_mark_youjiantou,y_mark_youjiantou,16,8,8,pre_altitude,clBackground);
		DrawAltitudeMSL(x_mark_youjiantou,y_mark_youjiantou,16,8,8,StrToInt(Trim(p)),clLime);
		pre_altitude_ft=Trim(p);
		pre_altitude=StrToInt(Trim(p));

		//解析Gyro Heading Label
		p = strtok(NULL,split);
		DrawLabel(195,480,13,pre_gyro_number,clBackground);
		DrawLabel(195,480,13,Trim(p),clLime);
		DrawGyroEdge(195,480,6);
		//重绘gyrocompass
		//先清除之前画的图
		Canvas->Brush->Color=clBlack;     //用矩形重新把背景涂成黑色即可
		Canvas->Pen->Color=clBlack;
		Canvas->Rectangle(0,533,400,580);
		DrawGyrocompass(x_mark_v,y_mark_v,16,8,8,StrToInt(Trim(p)));

		//解析pitch ladder roll degree
		p = strtok(NULL,split);
		int roll_degree=StrToInt(Trim(p));
		//解析pitch ladder pitch degree
		p = strtok(NULL,split);
		int pitch_degree=StrToInt(Trim(p));
		//重绘pitchladder
		DrawLadderPartA(70,pre_XOY_degree,pre_XOZ_degree,100,100,36,clBackground);
		DrawLadderPartA(70,pitch_degree,roll_degree,100,100,36,clLime);
		pre_XOY_degree=pitch_degree;
		pre_XOZ_degree=roll_degree;

		delete gload;
		delete cRecvBuff;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button2Click(TObject *Sender)
{
				 loop_flag=0;
				//Label1->Caption="T 0.0";
}
//---------------------------------------------------------------------------



void __fastcall TForm4::FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
			  origin_x=X;
			  origin_y=Y;
			  if(X>=m_x&&X<=m_x+size*4&&Y>=m_y&&Y<=m_y+size) m_flag=1;
			  if(X>=gs_x&&X<=gs_x+size*8&&Y>=gs_y&&Y<=gs_y+size) gs_flag=1;
			  if(X>=gload_x&&X<=gload_x+size*6&&Y>=gload_y&&Y<=gload_y+size) gload_flag=1;
			  if(X>=agl_x&&X<=agl_x+size*8&&Y>=agl_y&&Y<=agl_y+size) agl_flag=1;
			  if(X>=kias_left_x&&X<=kias_right_x&&Y>=kias_top_y&&Y<=kias_bottom_y) kias_flag=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::FormMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	if(m_flag==1) {
		m_x=m_x+X-origin_x;
		m_y=m_y+Y-origin_y;
		Canvas->Pen->Color=clBlack;
		Canvas->Rectangle(0,0,430,610);
		FormPaint(Sender);
		m_flag=0;
		}
	if(gs_flag==1) {
		gs_x=gs_x+X-origin_x;
		gs_y=gs_y+Y-origin_y;
		Canvas->Pen->Color=clBlack;
		Canvas->Rectangle(0,0,430,610);
		FormPaint(Sender);
		gs_flag=0;
		}
	if(gload_flag==1) {
		gload_x=gload_x+X-origin_x;
		gload_y=gload_y+Y-origin_y;
		Canvas->Pen->Color=clBlack;
		Canvas->Rectangle(0,0,430,610);
		FormPaint(Sender);
		gload_flag=0;
		}
	if(agl_flag==1) {
		agl_x=agl_x+X-origin_x;
		agl_y=agl_y+Y-origin_y;
		Canvas->Pen->Color=clBlack;
		Canvas->Rectangle(0,0,430,610);
		FormPaint(Sender);
		agl_flag=0;
		}
	if(kias_flag==1) {
		kias_left_x=kias_left_x+X-origin_x;
		kias_top_y=kias_top_y+Y-origin_y;
		kias_right_x=kias_right_x+X-origin_x;
		kias_bottom_y=kias_bottom_y+Y-origin_y;
		x_mark_zuojiantou=x_mark_zuojiantou+X-origin_x;
		y_mark_zuojiantou=y_mark_zuojiantou+Y-origin_y;
		Canvas->Pen->Color=clBlack;
		Canvas->Rectangle(0,0,430,610);
		FormPaint(Sender);
		kias_flag=0;
		}
}
//---------------------------------------------------------------------------

