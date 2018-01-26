#include "pcm/palm.h"

namespace prdt
{

using namespace cv;
using namespace std;

Palm::Palm()
{
}

Palm::Palm(const char *image_path)
{
    if (image_path == NULL)
    {
        return;
    }

    data_ = cv::imread(image_path);
}

Palm::~Palm()
{
}

Palm::Palm(const Palm &other)
{
    data_ = other.data_.clone();
}

Palm::Palm(const Mat &palm)
{
    data_ = palm.clone();
}

Palm& Palm::operator=(const Palm &other)
{
    if (this == &other)
    {
        return *this;
    }
    
    data_ = other.data_.clone();

    return *this;
}

} // namespace prdt
