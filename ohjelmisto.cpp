#include <iostream>
#include <windows.h> 
#include <conio.h>

using namespace std;

// å = 0xDD
// ä = 0xDE
// ö = 0xC0
// ' = 0xBF
// ´ = 0xDB
// ¨ = 0xBA
// § = 0xDC

void kopioKomento (const char* text) {
    OpenClipboard(0);
    EmptyClipboard();
    HGLOBAL hClipboard = GlobalAlloc(GMEM_MOVEABLE, strlen(text)+1);
    memcpy(GlobalLock(hClipboard), text, strlen(text)+1); GlobalUnlock(hClipboard);
    SetClipboardData(CF_TEXT, hClipboard);
    CloseClipboard();}

void pasteClipboard() {
    keybd_event(VK_RCONTROL, 0, 0, 0);
    keybd_event('V', 0, 0, 0);
    keybd_event('V', 0, KEYEVENTF_KEYUP, 0); 
    keybd_event(VK_RCONTROL, 0, KEYEVENTF_KEYUP, 0); 
}

void pressKey(WORD key) {
    keybd_event(key, 0, 0, 0);
    keybd_event(key, 0, KEYEVENTF_KEYUP, 0);
}


int main(){
    while(1){

        while (GetAsyncKeyState(VK_LCONTROL)){
            if (GetAsyncKeyState(0xDC))
            {
                kopioKomento("\\bar{ }"); //esimerkki
                pasteClipboard(); 
                Sleep(500); 
            }
            if (GetAsyncKeyState(0xDB))
            {
                kopioKomento("\\begin{matrix}\\\\\\end{matrix}"); //esimerkki
                pasteClipboard();
                Sleep(550);
            }
            Sleep(200);
        }
        if (GetAsyncKeyState(VK_F2))
        {
            Sleep(5000);}Sleep(100);}return 0;}
