/*************************************************************************
> File Name: Controller.h
> Author: Leosocy
> Mail: 513887568@qq.com
> Created Time: 2018/1/7 18:36:32
************************************************************************/

#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <PRDT.h>
#include <Palm.h>

namespace PRDT
{
    class Controller
    {
    public:
        Controller();
        ~Controller();

        void SetResultCallBack(ResultCallBackFunc func) { this->resultCallBackHandler = func; }
        void SetStateCallBack(StateCallBackFunc func) { this->stateCallBackHandler = func; }
        void RegisterPalm(const Palm &instance);
    protected:
    private:
        ResultCallBackFunc resultCallBackHandler;
        StateCallBackFunc stateCallBackHandler;

        Palm *palm;

        bool MallocPalmData();
        void FreePalmData();
    };
}

#endif // !__CONTROLLER_H__
