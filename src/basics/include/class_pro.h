#pragma once

#include <iostream>
#include <vector>
#include <string>

class Screen
{
public:
    using pos = std::string::size_type;
    friend class Window_mgr; 

    //  参数类型 ScreenIndex 用到 Screen 类，需要前置声明/定义
    //  friend void Window_mgr::clear (ScreenIndex);

    Screen();
    Screen(pos, pos, char);

    //  读取光标处字符
    char get() const { return contents[cursor]; } //  隐式内联
    //  返回指定列的字符
    inline char get(pos r, pos c) const { return contents[r * width + c]; } //  显式内联

    //  短小且高频的操作直接写在类内：天然 inline，每个 TU 都能看到定义
    Screen& move(pos r, pos c)
    {
        pos row = r * width; //  计算行的位置
        cursor = row + c;    //  在行内将光标移动到指定的列
        return *this;        //  以左值的形式返回对象
    }

    Screen &set(char c)
    {
        contents[cursor] = c; //  设置当前光标所在位置的新值
        return *this;
    }

    Screen& set(pos r, pos col, char ch)
    {
        contents[r * width + col] = ch; //  设置给定位置的新值
        return *this;
    }

    Screen& display(std::ostream &);
    const Screen& display(std::ostream &) const;

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

    void do_display(std::ostream &) const;
};

class Window_mgr
{
public:
    using ScreenIndex = std::vector<Screen>::size_type;

    //  按编号将指定的 Screen 重置为空白S
    void clear(ScreenIndex);
    void addScreen(const Screen &);
    ScreenIndex addScreen_pro (Screen s);           //  返回新屏幕的编号
    void displayAll(std::ostream&) const;

private :
    //  窗口中每个屏幕的编号
    std::vector<Screen> screens;
};

void run_test();
void run_test2();
