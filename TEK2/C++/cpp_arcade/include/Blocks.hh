//
// Created by Nicolas on 06/04/17.
//

#pragma once
# include <stdint.h>

namespace arcade
{
  enum class BlockType : uint16_t
    {
      EMPTY,
      WALL,
      SNAKE,
      PACMAN,
      COIN,
      GHOST_1,
      GHOST_2,
      GHOST_3,
      GHOST_4,
      GOD_MODE,
      POWERUP_1,
      POWERUP_2,
      POWERUP_3
    };
};
