#ifndef PAGE_H
#define PAGE_H
/* PAGE struct definition and related functions */

#include <ncurses.h> // might have to move this
#include <vector>
#include <string>
#include "line.h" 

#define PAGE_SIZE 500 /* Default number of lines */
#define WIN_SIZE (LINES - 2) /* Size of window, making room for bottom prompt */
#define NAME_LIMIT 256 /* Max size of a unix filename + 1 */

struct page {
    std::string filename;
    std::vector<line> text; // lines of text
	int size; // size of array

    page(char *filename, int size);
    void dest_page();
    void insert_line(int index);
    void remove_line(int index);
    void expand();
    void print(int start, int end);
};

#endif
