//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton3Click(TObject *Sender)
{
if (OpenDialog1->Execute()) Memo1->Lines->LoadFromFile(OpenDialog1->FileName); 
StatusBar1->Panels->Items[0]->Text=OpenDialog1->FileName;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton5Click(TObject *Sender)
{
if (SaveDialog1->Execute()) Memo1->Lines->SaveToFile(SaveDialog1->FileName); 
StatusBar1->Panels->Items[0]->Text=SaveDialog1->FileName;        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
if (Memo1->Lines->Count>0) 
{ 
if (MessageBox(0,"Сохранить содержимое окна редактирования? ", 
"Подтвердите сохранение",MB_YESNO)==IDYES) 
{ 
SpeedButton5Click(Sender); 
} 
}; 
Memo1->Clear(); 
StatusBar1->Panels->Items[0]->Text="Без имени";        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
SpeedButton2Click(Sender); 
Close();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton4Click(TObject *Sender)
{
if (StatusBar1->Panels->Items[0]->Text=="Без имени") 
SpeedButton5Click(Sender); 
else Memo1->Lines->SaveToFile(StatusBar1->Panels->Items[0]->Text);        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton6Click(TObject *Sender)
{
Memo1->CutToClipboard();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton7Click(TObject *Sender)
{
Memo1->CopyToClipboard();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton8Click(TObject *Sender)
{
Memo1->PasteFromClipboard();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton9Click(TObject *Sender)
{
Application->CreateForm(__classid(TAboutBox), &AboutBox); 
AboutBox->ShowModal(); 
AboutBox->Free();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N9Click(TObject *Sender)
{
N9->Checked=!N9->Checked; 
Panel1->Visible=N9->Checked;        
}
//---------------------------------------------------------------------------
