#include "class_pro.h"

Screen::Screen () = default;
Screen::Screen (pos ht, pos wd, char c) :
    height(ht), width(wd), contents(ht * wd, c) {}


Screen& Screen::display (std::ostream &os)
{
    do_display (os);
    return *this;
}

//  重载
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

//  =============================================

void Window_mgr::clear (ScreenIndex i)
{
    Screen &s = screens[i];

    s.contents = std::string (s.height * s.width, ' ');
}

void Window_mgr::addScreen (const Screen &s)
{
    screens.push_back(s);
}

//  addScreen(Screen) + std::move	少一次拷贝
Window_mgr::ScreenIndex Window_mgr::addScreen_pro (Screen s)
{
    screens.push_back(std::move(s));
    return screens.size() - 1;
}

//  可切换到文件流/ostringstream 测试，块间加分隔线
void Window_mgr::displayAll (std::ostream& os) const
{
    for (ScreenIndex i = 0; i < screens.size(); ++i)
    {
        os << "---- screen " << i << " ----\n";
        screens[i].display(os); //  这里选中的是 const 重载
    }
}

void run_test ()
{
    Screen myScreen (5, 3, 'X');
    myScreen.move(4, 0).set('#').display(std::cout);
    std::cout << "\n";
    myScreen.display(std::cout);
    std::cout << std::endl;
}

void run_test2 ()
{
    Window_mgr wm;
    wm.addScreen(Screen(3, 3, 'X'));
    wm.addScreen(Screen(4, 4, 'Y'));
    wm.addScreen(Screen(5, 5, 'Z'));

    std::cout << "==== before clear ====\n";
    wm.displayAll(std::cout);

    wm.clear(2);
    std::cout << "==== after clear(2) ====\n";
    wm.displayAll(std::cout);
}