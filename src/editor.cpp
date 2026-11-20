#include "terminal_utils.hpp"
#include "renderer.hpp"

int main(){
    enableRawMode();

    std::cout << "Raw mode active. (q or CMD + Q to quit.)\r\n";

    char c;
    while (read(STDIN_FILENO, &c, 1) == 1){
        if (c == 'q' || c == 17){
            break;
        }

        if (c >= 32 && c <= 126){
            std::cout << c << "\r\n";
        }
    }
}