#pragma once
#include <list>
#include "Observer.h"
class Subject
{
	std::list<Observer*> observers;
public:
	enum ObserverEvent {

		ACTIVATE,
		SUBJECT_DEATH
	};
	Subject();
	~Subject();
	void Attach(ObserverEvent* entity);
	void Detach();
	void NotifyObservers(ObserverEvent entity);

};