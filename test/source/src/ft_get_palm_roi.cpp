#pragma once

#include <ft_get_palm_roi.h>

void ft_get_palm_roi::SetUp()
{
    ft_prdt_base::SetUp();

    SetPalmImage(PALM_IMAGE_PATH);
    SetRoiSize(DEFAULT_PALM_ROI_WIDTH, DEFAULT_PALM_ROI_HEIGHT);
}

void ft_get_palm_roi::TearDown()
{
    ft_prdt_base::TearDown();
}

void ft_get_palm_roi::ExcuteInterface()
{
    interRet = GetPalmROI(this->palmImage,
                          this->roiSize,
                          this->palmRoi);
}

TEST_F(ft_get_palm_roi, Given_EmptyPalmImageMat_When_GetPalmROI_Then_PRDT_LOAD_PALM_IMAGE_FAILURE)
{
    SetPalmImage(NOT_EXISTS_PALM_IMAGE_PATH);

    ExcuteInterface();

    CheckInterfaceRet(PRDT_LOAD_PALM_IMAGE_FAILURE);
}

TEST_F(ft_get_palm_roi, Given_PalmRoiSizeWidthLE0_When_GetPalmROI_Then_PRDT_PALM_ROI_SIZE_INVALID)
{
    SetRoiSize(0, DEFAULT_PALM_ROI_HEIGHT);

    ExcuteInterface();

    CheckInterfaceRet(PRDT_PALM_ROI_SIZE_INVALID);
}

TEST_F(ft_get_palm_roi, Given_PalmRoiSizeHeightLE0_When_GetPalmROI_Then_PRDT_PALM_ROI_SIZE_INVALID)
{
    SetRoiSize(DEFAULT_PALM_ROI_WIDTH, -1);

    ExcuteInterface();

    CheckInterfaceRet(PRDT_PALM_ROI_SIZE_INVALID);
}

