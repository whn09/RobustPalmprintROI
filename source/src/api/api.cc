#include "prdt.h"
#include "pcm/controller.h"
#include "pcm/palm.h"
#include "util/pub.h"

using namespace prdt;

int GetPalmROI(const cv::Mat &palm_image,
               const cv::Size &roi_size,
               cv::Mat &palm_roi)
{
    printf("GetPalmROI in api.cc\n");
    if (palm_image.empty())
    {
        PRDT_Log("PalmImage empty.");
        return PRDT_LOAD_PALM_IMAGE_FAILURE;
    }
    if (roi_size.width <= 0
        || roi_size.height <= 0)
    {
        PRDT_Log("RoiSize(%d, %d) Invalid.", roi_size.width, roi_size.height);
        return PRDT_PALM_ROI_SIZE_INVALID;
    }

    printf("roi_size.width = %d, roi_size.height = %d\n", roi_size.width, roi_size.height);

    Palm orig_palm(palm_image);
    Controller algorithm_controller;
    algorithm_controller.InjectPalm(orig_palm);

    return PRDT_SUCCESS;
}
int GetPalmROIAsync(_IN const cv::Mat &palm_image,
                    _IN const cv::Size &roi_size,
                    _IN ResultCallBackFunc result_call_back,
                    _IN StateCallBackFunc state_call_back)
{
    return PRDT_SUCCESS;
}

int GetPalmROIByPath(_IN const char *image_path,
                     _IN const cv::Size &roi_size,
                     _OUT cv::Mat &palm_roi)
{
    printf("GetPalmROIByPath in api.cc\n");
    cv::Mat image = cv::imread(image_path, cv::CV_LOAD_IMAGE_UNCHANGED);
    return GetPalmROI(image, roi_size, palm_roi)
}
int GetPalmROIByPathAsync(_IN const char *image_or_video_path,
                          _IN const cv::Size &roi_size,
                          _IN ResultCallBackFunc result_call_back,
                          _IN StateCallBackFunc state_call_back)
{
    return PRDT_SUCCESS;
}