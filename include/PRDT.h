/*************************************************************************
    > File Name: PRDT.h
    > Author: Leosocy
    > Mail: 513887568@qq.com 
    > Created Time: 2018/1/7 00:11:50
 ************************************************************************/

#ifndef __PRDT_H__
#define __PRDT_H__

#include <string>
#include <opencv2/opencv.hpp>

#ifdef _WINDOWS

#ifdef PRDT_USER
#define PRDT_API __declspec(dllimport)
#else
#define PRDT_API __declspec(dllexport)
#endif

#else
#define PRDT_API

#endif

#define _IN
#define _OUT
#define _INOUT

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __cplusplus
}
#endif

#endif /* end of prdt.h */
