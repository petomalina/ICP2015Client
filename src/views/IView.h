//
// Created by gelidus on 5.5.2015.
//

#pragma once

enum class ViewState {
	Menu,
	Game
};

class IView {

public:
	virtual void initialize() = 0;

	virtual void show() = 0;

	virtual void generateMap() = 0;
};