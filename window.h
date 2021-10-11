#ifndef TEXT_H
#define TEXT_H


#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <ncurses.h>

#include "page.h"
#include "prompt.h"

int file_exists(char *filename);
int count_lines(FILE *fp);

struct window{
    struct curser;
    page p;
    int x,y;

    int y_offset = 0;
    int tab_offset = 0;

    std::fstream file;

    window(const std::string filename);
    void load_file(const char* filename);
    void save_file();
    void update_status(char *info);
    void move_left();
    void move_right();
    void move_up();
    void move_down();
    void print_loc();
};





#endif

