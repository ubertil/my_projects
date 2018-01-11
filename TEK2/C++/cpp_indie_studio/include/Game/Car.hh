//
// Created by uberti_l on 5/22/17.
//

#pragma once
# include <string>
# include <unordered_map>
# include <vector>
# include "Irrlicht/irrlicht.h"
# include "Game/IGameObject.hh"
# include "Input/Controller.hh"
# include "Game/Model.hh"
# include "Game/Circuit.hh"
# include "Game/Camera.hh"
# include "Physic/Physic.hh"

// TODO : GetPowerUP / Set
// TODO : AutoDrive / Drive

namespace Sprint
{
    namespace Game
    {
        class Car : public IGameObject
        {
        public:
            Car(irr::scene::IAnimatedMeshSceneNode  &node);
            Car(const Car &cpy) = delete;
            Car&    operator=(const Car &cpy) = delete;
            ~Car() = default;
            irr::scene::IAnimatedMeshSceneNode  &getNode() const;
            Sprint::Game::Type                  getType() const;
            const float                         getMaxSpeed() const;
            const float                         getSpeed() const;
            void                                reset();
            void                                setSpeed(float);
            void                                subaddSpeed(float);
            void                                incrIndexCheckPoint(std::vector<irr::core::vector3df> &s);
            int                                 getNbLoop() const;
            void                                move(const int i, Sprint::Game::Model m,
                                                     Sprint::Camera::ViewMode v,
                                                     std::vector<std::unique_ptr<Sprint::Input::Controller> > &controllers,
                                                     Circuit *circuit,
                                                     irr::core::vector3df &pos,
                                                     irr::core::vector3df &cam,
                                                     bool z_pressed,
                                                     irr::scene::ISceneManager *sceneManager, Sprint::Physic &physic);
            void                                moveIA(Circuit *circuit);
            void                                setIA(bool);
            int                                 getTotalCheckpoints() const;
        private:
            bool                                IA;
            irr::core::vector3df                init_pos;
            float                               m_maxSpeed;
            float                               m_speed;
            irr::scene::IAnimatedMeshSceneNode  &m_node;
            int                                 index_checkpoint;
            int                                 nb_checkpoint_ranking;
            int                                 index_ranking_ia;
            int                                 nb_loop;
            irr::core::vector3df                acceleration;
            irr::core::vector3df                pos;
            irr::core::vector3df                dir;
        };
    }
}