# Null
A cross-platform C++ module-only library with many useful features. Just drag and drop! It's that easy.

# How to use
1. Make sure you set your compiler's language standard to **C++20/C++23** or higher.
2. **Clone** the repository anywhere inside your project, for example, in a directory named `dependencies`.
```bash
MyProject\dependencies> git clone https://github.com/Beyondo/null
```
3. Enjoy using modules in C++!

**For Visual Studio:**
- Make sure to click on "Show All Files" icon then click on refresh icon.
- Right click on `dependencies` or `dependencies/null` directory and click "Include In Project".

# How to use - Drag/Drop (VS)
1. In **filter view** mode, create a filter named anything, let's say X.
2. Download the library anywhere then just **drag and drop** it inside X.<br>

# Available modules
- `null.filterable`
- `null.clipboard`
- `null.window`
- `null.math`
- `null.meta`
- `null.vulkan` (requires linking to `vulkan-1` and defining the preprocessor `NULL_USE_VULKAN`)
- `null.graphics` (requires linking to your chosen graphics APIs and defining preprocessors for each of them)

# Quick example:
```cpp
import null.clipboard;
using namespace null;
int main()
{
	clipboard::set_text("Hello World!");
	return 0;
}
```

# Notes:
- All library modules are prefixed by `null.[module_name]`.
- All library modules are in the namespace `null::`.
- This library was coded so that Intellisense would always work fine with it.

If you found this library useful, or at least a good helpful example of how next-gen libraries of C++23 modules should be like, then pleaes consider starring it!
