#include "line.h"

line::line()
{
    buf = std::string("\0");
} // init_line

// Insert char into string. 
// at given index
void line::insert_char(char c, int index)
{
	int i;

    //move strings to new position, by 1 place

    std::rotate(
            std::next(buf.rbegin(), index),
            std::next(buf.rbegin(), index + 1),
            buf.rend()
            );

	buf[index] = c;
}

void line::remove_char(int index)
{
    
    //move left by 1 posistion
    std::rotate(
            std::next(buf.begin(), index),
            std::next(buf.begin(), index + 1),
            buf.end()
            );
}

//add a new char at the end
//use push_back
void line::add_char(char c)
{
    buf.push_back(c);
}
