/*************************************************************************
> File Name: PRDT.h
> Author: Leosocy
> Mail: 513887568@qq.com
> Created Time: 2018/1/8 22:28:13
************************************************************************/

#include <PRDT.h>
#include <Pub.h>
using namespace PRDT;

int GetPalmROI(_IN const cv::Mat &palmImage,
               _IN const cv::Size &roiSize,
               _OUT cv::Mat &palmROI)
{
    if (palmImage.empty())
    {
        PRDT_Log("API:GetPalmROI\tPalmImage empty.");
        return PRDT_LOAD_PALM_IMAGE_FAILURE;
    }
    if (roiSize.width <= 0
        || roiSize.height <= 0)
    {
        PRDT_Log("API:GetPalmROI\tRoiSize(%d, %d) Invalid.", roiSize.width, roiSize.height);
        return PRDT_PALM_ROI_SIZE_INVALID;
    }
    return PRDT_SUCCESS;
}
int GetPalmROIAsync(_IN const cv::Mat &palmImage,
                    _IN const cv::Size &roiSize,
                    _IN ResultCallBackFunc resultCallBack,
                    _IN StateCallBackFunc stateCallBack)
{
    return PRDT_SUCCESS;
}

int GetPalmROIByPath(_IN const char *imagePath,
                     _IN const cv::Size &roiSize,
                     _OUT cv::Mat &palmROI)
{
    return PRDT_SUCCESS;
}
int GetPalmROIByPathAsync(_IN const char *imageOrVideoPath,
                          _IN const cv::Size &roiSize,
                          _IN ResultCallBackFunc resultCallBack,
                          _IN StateCallBackFunc stateCallBack)
{
    return PRDT_SUCCESS;
}