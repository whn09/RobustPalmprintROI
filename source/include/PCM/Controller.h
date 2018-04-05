#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "prdt.h"

namespace prdt
{

class Palm;
class PalmDetector;
class PreProcessor;

class Controller 
{
public:
    Controller();
    ~Controller();

    void set_result_call_back_handler(ResultCallBackFunc func) { result_call_back_handler_ = func; }
    void set_state_call_back_handler(StateCallBackFunc func) { state_call_back_handler_ = func; }
    ResultCallBackFunc result_call_back_handler() { return result_call_back_handler_; }
    StateCallBackFunc state_call_back_handler() { return state_call_back_handler_; }

    void InjectPalm(const Palm &palm_instance);
protected:
private:
    bool MallocPalmData();
    void FreePalmData();

    ResultCallBackFunc result_call_back_handler_;
    StateCallBackFunc state_call_back_handler_;

    Palm *palm_;
    PalmDetector *detector_;
    PreProcessor *preprocessor_;
};

} // namespace prdt

#endif // !__CONTROLLER_H__
