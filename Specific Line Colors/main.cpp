#include <windows.h>
#include <iostream>
using namespace std;
///Think about wrapping WinAPI calls to throw exceptions
///instead of constant erorcode checking
int main()
{
    system("color 4A");
    /// Get handle to STDOUT.
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdout == INVALID_HANDLE_VALUE)
        return EXIT_FAILURE;

    /// Save the current text colors.
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    if (! GetConsoleScreenBufferInfo(hStdout, &csbiInfo))
        return EXIT_FAILURE;
    WORD wOldColorAttrs = csbiInfo.wAttributes;

    /// Set the text attributes to draw red text on black background.
    if (! SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | FOREGROUND_INTENSITY))
        return EXIT_FAILURE;
    cout << "HI\n";

    /// Set the text attributes to draw green text on black background.
    if (! SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY))
        return EXIT_FAILURE;
    cout << "Hi again!\n";

    /// Restore the original text colors.
    SetConsoleTextAttribute(hStdout, wOldColorAttrs);
}
