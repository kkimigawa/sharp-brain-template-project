#include <windows.h>
#include <tchar.h>

static HFONT hFont;
static RECT windowRect;

void ProcWmSize(HWND hWnd)
{
    LOGFONT logFont;

    GetClientRect(hWnd, &windowRect);

    if (windowRect.right / 20 < windowRect.bottom / 4) {
        logFont.lfHeight = windowRect.right / 20;
    } else {
        logFont.lfHeight = windowRect.bottom / 4;
    }

    logFont.lfWidth = 0;
    logFont.lfEscapement = 0;
    logFont.lfOrientation = 0;
    logFont.lfWeight = FW_EXTRABOLD;
    logFont.lfItalic = FALSE;
    logFont.lfUnderline = FALSE;
    logFont.lfStrikeOut = FALSE;
    logFont.lfCharSet = SHIFTJIS_CHARSET;
    logFont.lfOutPrecision = OUT_DEFAULT_PRECIS;
    logFont.lfClipPrecision = CLIP_DEFAULT_PRECIS;
    logFont.lfQuality = DEFAULT_QUALITY;
    logFont.lfPitchAndFamily = VARIABLE_PITCH | FF_SWISS;

    _tcscpy(logFont.lfFaceName, TEXT("MS PGothic"));

    DeleteObject(hFont);
    hFont = CreateFontIndirect(&logFont);

    InvalidateRect(hWnd, NULL, TRUE);
}

void ProcWmPaint(HWND hWnd)
{
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);

    SetBkMode(hdc, TRANSPARENT);
    SetTextColor(hdc, RGB(0, 0, 0));
    SelectObject(hdc, hFont);
    DrawText(hdc, TEXT("Hello, world!!"), -1, &windowRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    EndPaint(hWnd, &ps);
}

void ProcWmKeyUp(HWND hWnd, WPARAM wParam)
{
    switch (wParam) {
        case VK_ESCAPE: // Sharp-Brain back key
            DestroyWindow(hWnd);
            break;
    }
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
        case WM_CLOSE:
            DestroyWindow(hWnd);
            break;

        case WM_SIZE:
            ProcWmSize(hWnd);
            break;

        case WM_PAINT:
            ProcWmPaint(hWnd);
            break;

        case WM_KEYUP:
            ProcWmKeyUp(hWnd, wParam);
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }

    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd)
{
    TCHAR* className = TEXT("Hello");

    WNDCLASS wcl;
    wcl.hInstance = hInstance;
    wcl.lpszClassName = className;
    wcl.lpfnWndProc = WindowProc;
    wcl.style = 0;
    wcl.hIcon = NULL;
    wcl.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcl.lpszMenuName = 0;
    wcl.cbClsExtra = 0;
    wcl.cbWndExtra = 0;
    wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);

    if (!RegisterClass(&wcl)) {
        return FALSE;
    }

    HWND hWnd = CreateWindowEx(
        0,
        className,
        TEXT("Title"),
        WS_OVERLAPPED | WS_MAXIMIZE,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        480,
        320,
        NULL,
        NULL,
        hInstance,
        NULL);

    if (!hWnd) {
        return FALSE;
    }

    ShowWindow(hWnd, nShowCmd);
    UpdateWindow(hWnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        DispatchMessage(&msg);
    }

    return msg.wParam;
}
