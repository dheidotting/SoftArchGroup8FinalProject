#pragma once
#include "LibCore.h"
#include "IObserver.h"
#include "../TopLevelSession/TopSession.h"
// #include "CoreSession.h"  include new session?

class LIBCORE_API Observer : public IObserver
{

public:
    Observer(TopSession& coreSesssion, EventTypes eventType);
    ~Observer() override;
    void Update(const std::string& message_from_subject) override;
    void Update(const std::string& message_from_subject, void* data) override;
    void RemoveMeFromTheList();
    void PrintInfo();
    void PrintInfo(void* data);
    bool UpdateOnEventType(EventTypes eventType);

private:
    std::string message_from_subject_;
    TopSession& topSession_;
    static int static_number_;
    int number_;
    EventTypes m_eventType;

};
