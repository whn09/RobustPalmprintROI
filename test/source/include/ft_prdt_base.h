#pragma once

#include <gtest/gtest.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <PRDT.h>
using namespace std;

#ifdef _WINDOWS
#define TEST_DATA_BASE_DIR "..\\test\\palm_test_data\\"
#elif
#define TEST_DATA_BASE_DIR "../test/palm_test_data/"
#endif

#define PALM_IMAGE_PATH                 TEST_DATA_BASE_DIR"palm_image.jpg"
#define NOT_EXISTS_PALM_IMAGE_PATH      TEST_DATA_BASE_DIR"palm_image_not_exists.jpg"
#define PALM_VIDEO_PATH                 TEST_DATA_BASE_DIR"palm_video.mp4"
#define NOT_EXISTS_PALM_VIDEO_PATH      TEST_DATA_BASE_DIR"palm_video_not_exists.mp4"



#define DEFAULT_PALM_ROI_WIDTH  256
#define DEFAULT_PALM_ROI_HEIGHT 256

#define PATH_LEN 128
#define FREE_CHAR_ARRAY(pArray) do {\
    if((pArray) != NULL) {\
        free((pArray));\
        (pArray) = NULL;\
    }\
}while(0)
#define MALLOC_CHAR_ARRAY(pDstArray, pSrcArray, len) do {\
    if((pSrcArray) == NULL) {\
        (pDstArray) = NULL;\
        return;\
    }\
    (pDstArray) = (char*)malloc((len) * sizeof(char));\
    strncpy((pDstArray), (pSrcArray), (len));\
}while(0)

void DefaultResultCallBack(_IN cv::Mat *palmROI);
void DefaultStateCallBack(_IN int state);

class ft_prdt_base : public testing::Test
{
public:
    ft_prdt_base();
    virtual ~ft_prdt_base();

    virtual void SetUp();
    virtual void TearDown();

    virtual void SetImagePath(const char *imagePath)
    {
        FREE_CHAR_ARRAY(this->imagePath);
        MALLOC_CHAR_ARRAY(this->imagePath, imagePath, PATH_LEN);
    }
    virtual void SetVideoPath(const char *videoPath)
    {
        FREE_CHAR_ARRAY(this->videoPath);
        MALLOC_CHAR_ARRAY(this->videoPath, videoPath, PATH_LEN);
    }
    virtual void SetPalmImage(const char *imagePath, double scale = 1.0, bool gray = false);
    virtual void SetRoiSize(int width, int height)
    {
        this->roiSize.width = width;
        this->roiSize.height = height;
    }
    
    void SetResultCallBackFunc(ResultCallBackFunc func = DefaultResultCallBack)
    {
        this->resultCallBack = func;
    }
    void SetStateCallBackFunc(StateCallBackFunc func = DefaultStateCallBack)
    {
        this->stateCallBack = func;
    }

    virtual void ExcuteInterface() = 0;
    void CheckInterfaceRet(int expectRet);
protected:
    char *imagePath;
    char *videoPath;
    cv::Mat palmImage;
    cv::Size roiSize;
    cv::Mat palmRoi;
    ResultCallBackFunc resultCallBack;
    StateCallBackFunc stateCallBack;
    int interRet;
private:
};