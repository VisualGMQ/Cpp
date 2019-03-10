### GameBody文件说明
	GameBody将SDL2的基本流程封装在GameBody类中，方便以后写测试文件的时候可以快速的测试。
## GameBody使用方法：
	原生的GameBody类只是创造一个窗口，不会有任何的其他动作。你可以创建一个GameBody对象来显示这个窗口。如果想要添加自己的东西，需要继承GameBody类，重写update()函数以及clean()函数。update用于在游戏中执行的更新，clean用于在游戏结束后的清理工作。
	GameBody类里除了isQuit()和构造函数之外，所有的函数都是virtual函数，意味着你可以重写来实现自己的功能。一般都是重写update()函数来实现功能。
## GameBody对象的使用流程：
	1. 首先声明一个GameBody或者你自己继承的类的对象。
	2. 使用RUN\_APP()宏来让你的类运行起来。

	就可以完成游戏的流程。

更新：
**2018.12.6**:
	完成了GameBody的类定义。

**2018.12.7**:
    添加了#ifdef \_XCODE\_PROJECT_来使这个头文件在XCODE和g++里面都可以编译（因为这两个的头文件导入的路径不一样）。但是不可以简单的直接在源文件里面加上#define \_XCODE\_PROJECT\_，而是需要在GameBody.cpp和GameBody.hpp的开始部分都加上
```c++	
\#ifndef \_XCODE\_PROJECT\_
\#define \_XCODE\_PROJECT\_
\#endif
```

**2019.2.16**
	* 将main函数封装在RUN_APP()宏里面，方便整体结构，不需要写main函数，也不需要记住类的成员函数的调用顺序了。

**2019.3.8**
	* 添加了一些UML模型，写了gbWindow,geomentry,header文件。重新整理了工程的文件夹（变的有工程的样子了）。
	* 编译虽然没有报错，但是在运行test.cpp测试文件的时候会报Segment fault错误（运行错误），很烦。

**2019.3.10**
	* 修改了Segment fault错误
	* 对gbWindow和geomentry写了测试文件，通过全部测试，应该可以正常使用了。
	* 对gbWindow和geomentry写了doxygen注释。
