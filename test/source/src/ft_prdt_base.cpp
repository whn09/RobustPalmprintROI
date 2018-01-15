#include <ft_prdt_base.h>

void DefaultResultCallBack(_IN cv::Mat *palmROI)
{

}
void DefaultStateCallBack(_IN int state)
{

}

ft_prdt_base::ft_prdt_base()
{

}

ft_prdt_base::~ft_prdt_base()
{

}

void ft_prdt_base::SetUp()
{
    this->imagePath = NULL;
    this->videoPath = NULL;
}

void ft_prdt_base::TearDown()
{
    FREE_CHAR_ARRAY(this->imagePath);
    FREE_CHAR_ARRAY(this->videoPath);
    this->palmImage.release();
    this->palmRoi.release();
    this->roiSize.width = 0;
    this->roiSize.height = 0;
}

void ft_prdt_base::SetPalmImage(const char *imagePath, double scale, bool gray)
{
    if (imagePath == NULL)
    {
        EXPECT_STREQ("ImagePath", " can't be NULL!");
        return;
    }

    this->palmImage = gray ? cv::imread(imagePath, 0) : cv::imread(imagePath);
    if (this->palmImage.empty())
    {
        return;
    }
    cv::Size newSize((int)this->palmImage.cols*scale, (int)this->palmImage.rows*scale);
    cv::resize(this->palmImage, this->palmImage, newSize);
}

void ft_prdt_base::CheckInterfaceRet(int expectRet)
{
    EXPECT_EQ(interRet, expectRet);
}
