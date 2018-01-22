/*************************************************************************
> File Name: Palm.cpp
> Author: Leosocy
> Mail: 513887568@qq.com
> Created Time: 2018/1/23 23:56:54
************************************************************************/

#include <Palm.h>

PRDT::Palm::Palm()
{
}

PRDT::Palm::Palm(const char *imagePath)
{
    if (imagePath == NULL)
    {
        return;
    }

    this->data = cv::imread(imagePath);
}

PRDT::Palm::~Palm()
{
}

PRDT::Palm::Palm(const Palm &other)
{
    this->data = other.data.clone();
}

PRDT::Palm& PRDT::Palm::operator=(const Palm &other)
{
    if (this == &other)
    {
        return *this;
    }
    
    this->data = other.data.clone();

    return *this;
}
