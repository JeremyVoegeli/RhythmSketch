#pragma once
#include <termios.h>
#include <unistd.h>
#include <iostream>

struct termios orig_termios;

void disableRawMode(){
    //restores original terminal attributes
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enableRawMode(){
    tcgetattr(STDIN_FILENO, &orig_termios); //get current terminal attributes

    std::atexit(disableRawMode); //sets function to run on terminal exit

    struct termios raw = orig_termios;
    cfmakeraw(&raw); //applies raw mode config

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw); //apply raw config settings
}