#ifndef __PRDT_H__
#define __PRDT_H__

#include "opencv2/opencv.hpp"

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
    typedef void(*ResultCallBackFunc)(_IN cv::Mat *palm_roi);
    typedef void(*StateCallBackFunc)(_IN int state);

    PRDT_API int GetPalmROI(_IN const cv::Mat &palm_image,
                            _IN const cv::Size &roi_size,
                            _OUT cv::Mat &palm_roi);
    PRDT_API int GetPalmROIAsync(_IN const cv::Mat &palm_image,
                                 _IN const cv::Size &roi_size,
                                 _IN ResultCallBackFunc result_call_back,
                                 _IN StateCallBackFunc state_call_back);

    PRDT_API int GetPalmROIByPath(_IN const char *image_path,
                                  _IN const cv::Size &roi_size,
                                  _OUT cv::Mat &palm_roi);
    PRDT_API int GetPalmROIByPathAsync(_IN const char *image_or_video_path,
                                       _IN const cv::Size &roi_size,
                                       _IN ResultCallBackFunc result_call_back,
                                       _IN StateCallBackFunc state_call_back);

#ifdef __cplusplus
}
#endif

#endif /* end of prdt.h */
