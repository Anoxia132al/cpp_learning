#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <memory>
#include <string>
#include <vector>

using std::cout;
using std::endl;

class StrBlobPtr;

class StrBlob
{
public:
    friend class StrBlobPtr;

    using size_type = std::vector<std::string>::size_type;

    //  StrBlob () = default;
    //  让 data 指向空的 vector
    StrBlob () : data(std::make_shared<std::vector<std::string>>()) {}
    
    //  **initializer_list 专门用来接收 {} 传来的数据，作为轻量级的中转站
    StrBlob(std::initializer_list<std::string> il)
        : data(std::make_shared<std::vector<std::string>>(il))
    {
    }

    size_type size () const { return data->size(); }
    bool empty () const { return data->empty(); }

    void push_back (const std::string& t) { data->push_back(t); }
    void pop_back () 
    {
        check (0, "pop_back on empty StrBlob");
        data->pop_back(); 
    }
    
    //  front()、back()：访问首元素、末元素
    std::string& front () { check (0, "front on empty StrBlob"); return data->front(); }
    const std::string& front () const { check (0, "front on empty StrBlob"); return data->front(); }
    std::string& back () { check (0, "back on empty StrBlob"); return data->back(); }
    const std::string& back () const { check (0, "back on empty StrBlob"); return data->back(); }

    StrBlobPtr begin();
    StrBlobPtr end();

private:
    std::shared_ptr<std::vector<std::string>> data;

    //  如果 data[i] 不合法，抛出一个异常
    void check (size_type i, const std::string &msg) const
    {
        if (i >= data->size()) 
            throw std::out_of_range(msg);
    }
};

//  =====================================================

class StrBlobPtr
{
public:
    StrBlobPtr () : curr(0) {}
    StrBlobPtr (StrBlob& a, std::size_t sz = 0)
        : wptr (a.data), curr (sz) {}

    bool operator!= (const StrBlobPtr& rhs) const { return curr != rhs.curr; }
    //  deref()：读取当前迭代位置的字符串
    std::string& deref () const
    {
        return (*check (curr, "dereference past end"))[curr];
    }
    //  前缀递增, 把迭代位置前进一格
    StrBlobPtr& incr ()
    {
        check (curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }
private:
    std::shared_ptr<std::vector<std::string>> 
    check (std::size_t i, const std::string& msg) const
    {
        auto ret = wptr.lock ();
        if (!ret)
            throw std::runtime_error("unbound StrBlobPtr");
        if (i >= ret->size())
            throw std::out_of_range(msg);
        return ret;
    }
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;   //  再数组中的当前位置
};

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this, data->size());
}

//  =======================================================

void test_StrBlob()
{
    StrBlob words{"C++", "shared_ptr", "weak_ptr"};

    cout << "size: " << words.size() << '\n';
    cout << "empty: " << (words.empty() ? "true" : "false") << '\n';
    cout << "front: " << words.front() << '\n';
    cout << "back: " << words.back() << '\n';

    words.push_back("StrBlob");
    cout << "after push_back, back: " << words.back() << '\n';

    cout << "elements: ";
    auto iter = words.begin();
    const auto last = words.end();

    for (; iter != last; iter.incr())
        cout << iter.deref() << ' ';
    cout << '\n';

    // 循环结束时 iter 已到达 end，尾后位置不能解引用
    try
    {
        (void)iter.deref();
    }
    catch (const std::out_of_range& e)
    {
        cout << "end dereference: " << e.what() << '\n';
    }

    words.pop_back();
    cout << "after pop_back, size: " << words.size()
         << ", back: " << words.back() << '\n';

    StrBlob copy = words;
    copy.front() = "modified";
    cout << "shared data, original front: " << words.front() << '\n';
}

std::vector<int>* create_vector () { return new std::vector<int>(); }
std::shared_ptr<std::vector<int>> create_vector2 ()
    { return std::make_shared<std::vector<int>>(); }

void read_input (std::vector<int>* ptr)
{
    int num;
    while (std::cin >> num)
    {
        ptr->push_back(num);
    }
}
//  read_input2 和 print_vector2 按值接收 shared_ptr 会增加引用计数
//  这里不需要它们拥有指针，可以用 const 引用
void read_input2 (const std::shared_ptr<std::vector<int>>& ptr)
{
    int num;
    while (std::cin >> num)
    {
        ptr->push_back(num);
    }
}

void print_vector (std::vector<int>* ptr)
{
    for (int val : *ptr)
    {
        cout << val << " ";
    }
    cout << endl;
}
void print_vector2 (const std::shared_ptr<std::vector<int>>& ptr)
{
    for (int val : *ptr)
    {
        cout << val << " ";
    }
    cout << endl;
}

void run_above ()
{
    std::vector<int>* p = create_vector ();
    read_input (p);
    print_vector (p);
    delete p;
    p = nullptr;
}
void run_above2 ()
{
    auto p = create_vector2 ();
    read_input2 (p);
    print_vector2 (p);
}

//  ==========================================================

int main ()
{
    //  run_above ();
    //  run_above2 ();
    test_StrBlob ();
    return 0;
}
