#include "else_random.h"

extern const int ever {64};
int Sum2 ()
{
    int sum = 0, val = 0;
    while (std::cin >> val)
        sum += val; // 输入文件结束符 Ctrl + Z 结束输入
    return sum;
}

// 统计输入中每个整数_连续_出现的次数
void cntNum ()
{
    int currval = 0, val = 0;

    if (std::cin >> currval)
    {
        int cnt = 1;
        while (std::cin >> val)
        {
            if (val == currval)
            {
                cnt++;
            }
            else
            {
                cout << currval << " occurs " << cnt << " times" << endl;
                currval = val;
                cnt = 1;
            }
        }
        cout << currval << " occurs " << cnt << " times" << endl;
    }
}

void CntNum ()
{
    std::string line;
    while (std::getline(std::cin, line))
    {
        if (line.empty()) break;  // Skip empty lines
        std::istringstream iss(line);
        int currval = 0, val = 0;
        if (iss >> currval)
        {
            int cnt = 1;
            while (iss >> val)
            {
                if (val == currval)
                {
                    cnt++;
                }
                else
                {
                    cout << currval << " occurs " << cnt << " times" << endl;
                    currval = val;
                    cnt = 1;
                }
            }
            cout << currval << " occurs " << cnt << " times" << endl;
        }
    }
}