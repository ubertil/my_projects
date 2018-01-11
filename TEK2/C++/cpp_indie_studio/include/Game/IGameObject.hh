//
// Created by Nicolas on 24/05/17.
//

#pragma once
# include <stdint.h>
# include "Irrlicht/IAnimatedMeshSceneNode.h"

namespace Sprint
{
    namespace Game
    {
        enum class Type : uint16_t
        {
            CIRCUIT = 0,
            CAR,
            MODEL
        };

        class IGameObject
        {
        public:
            virtual irr::scene::IAnimatedMeshSceneNode  &getNode() const = 0;
            virtual Sprint::Game::Type                  getType() const = 0;
            virtual ~IGameObject() = default;
        };
    }
}