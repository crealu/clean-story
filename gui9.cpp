// GUI with windows api (part 1)
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
//#pragma comment(lib, "comctl32.lib")

// define some constants
#define OPEN_FILE_BUTTON 1
#define SAVE_FILE_BUTTON 2

// specify the window procdure function
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

// function prototype
void AddControls(HWND);

// window handlers
HWND hMainWindow, hEdit;


// hInst is the instance of the application
int WINAPI WinMain(HINSTANCE hInst , HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
  // create window from registered window class
  WNDCLASSW wc = {0};

  wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
  wc.hCursor = LoadCursor(NULL, IDC_ARROW);
  wc.hInstance = hInst;
  wc.lpszClassName = L"myWindowClass";    // use L prefix
  wc.lpfnWndProc = WindowProcedure;   // pointer to WindowProcedure on line 5

  if(!RegisterClassW(&wc)) {
    return -1;
  }

  hMainWindow = CreateWindowW(L"myWindowClass", L"My Window", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                100, 100, 500, 500, NULL, NULL, NULL, NULL);

  MSG msg = {0};

  while (GetMessage(&msg, NULL, NULL, NULL)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  return 0;
}

void display_file(char* path) {
  FILE *file;
  file = fopen(path, "rb");     // "r" means read, "rb" means read binary as in the bits
  fseek(file, 0, SEEK_END);
  int _size = ftell(file);
  rewind(file);                     // go to start of file
  char* data = new char[_size+1];   // terminating character for string
  fread(data, _size, 1, file);      // read file data into data variable
  data[_size] ='\0';

  SetWindowText(hEdit, data);
  fclose(file);
}

void open_file(HWND hWnd) {
  OPENFILENAME ofn;

  char file_name[100];

  // set initial bite size to 0
  ZeroMemory(&ofn, sizeof(OPENFILENAME));

  // fil in elements
  ofn.lStructSize = sizeof(OPENFILENAME);
  ofn.hwndOwner = hWnd;             // file owner
  ofn.lpstrFile = file_name;        // path of the file
  ofn.lpstrFile[0] = '\0';          // set the first element of the string to a terminating character
  ofn.nMaxFile = 100;               // maximum buffer length

  // can be assigned to "All files\0*.*\0Source Files\0*.CPP\0Text Files\0*.TXT\0"
  // or any file extension specified

  ofn.lpstrFilter = "All files\0*.*\0";

  ofn.nFilterIndex = 1;   // if 1, all files selcted by default

  GetOpenFileName(&ofn);
  // to use this, you need to add a reference to libcomdlg32.a
  // filePath = C:\MinGW\mingw32\i686-w64-mingw32\lib
  // fileName = comdlg32
  // SO it looks like g++ gui8.cpp -LfilePath -lfileName
  // THEN when you compile use this g++ gui8.cpp -o gui8test.exe -lcomdlg32

  // to test, use
  //MessageBox(NULL, ofn.lpstrFile, "", MB_OK);

  display_file(ofn.lpstrFile);
}

void write_file(char* path) {
  FILE *file;
  file = fopen(path, "w");     // "w" means write, "rb" means read binary as in the bits

  int _size = GetWindowTextLength(hEdit);
  char* data = new char[_size + 1];
  GetWindowText(hEdit, data, _size + 1);

  fwrite(data, _size, 1, file);

  fclose(file);
}

void save_file(HWND hWnd) {
  OPENFILENAME ofn;

  char file_name[100];

  // set initial bite size to 0
  ZeroMemory(&ofn, sizeof(OPENFILENAME));

  // create save file dialog box
  ofn.lStructSize = sizeof(OPENFILENAME);
  ofn.hwndOwner = hWnd;             // file owner
  ofn.lpstrFile = file_name;        // path of the file
  ofn.lpstrFile[0] = '\0';          // set the first element of the string to a terminating character
  ofn.nMaxFile = 100;               // maximum buffer length
  ofn.lpstrFilter = "All files\0*.*\0";
  ofn.nFilterIndex = 1;   // if 1, all files selcted by default

  GetSaveFileName(&ofn);

  write_file(ofn.lpstrFile);
}

// g++ gui9.cpp -LC:/MinGW/mingw32/i686-w64-ming232/lib -lcomdlg32


LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
  // message loop
  switch (msg) {
    case WM_COMMAND:
      switch (wp) {
        case OPEN_FILE_BUTTON:
          open_file(hWnd);
          break;
        case SAVE_FILE_BUTTON:
          save_file(hWnd);
          break;
      }
    case WM_CREATE:
      AddControls(hWnd);
      break;
    case WM_DESTROY:
      PostQuitMessage(0);
      break;
    default:
      return DefWindowProcW(hWnd, msg, wp, lp);
  }
}


void AddControls(HWND hWnd) {
  CreateWindowW(L"Button", L"Open File", WS_VISIBLE | WS_CHILD, 10, 10, 150, 36,
                hWnd, (HMENU)OPEN_FILE_BUTTON, NULL, NULL);
  hEdit = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | ES_MULTILINE | WS_BORDER | WS_VSCROLL | WS_HSCROLL,
                10, 50, 400, 300, hWnd, NULL, NULL, NULL);

  CreateWindowW(L"Button", L"Save File", WS_VISIBLE | WS_CHILD, 170, 10, 150, 36,
                hWnd, (HMENU)SAVE_FILE_BUTTON, NULL, NULL);
}
