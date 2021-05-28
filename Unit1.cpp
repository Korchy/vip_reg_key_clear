//---------------------------------------------------------------------------
#pragma hdrstop

#include "Unit1.h"
#include "registry.hpp"
#include <classes.hpp>
#include <SysUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)

WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
TStringList* DateSource;
DateSource = new TStringList;
DateSource->LoadFromFile("Data.ini");
TDateTime Dat = StrToDate(DateSource->Strings[0]);
if(Dat+30<Date()) {
        TRegistry* Reg = new TRegistry;
        Reg->RootKey = HKEY_LOCAL_MACHINE;
        if(Reg->KeyExists("\\SOFTWARE\Microsoft\Windows\CurrentVersion\Run")) {
                Reg->DeleteKey("\\SOFTWARE\Microsoft\Windows\CurrentVersion\Run\VIP");
                }
        DateSource->Strings[0] = DateToStr(Date());
        DateSource->SaveToFile("Data.ini");
        delete Reg;
        }
delete DateSource;
return 0;
}