//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
POINT ori_pt;
POINT cur_pt;
bool IsImage2MouseDown=False;
bool IsRectEdge=False;
bool change_height=False;
bool change_width=False;

//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
	image=new TImage(Form4);
	image->Parent = Form4;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Image2MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
						ShowCursorStyle(Sender);
						 GetCursorPos(&ori_pt);
						 IsImage2MouseDown=True;
						 //判断鼠标风格执行具体操作
						 if(Form4->Cursor==crSizeNWSE||Form4->Cursor==crSizeNESW){
							change_height=True;
							change_width=True;
							}
						 if(Form4->Cursor==crSizeNS){
							change_height=True;
							}
						 if(Form4->Cursor==crSizeWE){
							change_width=True;
							}

}
//---------------------------------------------------------------------------
void __fastcall TForm4::Image2MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	   //	ShowCursorStyle(Sender);
		GetCursorPos(&cur_pt);
		if(IsImage2MouseDown==True){
			if(change_height==False&&change_width==False){
				Image2->Top=Image2->Top+ cur_pt.y-ori_pt.y;
				Image2->Left=Image2->Left+cur_pt.x-ori_pt.x;
				}//end if(	Form4->Cursor==crSizeAll)
			else if(change_height==True&&change_width==False){
				Image2->Height=Image2->Height+ cur_pt.y-ori_pt.y;
				}//end if(Form4->Cursor==crSizeNS)
			else if(change_height==True&&change_width==True){
				 Image2->Height=Image2->Height+cur_pt.y-ori_pt.y;
				 Image2->Width=Image2->Width+cur_pt.x-ori_pt.x;
				 }
			else if(change_height==False&&change_width==True){
				  Image2->Width=Image2->Width+cur_pt.x-ori_pt.x;
				  }
		}
		//恢复鼠标风格
		Form4->Cursor=crArrow;
		change_height=False;
		change_width=False;
}
//---------------------------------------------------------------------------




void __fastcall TForm4::Image2MouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y)
{
	ShowCursorStyle(Sender);
}
//---------------------------------------------------------------------------
void TForm4::ShowCursorStyle(TObject *Sender)
{
	image=dynamic_cast<TImage *>(Sender);    //把调用消息强制转换为指定类
	int client_ori_x=Form4->GetClientOrigin().x;
	int client_ori_y=Form4->GetClientOrigin().y;

	GetCursorPos(&cur_pt);
	int x_left=image->Left+0.25*image->Width+client_ori_x;  //注意客户区坐标与屏幕坐标不同,将整个对象分成八块区域
	int x_right=image->Left+0.75*image->Width+client_ori_x;
	int y_top=image->Top+0.25*image->Height+client_ori_y;
	int y_bottom=image->Top+0.75*image->Height+client_ori_y;
	if(cur_pt.x>=x_left&&cur_pt.x<x_right&&
	   cur_pt.y>=y_top&&cur_pt.y<=y_bottom)
		Form4->Cursor=crSizeAll;
	else if(cur_pt.x>=image->Left+client_ori_x&&cur_pt.x<x_left&&
	   cur_pt.y>=image->Top+client_ori_y&&cur_pt.y<=y_top)
		Form4->Cursor=crSizeNWSE;
	else if(cur_pt.x>=x_left&&cur_pt.x<x_right&&
	   cur_pt.y>=image->Top+client_ori_y&&cur_pt.y<=y_top)
		Form4->Cursor=crSizeNS;
	else if(cur_pt.x>=x_right&&cur_pt.x<=image->Left+image->Width+client_ori_x&&
	   cur_pt.y>=image->Top+client_ori_y&&cur_pt.y<=y_top)
		Form4->Cursor=crSizeNESW;
	else if(cur_pt.x>=x_right&&cur_pt.x<=image->Left+image->Width+client_ori_x&&
	   cur_pt.y>=y_top&&cur_pt.y<=y_bottom)
		 Form4->Cursor=crSizeWE;
	else if(cur_pt.x>=x_right&&cur_pt.x<=image->Left+image->Width+client_ori_x&&
	   cur_pt.y>=y_bottom&&cur_pt.y<=image->Top+image->Height+client_ori_y)
		Form4->Cursor=crSizeNWSE;
	else if(cur_pt.x>=x_left&&cur_pt.x<=x_right&&
	   cur_pt.y>=y_bottom&&cur_pt.y<=image->Top+image->Height+client_ori_y)
		Form4->Cursor=crSizeNS;
	else if(cur_pt.x>=image->Left+client_ori_x&&cur_pt.x<=x_left&&
	   cur_pt.y>=y_bottom&&cur_pt.y<=image->Top+image->Height+client_ori_y)
		Form4->Cursor=crSizeNESW;
	else if(cur_pt.x>=image->Left+client_ori_x&&cur_pt.x<=x_left&&
	   cur_pt.y>=y_top&&cur_pt.y<=y_bottom)
		Form4->Cursor=crSizeWE;
}




