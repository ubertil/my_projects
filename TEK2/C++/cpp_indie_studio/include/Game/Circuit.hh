//
// Created by come on 23/05/17.
//

#pragma once
# include <memory>
# include <vector>
# include <string>
# include "Irrlicht/irrlicht.h"
# include "Physic/Physic.hh"
# include "Game/IGameObject.hh"

namespace Sprint
{
    namespace Game
    {
        class Car;

        class Circuit : public IGameObject
        {
        private:
            irr::scene::IAnimatedMeshSceneNode      &m_node;
            std::vector<irr::core::vector3df>       checkpoint;
            std::vector<irr::core::vector3df>       checkpoint_ia;
            std::vector<irr::core::vector3df>       speed_boost;
            std::vector<irr::core::vector3df>       gravity_boost;
            std::vector<irr::core::vector3df>       slow_boost;
        public:
            Circuit(irr::scene::IAnimatedMeshSceneNode &node);
            ~Circuit() = default;

            irr::scene::IAnimatedMeshSceneNode      &getNode() const;
            Sprint::Game::Type                      getType() const;
            double                                  distanceCheckPoint(std::vector<irr::core::vector3df> &s, int index, Sprint::Game::Car &car);
            void                                    checkSpeedBoost(Sprint::Game::Car &car);
            void                                    checkSlowBoost(Sprint::Game::Car &car);
            void                                    checkGravityBoost(Sprint::Game::Model m, Sprint::Game::Car &car, Sprint::Physic &physic);
            std::vector<irr::core::vector3df>       &getCheckpoint();
            std::vector<irr::core::vector3df>       &getCheckpointIA();
        };
    }
}