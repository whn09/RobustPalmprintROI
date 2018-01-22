/*************************************************************************
> File Name: Palm.h
> Author: Leosocy
> Mail: 513887568@qq.com
> Created Time: 2018/1/22 23:33:17
************************************************************************/

#ifndef __PALM_H__
#define __PALM_H__

#include <opencv2/opencv.hpp>

namespace PRDT
{
    class Palm
    {
    public:
        Palm();
        Palm(const char *imagePath);
        ~Palm();
        Palm(const Palm &other);
        Palm& operator=(const Palm &other);
    protected:
    private:
        cv::Mat data;
    };
}

#endif // !__PALM_H__
