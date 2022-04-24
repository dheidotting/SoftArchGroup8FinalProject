#include "TopSession.h"
#include "..\LibCore\Observer.h"
#include "..\AppPartOps\DelMeBadPattern.h"


TopSession::TopSession() : m_observerForSavePart(nullptr), m_observerForClosePart(nullptr), m_observerForOpenPart(nullptr)
{

}

TopSession& TopSession::GetInstance()
{
    static TopSession instance;

    return instance;
}

void TopSession::SetupDefaultObservers()
{
    m_observerForSavePart = new Observer(TopSession::GetInstance(), Observer::SaveEntity);
    m_observerForClosePart = new Observer(TopSession::GetInstance(), Observer::CloseEntity);
    m_observerForOpenPart = new Observer(TopSession::GetInstance(), Observer::OpenEntity);

}


TopSession::~TopSession() {
    std::cout << "Goodbye, I was the Top Level Session.\n";
}

/**
 * The subscription management methods.
 */
void TopSession::Attach(IObserver* observer) {
    partObservers.push_back(observer);
}
void TopSession::Detach(IObserver* observer) {
    partObservers.remove(observer);
}
void TopSession::NotifyAll() {
    std::list<IObserver*>::iterator iterator = partObservers.begin();
    HowManyObserver();
    while (iterator != partObservers.end()) {
        (*iterator)->Update(m_message);
        ++iterator;
    }
}

static std::string  GenerateMessageFromEvent(Observer::EventTypes eventType)
{
    std::string retVal;
    if (eventType == Observer::CloseEntity)
    {
        retVal = "Close Part was Called";
    }
    else if (eventType == Observer::OpenEntity)
    {
        retVal = "Open Part was Called";
    }
    else if (eventType == Observer::SaveEntity)
    {
        retVal = "Save Part was Called";
    }
    else if (eventType == Observer::CreateEntity)
    {
        retVal = "Create Part was Called";
    }
    else
    {
        retVal = "Unknown Event Type";
    }

    return retVal;
}



void TopSession::Notify(Observer::EventTypes eventType)
{
    std::string generateMessage = GenerateMessageFromEvent(eventType);

    std::list<IObserver*>::iterator iterator = partObservers.begin();
    HowManyObserver();
    while (iterator != partObservers.end())
    {
        Observer* observer = dynamic_cast<Observer*>(*iterator);
        if (observer != nullptr && observer->UpdateOnEventType(eventType))
        {
            observer->Update(generateMessage);
        }
        ++iterator;
    }
}

void TopSession::Notify(Observer::EventTypes eventType, void* data)
{
    std::string generateMessage = GenerateMessageFromEvent(eventType);

    std::list<IObserver*>::iterator iterator = partObservers.begin();
    HowManyObserver();
    while (iterator != partObservers.end())
    {
        Observer* observer = dynamic_cast<Observer*>(*iterator);
        if (observer != nullptr && observer->UpdateOnEventType(eventType))
        {
            observer->Update(generateMessage, data);
        }
        ++iterator;
    }
}

void TopSession::CreateMessage(Observer::EventTypes eventType)
{
    Notify(eventType);

}

void TopSession::CreateMessage(Observer::EventTypes eventType, void* data)
{
    Notify(eventType, data);

}



void TopSession::CreateMessage(std::string message) {
    this->m_message = message;
    NotifyAll();
}
void TopSession::HowManyObserver() {
    std::cout << "There are " << partObservers.size() << " observers in the list.\n";
}


void TopSession::ClearObservers()
{

}
