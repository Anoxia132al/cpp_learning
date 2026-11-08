#include "string_vector_arry.h"

void string_cin ()
{
    std::string s1, s2;
    std::cin >> s1 >> s2;
    cout << s1 << " " << s2 << endl;

    while (std::cin >> s1 && s1 != "quit")  { cout << s1 << endl; }
        cout << "end input above" << endl;

    //  std::cin.ignore();  //  忽略输入 "缓冲区" 中的换行符, 否则 getline 会读取到换行符而返回结果
    //  默认只忽略一个字符
    //  std::cin.ignore(100, '\n');  //  忽略输入 "缓冲区" 中的前 100 个字符, 直到遇到换行符为止
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //  忽略输入 "缓冲区" 中的所有字符, 直到遇到换行符为止
    while (getline(std::cin, s1))  if (!s1.empty())  //  s1.empty() 判断字符串是否为空, 为空返回 true, 否则返回 false
        { 
            cout << s1 << endl;
            cout << "s1->size = " << s1.size();
            break;
        }
}

void process_string ()
{
    std::string str = "Hello, three, 2, one!";
    for (auto c : str)  { cout << c; }  cout << endl;
    for (auto &c : str)  c = toupper(c);  //  将字符串中的每个字符转换为大写字母
    cout << str << endl;

    std::string str2 = "0123456789ABCDEF", result;
    int n;
    while (std::cin >> n && n != -1)
    {
        if ((std::string::size_type)n < str2.size())  { result += str2[n]; }  //  size() 返回值为 std::string::size_type 类型
    }  
    cout << result;
}

void pos_vector ()
{
    vector<std::string> str_vec {"Hello", "World", "C++", "Vector"};

    for (const auto &v : str_vec) { std::cout << v << " "; }  
    std::cout << std::endl;
    
    std::string str;
    vector<std::string> str_vec2;

    while (std::cin >> str)  { str_vec2.push_back(str); }  //  push_back() 将元素添加到容器的末尾
    for (const auto &v : str_vec2) { std::cout << v << " "; }
} 

void ts_iterator ()
{
    vector<std::string> str_vec {"Hello", "World", "C++", "Vector"};
    auto it = str_vec.cbegin();  //  cbegin() 返回一个指向容器开头的常量迭代器, 不能修改容器中的元素

    while (it != str_vec.cend())  { cout << *it++ << " "; }  //  cend() 返回一个指向容器末尾的常量迭代器, 不能修改容器中的元素
    cout << endl;
    for (auto it = str_vec.cbegin(); it != str_vec.cend(); ++it)  { cout << *it << " "; }
    cout << endl;

    vector<unsigned> scores (11, 0);
    unsigned grade;
    auto beg = scores.begin();  //  begin() 返回一个指向容器开头的迭代器, 可以修改容器中的元素
    while (std::cin >> grade) 
    { 
        if (grade <= 100)  ++*(beg + grade / 10);  //  beg + grade / 10 返回一个指向 scores 容器中对应元素的迭代器, 然后对该元素进行自增操作
    }
    for (auto it = scores.cbegin(); it != scores.cend(); ++it)  
    cout << *it << " "; 
}

void lk_arry ()
{
    int arr[] = {0, 1, 2, 3, 4, 5};

    for (int* p = arr; p != &arr[6]; ++p) { std::cout << *p << " "; } 
    std::cout << std::endl;

    int* beg = std::begin(arr);  //  begin() 返回一个指向数组开头的指针, 可以修改数组中的元素
    int* end = std::end(arr);
    while (beg != end) { std::cout << *beg << " "; ++beg; } std::cout << std::endl;

    int* rp = &arr[3];
    std::cout << rp[1] << std::endl; //  rp[1] 等价于 *(rp + 1),即 arr[4] 表示的元素
}

void mld_arry ()
{
    constexpr size_t rowCnt = 3, colCnt = 4;  //  constexpr 用于定义常量表达式, 在编译时求值, 可以用于数组大小等需要常量的地方
    //  size_t 是无符号整数类型, 用于表示对象的大小, 以及数组下标等, 在 32 位系统中通常为 4 字节, 在 64 位系统中通常为 8 字节
    //  与 size_type 不同, size_t 是 C++ 标准库中定义的类型, 而 size_type 是 STL 容器中定义的类型, 例如 vector<int>::size_type
    //  size_type 是为了保证在不同平台上都能正确表示容器的大小, 而 size_t 是为了保证在不同平台上都能正确表示对象的大小
    int ia[rowCnt][colCnt] = { {0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11} };

    for (size_t i = 0; i != rowCnt; ++i)
    {
        for (size_t j = 0; j != colCnt; ++j) { cout << ia[i][j] << " "; }
        cout << endl; 
    }

    //  使用范围 for 循环遍历多维数组, 需要使用引用类型, 否则会将数组退化为指针, 编译器将 row 判为 int* 类型
    for (const auto &row : ia)  //  如果写 (auto row : ia) 会把数组退化为指针，编译器将 row 判为 int* 类型
    {
        for (auto col : row) { cout << col << " "; }
        cout << endl;
    }

    for (auto p = ia; p != ia + rowCnt; ++p)
    {
        for (auto q = *p; q != *p + colCnt; ++q) { cout << *q << " "; }
        cout << endl;
    }

    for (auto p = std::begin(ia); p != std::end(ia); ++p)
    {
        for (auto q = std::begin(*p); q != std::end(*p); ++q) { cout << *q << " "; }
        cout << endl;
    }
}

void mld_vector ()
{
    vector<vector<int>> ia = { {0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11} };
    for (const auto &row : ia)
    {
        for (auto col : row) { cout << col << " "; }
        cout << endl;
    }
}