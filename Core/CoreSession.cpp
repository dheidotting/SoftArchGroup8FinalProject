#include "CoreSession.h"
#include "..\LibCore\Observer.h"
#include "..\AppPartOps\DelMeBadPattern.h"


CoreSession::CoreSession() : m_observerForSavePart(nullptr), m_observerForClosePart(nullptr), m_observerForOpenPart(nullptr)
{

}

CoreSession& CoreSession::GetInstance()
{
    static CoreSession instance;

    return instance;
}

void CoreSession::SetupDefaultObservers()
{
    m_observerForSavePart = new Observer(TopSession::GetInstance(), Observer::SaveEntity);
    m_observerForClosePart = new Observer(TopSession::GetInstance(), Observer::CloseEntity);
    m_observerForOpenPart = new Observer(TopSession::GetInstance(), Observer::OpenEntity);

}


CoreSession::~CoreSession() {
    std::cout << "Goodbye, I was the CoreSession.\n";
}

/**
 * The subscription management methods.
 */
void CoreSession::Attach(IObserver* observer)  {
    m_listObserver.push_back(observer);
}
void CoreSession::Detach(IObserver* observer)  {
    m_listObserver.remove(observer);
}
void CoreSession::NotifyAll()  {
    std::list<IObserver*>::iterator iterator = m_listObserver.begin();
    HowManyObserver();
    while (iterator != m_listObserver.end()) {
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



void CoreSession::Notify(Observer::EventTypes eventType) 
{
    std::string generateMessage = GenerateMessageFromEvent(eventType);

    std::list<IObserver*>::iterator iterator = m_listObserver.begin();
    HowManyObserver();
    while (iterator != m_listObserver.end()) 
    {
        Observer* observer = dynamic_cast<Observer*>(*iterator);
        if (observer != nullptr && observer->UpdateOnEventType(eventType))
        {
            observer->Update(generateMessage);
        }
        ++iterator;
    }
}

void CoreSession::Notify(Observer::EventTypes eventType, void * data)
{
    std::string generateMessage = GenerateMessageFromEvent(eventType);

    std::list<IObserver*>::iterator iterator = m_listObserver.begin();
    HowManyObserver();
    while (iterator != m_listObserver.end())
    {
        Observer* observer = dynamic_cast<Observer*>(*iterator);
        if (observer != nullptr && observer->UpdateOnEventType(eventType))
        {
            observer->Update(generateMessage, data);
        }
        ++iterator;
    }
}

void CoreSession::CreateMessage(Observer::EventTypes eventType)
{
    Notify(eventType);

}

void CoreSession::CreateMessage(Observer::EventTypes eventType, void* data)
{
    Notify(eventType, data);

}



void CoreSession::CreateMessage(std::string message ) {
    this->m_message = message;
    NotifyAll();
}
void CoreSession::HowManyObserver() {
    std::cout << "There are " << m_listObserver.size() << " observers in the list.\n";
}


void CoreSession::ClearObservers()
{

}
