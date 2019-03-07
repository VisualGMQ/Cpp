/**
 * @file header.hpp
 * @brief 包含一些全局的变量
 * @author VisualGMQ
 * 
 * 这个头文件里面包含了很多全局的变量，用于各个头文件调用
 */
#ifndef __HEADER_HPP__
#define __HEADER_HPP__

#include <SDL2/SDL.h>

/**
 * @def GB_CREATE_GETFUNC(vartype,funcname,varname)
 * @brief 在类里面创造一个get方法
 * @param vartype 要get的变量的类型
 * @param funcname 函数的名称，这个函数会在这个名称前加get
 * @param varname 要get的变量名
 *
 * @see GB_CREATE_SETFUNC
 * @see GB_CREATE_GETSETFUNC
 */
#define GB_CREATE_GETFUNC(vartype,funcname,varname) \
vartype get##funcname(){\
	return varname;\
}
/**
 * @def GB_CREATE_SETFUNC(vartype,funcname,varname)
 * @brief 在类里面创造一个set方法
 * @param vartype 要set的变量的类型
 * @param funcname 函数的名称，这个函数会在这个名称前加get
 * @param varname 要set的变量名
 * @see GB_CREATE_GETFUNC
 * @see GB_CREATE_GETSETFUNC
 */
#define GB_CREATE_SETFUNC(settype,funcname,varname) \
void set##funcname(settype param){\
	varname = param;\
}

/**
 * @def GB_CREATE_GETSETFUNC(vartype,funcname,varname)
 * @brief 在类里面创造一个set方法和一个get方法
 * @param vartype 要set/get的变量的类型
 * @param funcname 函数的名称
 * @param varname 要set/get的变量名
 * @see GB_CREATE_GETFUNC
 * @see GB_CREATE_SETFUNC
 */

#define GB_CREATE_GETSETFUNC(vartype,funcname,varname) \
GB_CREATE_GETFUNC(vartype,funcname,varname)\
GB_CREATE_SETFUNC(vartype,funcname,varname)


SDL_Renderer* globaleRenderer = nullptr;
bool isSDL_Init = false;
#endif
