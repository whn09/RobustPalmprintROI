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

#define PRDT_SUCCESS 0
#define PRDT_NULL_POINTER_ERROR 1

#define PRDT_LOAD_PALM_IMAGE_FAILURE 100
#define PRDT_LOAD_PALM_VIDEO_FAILURE 101

#define PRDT_PALM_ROI_SIZE_INVALID 200

#define PRDT_EXCUTE_RESULT_CALL_BACK_FUNC_ERROR 300
#define PRDT_EXCUTE_STATE_CALL_BACK_FUNC_ERROR 301

#define _IN
#define _OUT
#define _INOUT

#ifdef __cplusplus
extern "C"
{
#endif
    typedef void(*ResultCallBackFunc)(_IN cv::Mat *palmROI);
    typedef void(*StateCallBackFunc)(_IN int state);

    PRDT_API int GetPalmROI(_IN const cv::Mat &palImage,
                            _IN const cv::Size &roiSize,
                            _OUT cv::Mat &palmROI);
    PRDT_API int GetPalmROIAsync(_IN const cv::Mat &palmImage,
                                 _IN const cv::Size &roiSize,
                                 _IN ResultCallBackFunc resultCallBack,
                                 _IN StateCallBackFunc stateCallBack);

    PRDT_API int GetPalmROIByPath(_IN const char *imagePath,
                                  _IN const cv::Size &roiSize,
                                  _OUT cv::Mat &palmROI);
    PRDT_API int GetPalmROIByPathAsync(_IN const char *imageOrVideoPath,
                                       _IN const cv::Size &roiSize,
                                       _IN ResultCallBackFunc resultCallBack,
                                       _IN StateCallBackFunc stateCallBack);

#ifdef __cplusplus
}
#endif

#endif /* end of prdt.h */
