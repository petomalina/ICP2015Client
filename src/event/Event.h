/**
 * @brief ICP project 2015 (Maze game)
 * @authors xmalin26, xmasek15
 */


#ifndef __Event__H
#define __Event__H

#include <vector>
#include <functional>
#include <algorithm>
#include <memory>

#include <assert.h>

template <typename ...Arguments>
class Event {

public: // types
	using EventFunction = std::shared_ptr<std::function<void(Arguments...)>>;

private:
	std::vector<std::shared_ptr<std::function<void(Arguments...)>>> listeners;

public:
	Event()
	{ }

	~Event()
	{
		for (auto callback : this->listeners) {
			callback.reset();
		}
	}

	virtual void dispatch(Arguments... params)
	{
		for (auto callback : this->listeners) {
			callback->operator()(params...);
		}
	}

	// lambda function attach
	EventFunction attach(std::function<void(Arguments...)> function)
	{
		auto listener = EventFunction(new std::function<void(Arguments...)>(function));

		return this->attach(listener);
	}

	// overload operator for attaching lambdas
	Event &operator()(std::function<void(Arguments...)> function)
	{
		this->attach(function);

		return *this;
	}

	EventFunction attach(EventFunction listener)
	{
		this->listeners.push_back(listener);

		return listener;
	}

	// overload operator for attaching
	Event &operator()(EventFunction listener)
	{
		this->attach(listener);

		return *this;
	}

	// overload operator for dispatch
	Event &operator()(Arguments ...params)
	{
		this->dispatch(params...);
	}

	void detach(EventFunction listener)
	{
		auto iterator = std::find(this->listeners.begin(), this->listeners.end(), listener);

		assert(iterator != this->listeners.end());

		this->listeners.erase(iterator);
	}
};

#endif