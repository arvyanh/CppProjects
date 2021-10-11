#ifndef LINE_H
#define LINE_H
/* LINE struct and functions */

#include <string>

#define TAB_WIDTH 4

struct line
{
    std::string buf;

    line();
    void insert_char(char c, int index); // inserts char to string
    void remove_char(int index);
    void expand_size(); // doubles the size of the line
    void add_char(char c); // add to end of line

    auto size(){return  buf.size();}
};


#endif
