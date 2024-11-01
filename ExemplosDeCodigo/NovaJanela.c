#include <windows.h>

const char g_szClassName[] = "myWindowClass";

// Step 4: o procedimento de janela
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    //Step 1: Registrando a classe Janela
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Step 2: Creating the Window
    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "SEIB alpha lobo macho alha supremo!",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720,
        NULL, NULL, hInstance, NULL);

    if(hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // Step 3: O loop da mensagem 
    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}

// Codigo copiado do link - http://www.winprog.org/tutorial/simple_window.html :)

/*  Explicação do código - 
    cbSize - O tamanho da estrutura.
    style - Class Styles (), não deve ser confundido com Window Styles ().
    Isso geralmente pode ser definido como. CS_*WS_*0
    lpfnWndProc - Ponteiro para o procedimento de janela para essa classe de janela.
    cbClsExtra - Amount of extra data allocated for this class in memory. Usually . 0
    cbWndExtra - Quantidade de dados extras alocados na memória por janela desse tipo. Normalmente. 0
    hInstance - Identificador para a instância do aplicativo (que obtivemos no primeiro parâmetro de ). WinMain()
    hIcon - Ícone grande (geralmente 32x32) mostrado quando o usuário pressiona Alt+Tab.
    hCursor - Cursor que será exibido sobre nossa janela.
    hbrBackground - Pincel de fundo para definir a cor da nossa janela.
    lpszMenuName - Nome de um recurso de menu a ser usado para as janelas com essa classe.
    lpszClassName - Nome com o qual identificar a classe.
    hIconSm - Ícone pequeno (geralmente 16x16) para mostrar na barra de tarefas e no canto superior esquerdo da janela.
    */