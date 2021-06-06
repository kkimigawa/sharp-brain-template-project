#include <windows.h>
#include <tchar.h>

#define WND_CLASS_NAME TEXT("OUCC_Advent_Main")

static HFONT hFont;
static RECT rect;

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    HDC hdc;
    LOGFONT rLogfont;
    PAINTSTRUCT ps;

    switch (uMsg) {
        case WM_CLOSE:
            DestroyWindow(hWnd);
            break;

        case WM_SIZE: // ウィンドウサイズ変更時
            GetClientRect(hWnd, &rect);

            if (rect.right / 20 < rect.bottom / 4) {
                rLogfont.lfHeight = rect.right / 20;
            } else {
                rLogfont.lfHeight = rect.bottom / 4;
            }
            rLogfont.lfWidth = 0;
            rLogfont.lfEscapement = 0;
            rLogfont.lfOrientation = 0;
            rLogfont.lfWeight = FW_EXTRABOLD;
            rLogfont.lfItalic = FALSE;
            rLogfont.lfUnderline = FALSE;
            rLogfont.lfStrikeOut = FALSE;
            rLogfont.lfCharSet = SHIFTJIS_CHARSET;
            rLogfont.lfOutPrecision = OUT_DEFAULT_PRECIS;
            rLogfont.lfClipPrecision = CLIP_DEFAULT_PRECIS;
            rLogfont.lfQuality = DEFAULT_QUALITY;
            rLogfont.lfPitchAndFamily = VARIABLE_PITCH | FF_SWISS;
            _tcscpy(rLogfont.lfFaceName, TEXT("MS PGothic"));
            DeleteObject(hFont);
            hFont = CreateFontIndirect(&rLogfont);

            InvalidateRect(hWnd, NULL, TRUE);
            break;

        case WM_PAINT:
            hdc = BeginPaint(hWnd, &ps);

            SetBkMode(hdc, TRANSPARENT);
            SetTextColor(hdc, RGB(0, 0, 0));
            SelectObject(hdc, hFont);
            DrawText(hdc, TEXT("Hello, OUCC Advent Calendar 2020!"), -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

            EndPaint(hWnd, &ps);
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }

    return 0;
}

// 第3引数をLPSTR型からLPWSTR型に変更(UTF-16LEのみ対応のWinCEの独自仕様)
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd) {
    WNDCLASS wcl; // WNDCLASSEXは非対応
    wcl.hInstance = hInstance;
    wcl.lpszClassName = WND_CLASS_NAME;
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
        WND_CLASS_NAME,
        TEXT("OUCC Advent Calendar 2020"),
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX,
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
    ShowWindow(hWnd, SW_MAXIMIZE);
    UpdateWindow(hWnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        DispatchMessage(&msg);
    }

    return msg.wParam;
}
