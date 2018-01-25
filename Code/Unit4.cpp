//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
POINT ori_pt;                     //鼠标按下时初始位置
POINT cur_pt;                     //鼠标弹起时当前位置
bool IsImageMouseDown=False;    //鼠标是否按下的标志
//_di_IXMLNode node;				//节点变量用来读写xml文件


//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
	image=new TImage(Form4);      //初始化成员对象 image,动态创建image 控件
	image->Parent = Form4;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Image2MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{                        //面板信息显示
						 image=dynamic_cast<TImage *>(Sender);
						 Edit1->Text=m_pIniFile->ReadString(image->Name,"name","");
						 Edit6->Text=m_pIniFile->ReadString(image->Name,"scale","");
						 Edit2->Text=m_pIniFile->ReadString(image->Name,"size-Height","");
						 Edit3->Text=m_pIniFile->ReadString(image->Name,"size-Width","");
						 Edit4->Text=m_pIniFile->ReadString(image->Name,"Loacation-X","");
						 Edit5->Text=m_pIniFile->ReadString(image->Name,"Loacation-Y","");
						 GetCursorPos(&ori_pt);
						 IsImageMouseDown=True;
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Image2MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
		image=dynamic_cast<TImage *>(Sender);
		GetCursorPos(&cur_pt);
		int adjust_x=216;        //调整量取adjust_x,adjust_y为相对坐标系原点(即aiming reticle中心)
		int adjust_y=288;        //这样Loacation-X,Loacation-Y 都是相对坐标系的值
		if(IsImageMouseDown==True){
				image->Top=image->Top+ cur_pt.y-ori_pt.y;
				image->Left=image->Left+cur_pt.x-ori_pt.x;
				if(strcmp(WChar2MultiByte(image->Name.c_str()),"Image4")){   //Aiming-Recticle的位置是固定的，不对其做任何改变 ,unicode String 转const char*方法要记录
					m_pIniFile->WriteString(image->Name,"Loacation-X",image->Left-adjust_x);
					m_pIniFile->WriteString(image->Name,"Loacation-Y",image->Top-adjust_y);
					Edit4->Text=m_pIniFile->ReadString(image->Name,"Loacation-X","");
					Edit5->Text=m_pIniFile->ReadString(image->Name,"Loacation-Y","");
					}//end if strcmp
		}// end if (IsImageMouseDown==True)
		IsImageMouseDown=false;
}
//---------------------------------------------------------------------------




void __fastcall TForm4::Image2MouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y)
{
	Form4->Cursor=crSizeAll;
}
//---------------------------------------------------------------------------




void __fastcall TForm4::FormCreate(TObject *Sender)
{
	 //配置文件
	m_pIniFile = new TIniFile(ExtractFilePath(Application->ExeName)+"Config.ini");
	AnsiString namestring="TImage";
	//相对于image把心的坐标
	int adjust_x=216;
	int adjust_y=288;
	//初始化元素位置和大小
    	for(int i=0;i<Form4->ControlCount;i++){
		if (Form4->Controls[i]->ClassNameIs(namestring)){
				TImage *p=dynamic_cast<TImage*>(Form4->Controls[i]);
			p->Height=StrToInt(m_pIniFile->ReadString(p->Name,"size-Height",p->Height));
			p->Width=StrToInt(m_pIniFile->ReadString(p->Name,"size-Width",p->Width));
			p->Left=StrToInt(m_pIniFile->ReadString(p->Name,"Loacation-X",""))+adjust_x;
			p->Top=StrToInt(m_pIniFile->ReadString(p->Name,"Loacation-Y",""))+adjust_y;
			} // end if
		} //end for
}
//---------------------------------------------------------------------------

char* TForm4::WChar2MultiByte(wchar_t *szStr)
{
	//wchar转多字节
	char *pResult;

	int size = WideCharToMultiByte(CP_UTF8, 0, szStr, -1, NULL, 0, NULL, NULL);
	pResult = (char*)malloc((size+1)/**sizeof(char)*/);
	WideCharToMultiByte(CP_UTF8, 0, szStr, -1, pResult, size, NULL, NULL);
	return pResult;
}

void __fastcall TForm4::UpDown1Click(TObject *Sender, TUDBtnType Button)
{
			//改变元素Scale大小
           	AnsiString namestring="TImage";
			for(int i=0;i<Form4->ControlCount;i++){
				if(Form4->Controls[i]->ClassNameIs(namestring)){
					TImage *p=dynamic_cast<TImage*>(Form4->Controls[i]);
						if(!strcmp(WChar2MultiByte(m_pIniFile->ReadString(p->Name,"name","").c_str()),WChar2MultiByte(Edit1->Text.c_str()))){
							m_pIniFile->WriteString(p->Name,"scale",Edit6->Text);
							Edit6->Text=m_pIniFile->ReadString(p->Name,"scale","");
						 //scale反映到图片本身来
						 //配置文件ori_Height,ori_Width保留了最初原始布局下的元素属性值，scale变化都在此基础上变化
						 p->Height=m_pIniFile->ReadString(p->Name,"ori_Height","").ToInt()+StrToInt(Edit6->Text)-100;
						 p->Width=m_pIniFile->ReadString(p->Name,"ori_Width","").ToInt()+StrToInt((Edit6->Text)-100)*(p->Width/p->Height);
						 m_pIniFile->WriteString(p->Name,"size-Height", p->Height);
						 Edit2->Text=m_pIniFile->ReadString(p->Name,"size-Height","");
						 m_pIniFile->WriteString(p->Name,"size-Width", p->Width);
						 Edit3->Text=m_pIniFile->ReadString(p->Name,"size-Width","");
						} //end if(strcmp
					} //end  if(Form4->Controls[i]
				} //end for           对本身的值进行操作就好了



}
//---------------------------------------------------------------------------

void __fastcall TForm4::Image1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
		 Form4->Cursor=crArrow;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button1Click(TObject *Sender)
{
	 if(OpenDialog1->Execute()){
			//String name=ExtractFileName(OpenDialog1->FileName);
			Edit7->Text=OpenDialog1->FileName;
			XMLDocument1->LoadFromFile(OpenDialog1->FileName);
			_di_IXMLNode node = XMLDocument1->DocumentElement;
			if (node == NULL){
				ShowMessage("不是合法的程序配置文件XML文件格式。");
				return;
				}
			else
				 UpdateNodeData(node,"label");
		}
}
//---------------------------------------------------------------------------
void TForm4::UpdateNodeData(_di_IXMLNode panode,AnsiString nodename)
{

	_di_IXMLNodeList nodes = panode->ChildNodes;
	_di_IXMLNode node = nodes->FindNode(nodename);
	if (node == NULL)
		ShowMessage("未找到"+nodename+"结点");
	else//{
		//node->SetAttribute("FriendlyName", friendlyname);
		ShowMessage("已找到"+nodename+"结点");
}




//加载XML文件










