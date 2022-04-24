#pragma once
#include "TopLevelSession.h"
#include "../Core/ISubject.h"
#include <list>
#include <iostream>
#include "../LibCore/IObserver.h"
#include "../AppPartOps/PartObserver.h"

class Observer;

class TOPLEVELSESSION_API TopSession : ISubject
{
public:
    static TopSession& GetInstance();

    TopSession(TopSession const&) = delete;
    void operator=(TopSession const&) = delete;


    ~TopSession() override;

    /**
     * The subscription management methods.
     */
    void Attach(IObserver* observer) override;
    void Detach(IObserver* observer) override;
    void NotifyAll() override;
    void Notify(IObserver::EventTypes eventType) override;
    void Notify(IObserver::EventTypes eventType, void* data) override;

    void CreateMessage(IObserver::EventTypes eventType);
    void CreateMessage(IObserver::EventTypes eventType, void* data);
    void CreateMessage(std::string message = "Empty");
    void HowManyObserver();

    void ClearObservers();

    void SetupDefaultObservers();

private:
    std::list<IObserver*> partObservers;
    // add another observer type list
    std::string m_message;
    TopSession();


    Observer* m_observerForSavePart;
    Observer* m_observerForClosePart;
    Observer* m_observerForOpenPart;

};