/*************************************************************************
> File Name: PRDT.h
> Author: Leosocy
> Mail: 513887568@qq.com
> Created Time: 2018/1/7 18:36:32
************************************************************************/

#ifndef __ADAPTER_LAYER_H__
#define __ADAPTER_LAYER_H__

#include <PRDT.h>

namespace PRDT
{
    class PalmAdapter
    {
    public:
        void SetResultCallBack(ResultCallBackFunc func) { this->resultCallBackHandler = func; }
        void SetStateCallBack(StateCallBackFunc func) { this->stateCallBackHandler = func; }
    protected:
    private:
        ResultCallBackFunc resultCallBackHandler;
        StateCallBackFunc stateCallBackHandler;
    };
}

#endif // !__ADAPTER_LAYER_H__
