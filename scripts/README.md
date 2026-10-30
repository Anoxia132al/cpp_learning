## 创建新的 C++ 学习模块

使用 Python 3 运行脚本，并传入小写下划线命名的模块名：

```powershell
python scripts/new_exercise.py array_reference
```

脚本会创建 `include/array_reference.h` 和 `src/array_reference.cpp`，并将源文件添加到 `CMakeLists.txt`。然后在 `src/Main.cpp` 中添加：

```cpp
#include "array_reference.h"
```

并在 `main()` 中调用 `run_array_reference();`。最后按 F5，或运行 `cmake --build build` 编译项目。
