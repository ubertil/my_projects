//
// Created by Nicolas on 23/03/17.
//

#pragma once
# include <stdint.h>

namespace arcade
{
    enum class Event : uint16_t
    {
	NOTHING = 0,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	MENU,
	PAUSE,
	PLUS,
	MINUS,
	QUIT,
	ENTER,
	BACK,
	RESTART,
	NEXT_GAME,
	NEXT_LIB,
	PREV_GAME,
	PREV_LIB,
    };
};
