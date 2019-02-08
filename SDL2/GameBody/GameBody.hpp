/**
 * 这个头文件是用来简化SDL2游戏开发的
 *
 * @file GameBody.hpp
 * @author VisualGMQ
 * @date Fri Feb 8 2019
 * @brief 包含一个类
 */
#ifndef _GAMEBODY_HPP_
#define _GAMEBODY_HPP_

#ifndef _XCODE_PROJECT_
#define _XCODE_PROJECT_
#endif

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#ifdef _XCODE_PROJECT_
#include <SDL2_image/SDL_image.h>
#else
#include <SDL2/SDL_image.h>
#endif
using namespace std;

/**
 * \class GameBody
 * \brief 这个类封装了很多的SDL方法，方便你去快速构建一个应用
 *
 * 这个类的用法是这样：
 * 如果你对窗体的要求不是很高的话，可以只重写update()函数来添加你自己的功能。如果需要对事件处理进行改动的话你需要重写eventHandle()函数。你也可以重写clean()函数来清空资源。所有的虚函数都是可以重写的
 * 基本的流程是这样：
 * ```
 * class myClass:public GameBody{
 *	//TODO....
 * };
 *	
 * int main(int argc,char** argv){
 *	myClass mc;
 *	while(!mc.isQuit())
 *		mc.step();
 *	return 0;
 * }
 * ```
 */
class GameBody{
public:
	/**
	 * @fn GameBody
	 * @brief 构造函数
	 * @param title 窗口的标题
	 * @param width 窗口宽度
	 * @param height 窗口高度
	 * @param flag 传递给SDL_CreateWindow()函数的参数，指定窗口的类型
	 * @param delaytime 每一帧延时的时间
	 */
	GameBody(const string,int width,int height,Uint32,int delaytime);
	/**
	 * @fn eventHandle()
	 * @brief 事件处理函数，你可以重写这个事件来给出你自己的处理过程。这个里面只是给出了退出事件的监测
	 */
	virtual void eventHandle();
	/**
	 * @fn update()
	 * @brief 每一帧要执行的代码，你几乎必须重写这个函数来实现你自己的功能（除非你想要一个不做任何事情的窗口）
	 */
	virtual void update(){};
	/**
	 * @fn step()
	 * @brief 你必须在循环里面显式的调用这个函数。这个函数里面按照流程调用了update()和一些其他的函数
	 */
	virtual void step();
	/**
	 * @fn delay(int millisec)
	 * @brief 每一帧延时的时间
	 * @param millisec 延时的时间，为微秒
	 */
	virtual void delay(int millisec);
	/**
	 * @fn isQuit()
	 * @brief 你不应该重写这个函数，它是用于在循环里面判断是否退出程序的函数
	 */
	bool isQuit(){return gamequit;};
	/**
	 * fn clean()
	 * @brief 会在析构函数里面调用，用于程序最后的清楚
	 * @return 如果app结束返回true，否则返回false
	 */
	virtual void clean(){};
	/**
	 * @fn ~GameBody()
	 * @brief 析构函数
	 */
	virtual ~GameBody();
private:
	static bool isSDL_Init;
	SDL_Window* win; 
	SDL_Renderer* render;
	SDL_Event event;
	bool error;
	bool gamequit;
	int delaytime;
	virtual void renderBegin();
	virtual void renderEnd();
};

#endif
