#include "page.h"

page::page(char *filename, int size)
    :filename(filename)
{
    text.reserve(size);

    int i;
    for(i = 0; i < size; i++)
    {
        text.emplace_back();
    }

} // init_page

void page::dest_page()
{
    int i;
    for(i = 0; i < numlines; i++)
    {
        free(text[i].line); // maybe replace with dest_line()
    }
    free(text);
} // dest_page



// WARNING: Expansion function implemented but not tested
void page::insert_line(int index)
{	
    if( numlines >= size ) expand_page();
    
    LINE newline;
    init_line(&newline);
    newline.line[0] = '\0';
    
    int i;

    for(i = numlines - 1; i >= index; i--)
        text[i + 1] = text[i];

    text[index] = newline;
    (numlines)++;
} // insert_line



void page::remove_line(int index)
{
    if( numlines > 1 )
    {
        free(text[index].line);
    
        int i;
        for(i = index; i < numlines - 1; i++)
        {
            text[i] = text[i + 1];
        }
        (numlines)--;
    }
} // remove_line

void page::expand()
{
    int newsize = size * 2;
    LINE *newline = malloc(newsize * sizeof(LINE));
    
    int i;
    for(i = 0; i < size; i++) // copy old lines
        newline[i] = text[i];
    for(i = size; i < newsize; i++) // init new lines
        init_line(newline + i);
        
    text = newline;
    size = newsize;
} // expand_page

// NOTE: This moves the cursor to the end of the displayed text
void page::print(const int start, int end)
{
    int i, line;
    for(i = start, line = 0; i < numlines && i < end; i++, line++)
    {
        move(line, 0);
        clrtoeol();
        printw(" %s", text[i].line);
    }
    if(start < end)
    {
        move(line, 0);   
        clrtoeol(); // if we deleted a line this may be necessary
        move(line-1, 1);
    }
    refresh();
} // print_page
