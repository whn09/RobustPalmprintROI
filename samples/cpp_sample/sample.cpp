#include <prdt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

void PrintUsage()
{
    printf("Usage:\t./sample -i image\n");
    printf("e.g.\t./sample -i ./palm_test_data/palm_image.jpg\n");
}

bool CheckOptions(int argc, char** argv)
{
    if (argc < 3)
    {
        PrintUsage();
        return false;
    }
    return true;
}


int main(int argc, char** argv)
{
    const char* palmprint_image_path = NULL;
    int i = 1;
    while (i < argc)
    {
        if (strcmp(argv[i], "-i") == 0)
        {
            palmprint_image_path = argv[++i];
        }
        ++i;
    }
    cv::Size roiSize;
    roiSize.width = 1200;
    roiSize.height = 1200;
    cv::Mat palmRoi;
    int ret = GetPalmROIByPath(palmprint_image_path, roiSize, palmRoi);

    vector<int> compression_params;
    compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
    compression_params.push_back(0); // 0-9
    try {
        cv::imwrite("tmp.png", palmRoi, compression_params);
    }
    catch (runtime_error& ex) {
    }
}

