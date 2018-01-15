#pragma once

#include <ft_prdt_base.h>

class ft_get_palm_roi : public ft_prdt_base
{
public:
    virtual void SetUp();
    virtual void TearDown();

    virtual void ExcuteInterface();
};