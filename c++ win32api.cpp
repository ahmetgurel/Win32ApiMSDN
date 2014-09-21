#include <windows.h>

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow){
	DWORD read;
	HANDLE hfile, hfile2;
	DWORD FileSize = 0;
	char deneme[20] = { 0 };
	char buff[4096] = { 0 };
	int sayac = 0;
	
	hfile = CreateFile(lpCmdLine, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	hfile2 = CreateFile(("output.intern.txt"), GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);

	FileSize = GetFileSize(hfile, NULL);
	_itoa_s(FileSize, deneme, 10);

	MessageBox(NULL, deneme,
		"Dosya Boyutu", NULL);

	
	ReadFile(hfile, buff, FileSize, &read, NULL);
	
	for each (char i in buff) {
		
		i = char((int)i + 1);
		buff[sayac] = i;
		sayac += 1;	
	}

	WriteFile(hfile2, buff,FileSize, &read, NULL); 
	CloseHandle(hfile);

	 return(0);

  }

