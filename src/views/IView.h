//
// Created by gelidus on 7.5.2015.
//

#ifndef ICP2015CLIENT_IVIEW_H
#define ICP2015CLIENT_IVIEW_H

#include "../event/Event.h"

enum class Rotation {
	Up, Down, Left, Right
};

enum class FragmentType {
	T, L, I
};

class IView {

public:
	virtual void initialize() = 0;
	virtual void show() = 0;

public:
	// rotation of character
	Event<Rotation> onCharacterMove;
	// index and what type
	Event<int, FragmentType, Rotation> onFragmentPlace;
	// number of players, size of playground
	Event<int, int> onGameStart;

	Event<> onUndo;

	Event<> onRedo;

	Event<> onSave;
};


#endif //ICP2015CLIENT_IVIEW_H
