/*

The C++20 Masterclass: Debugging in Visual Studio Code

General Notes:
Debug Tools from gcc / GDB Debug Config (https://code.visualstudio.com/docs/cpp/config-mingw):
	- Run -> Add Configuration
	- Select C++ (GDB/LLDB)
	- Select g++.exe build and debug active files
	- launch.json file in .vscode folder is created (debugger settings)
	- Set "program" path by "${fileDirname}\\main.exe"
	- Set "externalConsole" to true
	- Set "miDebuggerPath" to "C:\\Tools\\mingw64\\bin\\gdb.exe"
	- Select "Run and Debug" side tab: config selected, variables, watch and call stack
	- Set a Break Point in the function call in the main function
	- Select "Step Into" to enter inside a function
	- Select "Step Out" to go out from a function
	- Select "Step Over" to go to the next line without going into the functions
	
Debug Tools from the Microsoft C++ compiler:
	- Copy launch.json config from https://code.visualstudio.com/docs/cpp/config-msvc
	- Set "program" path by "${fileDirname}\\main.exe"
	- Set "console": "externalTerminal"
Set "preLaunchTask": "Build with MSVC"

   [REF]: See above.
*/

using namespace std;

int &adjust(int &input);
int sum(int x, int y);

// Continue in the main function