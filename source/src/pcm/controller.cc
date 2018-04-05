#include "pcm/controller.h"
#include "pcm/palm.h"
#include "util/pub.h"

namespace prdt
{

Controller::Controller()
{
    palm_ = NULL;
}

Controller::~Controller()
{
    if (palm_ != NULL)
    {
        delete palm_;
    }
}

void Controller::InjectPalm(const Palm &palm)
{
    bool bRet = false;
    bRet = MallocPalmData();
    if (bRet)
    {
        *palm_ = palm;
    }
    else
    {
        PRDT_Log("Inject palm failed. Malloc palm data error");
    }
}

bool Controller::MallocPalmData()
{
    FreePalmData();
    palm_ = new Palm();

    return palm_ == NULL ? false : true;
}

void Controller::FreePalmData()
{
    if (palm_ != NULL)
    {
        delete palm_;
        palm_ = NULL;
    }
}

} // namespace prdt
