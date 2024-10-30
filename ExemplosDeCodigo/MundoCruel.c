#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
    LPSTR lpCmdLine, int nCmdShow)
{ // Pelo que entendi o primeiro " " é a mensagem e a segunda aspas depois da virgula e o nome da mensagem que voce quer colocar
    MessageBox(NULL, "Hello, Your compuyter have a virus!", "Aviso da India", MB_OK);
    return 0;
}

/*  Explicação do Código - 
    WinMain() = é o equivalente do Windows a partir de DOS ou UNIX. É aqui que seu programa inicia a execução. Os parâmetros são os seguintes: main()
    HINSTANCE hPrevInstance = Sempre para programas Win32. NULL
    LPSTR lpCmdLine = Os argumentos da linha de comando como uma única cadeia de caracteres. NÃO incluindo o nome do programa.
    int nCmdShow = Um valor inteiro que pode ser passado para . Chegaremos a isso mais tarde. ShowWindow()
    hInstance é usado para coisas como carregar recursos e qualquer outra tarefa que seja realizado por módulo. 
    Um módulo é o EXE ou uma DLL carregada em seu programa. 
    Para a maior parte (se não todos) deste tutorial, haverá apenas um módulo com o qual se preocupar, o EXE.
    hPrevInstance = costumava ser o identificador para a instância executada anteriormente do seu programa (se houver) no Win16. 
    Isso não se aplica mais. No Win32 você ignora este parâmetro.
    
    Convenções de chamada - 
    WINAPI especifica a convenção de chamada e é definida como. Se você não sabe o que isso significa, 
    não se preocupe com isso pois isso realmente não nos afetará no escopo deste tutorial. 
    Apenas lembre-se disso é necessário aqui. _stdcall
    
    */