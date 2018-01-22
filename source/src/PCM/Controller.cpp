/*************************************************************************
> File Name: Controller.cpp
> Author: Leosocy
> Mail: 513887568@qq.com
> Created Time: 2018/1/23 23:42:27
************************************************************************/

#include <Controller.h>

PRDT::Controller::Controller()
{
    this->palm = NULL;
}

PRDT::Controller::~Controller()
{
    if (this->palm != NULL)
    {
        delete palm;
    }
}

void PRDT::Controller::RegisterPalm(const Palm &palm)
{
    bool bRet = false;
    bRet = MallocPalmData();
    if (bRet)
    {
        *this->palm = palm;
    }
}

bool PRDT::Controller::MallocPalmData()
{
    FreePalmData();
    this->palm = new Palm();

    return this->palm == NULL ? false : true;
}

void PRDT::Controller::FreePalmData()
{
    if (this->palm != NULL)
    {
        delete this->palm;
        this->palm = NULL;
    }
}