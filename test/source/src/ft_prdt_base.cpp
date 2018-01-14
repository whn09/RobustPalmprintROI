#include <ft_prdt_base.h>

void(*DefaultResultCallBack)(_IN cv::Mat *palmROI)
{

};
void(*DefaultStateCallBack)(_IN int state)
{

};

ft_prdt_base::ft_prdt_base()
{

}

ft_prdt_base::~ft_prdt_base()
{

}

void ft_prdt_base::SetUp()
{

}

void ft_prdt_base::TearDown()
{

}

void ft_prdt_base::SetPalmImage(const char *imagePath, double scale, bool gray)
{
    if (imagePath == NULL)
    {
        EXPECT_STREQ("ImagePath", " can't be NULL!");
        return;
    }

    this->palmImage = gray ? cv::imread(imagePath, 0) : cv::imread(imagePath);
    cv::Size newSize(this->palmImage.cols*scale, this->palmImage.rows*scale);
    cv::resize(this->palmImage, this->palmImage, newSize);
}