/**
 * @brief ICP project 2015 (Maze game)
 * @authors xmalin26, xmasek15
 */
*/

#ifndef __EventListener__H
#define __EventListener__H

#include "Event.h"
#include <map>

template <typename MapType>
class EventListener {

private:
	std::map<MapType, Event<> *> events;

public:
	EventListener()
	{ }

	virtual ~EventListener()
	{
		for (auto event : this->events) {
			delete event.second;
		}
	}

	template <typename ...Arguments>
	void on(MapType eventType, std::function<void(Arguments...)> function)
	{
		if (this->events.find(eventType) == this->events.end()) { // event does not exist, create new
			this->createEvent < Arguments...>(eventType);
		}

		reinterpret_cast<Event<Arguments...> *>(this->events[eventType])->attach(function);
	}

	template <typename ...Arguments>
	void createEvent(MapType eventType)
	{
		this->events.insert(
				std::pair<MapType, Event<> *>(eventType, reinterpret_cast<Event<> *>(new Event<Arguments...>())));
	}

	template <typename ...Arguments>
	Event<Arguments...> *get(MapType eventType)
	{
		auto iterator = this->events.find(eventType);
		if (iterator == this->events.end()) {
			this->createEvent<Arguments...>(eventType);
			return this->get < Arguments...>(eventType);
		}
		else {
			return reinterpret_cast<Event<Arguments...> *>(iterator->second);
		}
	}

	template <typename ...Arguments>
	void dispatch(MapType eventType, Arguments... params)
	{

		auto iterator = this->events.find(eventType);
		if (iterator != this->events.end()) { // event found
			this->get<Arguments...>(eventType)->dispatch(params...);
		}
	}
};

#endif