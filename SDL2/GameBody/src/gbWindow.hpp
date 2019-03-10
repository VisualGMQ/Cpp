#ifndef __GBWINDOW_HPP__
#define __GBWINDOW_HPP__
/** @file gbWindow.hpp
 * @author VisualGMQ
 * @brief 一个封装了窗口的类
 */
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "geomentry.hpp"
#include "header.hpp"
using namespace std;

/**
 * @class gbWindow
 * @brief 封装SDL_Window的类
 *
 * 这个类封装了SDL_Window
 */
class gbWindow{
public:
	/**
	 * @enum MODE
	 * @brief 记载一些flag，用于setMode函数和getMode()函数
	 */
	enum MODE{
		WINDOW_BORDERED,
		WINDOW_RESIZABLE,
		WINDOW_FULLSCREEN,
	};
	/** @fn gbWindow(SDL_Window*)
	 *  @brief 给入一个已经有的SDL_Window*。
	 *  @param window SDL_Window*参数
	 */
	gbWindow(SDL_Window*);
	/** @fn gbWindow(const string title,int width,int height,Uint32 type,string iconpath = "")
	 *  @brief 给入必要的参数来构建一个窗口
	 *  @param title 窗口标题
	 *  @param width 窗口高度
	 *  @param height 窗口宽度
	 *  @param type SDL2自带的窗体类型，比如SDL_WINDOW_SHOWN
	 *  @param iconpath 窗口icon图标的路径。默认为空表示没有图标
	 */
	gbWindow(const string title,int width,int height,Uint32 type,string iconpath = "");
	/** @fn getSize()
	 *  @brief 返回窗体大小
	 *  @return 返回gbSize
	 */
	gbSize getSize();
	/** @fn isFocus()
	 *  @brief 判断是否有焦点
	 *  @return 如果有焦点返回true
	 */
	bool isFocus();
	/** @fn getTitle()
	 *  @brief 获得标题
	 *  @see setTitle()
	 */
	const string getTitle();
	/** @fn getPosition()
	 *  @brief 返回窗体位置
	 *  @see setPosition()
	 */
	gbPoint getPosition();
	/** @fn getBrightness()
	 *  @brief 返回窗体亮度
	 *  @see setBrightness()
	 */
	float getBrightness();
	/** @fn getMode()
	 *  @brief 获得当时传入的flag
	 *  @see setMode()
	 */
	Uint32 getMode();
	/** @fn setTitle(string)
	 *  @brief 设置标题
	 *  @param title 标题
	 */
	void setTitle(string);
	/** @fn setBrightness(float)
	 *  @brief 设置窗体亮度
	 */
	void setBrightness(float);
	/** @fn setIcon(string path)
	 *  @brief 设置窗口icon
	 *  @param path icon路径
	 */
	void setIcon(string path);
	/** @fn setMode(MODE,bool)
	 *  @brief 设置窗体的模式
	 *  @param mode 必须是MODE枚举类型，窗体的模式
	 *  @param bool 设置传入的mode是否可用
	 *  @see MODE
	 *
	 *  mode参数不能够传入任意的SDL_WINDOW_*，而是只能够在MODE枚举里面选择。这个函数内部其实调用了SDL_SetWindowResizable()和SDL_SetWindow_FullScreen()等函数。
	 */
	void setMode(MODE,bool);
	/** @fn getWindow()
	 *  @brief 获得SDL_Window*
	 */
	GB_GET_BASIC_SOURCE(SDL_Window*,window);
	~gbWindow();
protected:
	/** @fn loadIcon(string path)
	 *  @brief 载入icon的函数
	 *  @param path icon图标的位置
	 */
	bool loadIcon(string path);
	Uint32 WindowMode;
	SDL_Surface* icon;
	SDL_Window* window;
};

#endif
