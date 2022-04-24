#pragma once
#include "LibCore.h"
#include <string>

class LIBCORE_API IObserver {
public:
    enum EventTypes
    {
        SaveEntity = 0,
        OpenEntity = 1,
        CloseEntity = 2,
        CreateEntity = 4
    };

    virtual ~IObserver() {};
    virtual void Update(const std::string& message_from_subject) = 0;
    virtual void Update(const std::string& message_from_subject, void* data) = 0;
};