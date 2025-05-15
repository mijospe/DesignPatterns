#pragma once
#include <functional>
#include <iostream>
#include <vector>

class Event
{
private:
	// The listeners for the event call
	std::vector<std::function<void()>> listeners;

public:
	// Subscribe a function to the event
	void SubscribeToEvent(std::function<void()> callback);
	// Invoke the listener
	void Invoke();
};

