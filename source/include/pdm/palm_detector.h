#ifndef __PALM_DETECTOR_H__
#define __PALM_DETECTOR_H__

#include "opencv2/opencv.hpp"

namespace prdt
{

class Palm;

class PalmDetector
{
public:
    PalmDetector();
    ~PalmDetector();

    void Detect(const Palm &orig_palm, cv::Rect &palm_region, Palm &precise_palm);
protected:
private:
};

} // namespace prdt

#endif