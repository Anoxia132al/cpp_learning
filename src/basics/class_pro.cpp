#include "class_pro.h"

Screen::Screen () = default;
Screen::Screen (pos ht, pos wd, char c) :
    height(ht), width(wd), contents(ht * wd, c) {}

char Screen::get () const
{
    return contents[cursor];
}

char Screen::get (pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];   //  返回指定列的字符
}

inline Screen& Screen::set (char c)
{
    contents[cursor] = c;   //  设置当前光标所在位置的新值
    return *this;
}

inline Screen& Screen::set (pos r, pos col, char ch)
{
    contents[r * width + col] = ch; //  设置给定位置的新值
    return *this;
}

Screen& Screen::display (std::ostream &os)
{
    do_display (os);
    return *this;
}

const Screen& Screen::display (std::ostream &os) const
{
    do_display (os);
    return *this;
}

//  负责显示 Screen 的内容
// void Screen::do_display (std::ostream &os) const
// {
//     os << contents;
// }

void Screen::do_display(std::ostream& os) const
{
    for (pos row = 0; row < height; ++row)
    {
        os << contents.substr(row * width, width) << '\n';
    }
}

inline Screen& Screen::move (pos r, pos c)
{
    pos row = r * width;    //  计算行的位置
    cursor = row + c;   //  在行内将光标移动到指定的列
    return *this;   //  以左值的形式返回对象
}

void run_test ()
{
    Screen myScreen (5, 3, 'X');
    myScreen.move(4, 0).set('#').display(std::cout);
    std::cout << "\n";
    myScreen.display(std::cout);
    std::cout << std::endl;
}