#ifndef __PALM_H__
#define __PALM_H__

#include "opencv2/opencv.hpp"

namespace prdt
{

class Palm
{
public:
    Palm();
    ~Palm();
    Palm(const char *image_path);
    Palm(const Palm &other);
    Palm(const cv::Mat &palm);
    
    Palm& operator=(const Palm &other);
protected:
private:
    cv::Mat data_;
};

} // namespace prdt

#endif // !__PALM_H__
