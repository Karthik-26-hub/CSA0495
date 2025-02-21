#include<windows.h>
#include<iostream>
int main()
{
    STARTUPINFO si={sizeof(si)};
    PROCESS_INFORMATION pi;
    if(!CreateProcess(NULL,(LPSTR)"C:\\Windows\\System32\\notepad.exe",
                      NULL,NULL,FALSE,0,NULL,NULL,&si,&pi)) {
        std::cout<<"Process creation failed.\n";
        return 1;
    }
    std::cout<<"Parent process.\n";
    std::cout<<"Child PID: "<<pi.dwProcessId<<std::endl;
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    return 0;
}
