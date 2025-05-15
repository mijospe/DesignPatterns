#include "Event.h"

void Event::SubscribeToEvent(std::function<void()> callback)
{
	// Add Listener to the list of Listeners
	listeners.push_back(callback);
}

void Event::Invoke()
{
	// Loop trough each Listener and execute the Listener
	for (std::function<void()>& listener : listeners) {
		listener();
	}
}