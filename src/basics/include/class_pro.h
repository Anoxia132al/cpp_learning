#pragma once

#include <iostream>
#include <vector>

class Screen
{
public :
    using pos = std::string::size_type;

    Screen ();
    Screen (pos, pos, char);

    //  读取光标处字符
    char get () const;  //  隐式内联
    inline char get (pos, pos) const;   //  显式内联
    Screen& move (pos, pos);

    Screen& set (char);
    Screen& set (pos, pos, char);

    Screen& display (std::ostream&);
    const Screen& display (std::ostream&) const;
private :
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

    void do_display (std::ostream&) const;
};

class Window_mgr
{
    std::vector<Screen> screens = {Screen (24, 80, ' ')};
};

void run_test ();

