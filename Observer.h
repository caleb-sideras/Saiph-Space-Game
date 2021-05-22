#pragma once
enum ObserverEvent {
	ACTIVATE,
	SUBJECT_DEATH
};
class Observer
{
public:
	virtual void Notification(ObserverEvent observerEvent) = 0;

};