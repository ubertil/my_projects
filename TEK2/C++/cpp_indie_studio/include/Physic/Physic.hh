//
// Created by Nicolas on 31/05/17.
//

#pragma once
# include <vector>
# include <unordered_map>
# include "Game/Model.hh"

namespace Sprint
{
    class Physic
    {
    private:
        irr::scene::ISceneManager                           &_sceneManager;
        std::unordered_map<Sprint::Game::Model, irr::scene::ISceneNodeAnimatorCollisionResponse *>anim;
        std::vector<irr::scene::IMetaTriangleSelector *>    metaSelector;
        std::vector<irr::scene::ITriangleSelector*>         selector;
        std::vector<Sprint::Game::Model>                    disabled_collisions;
    public:
        Physic(irr::scene::ISceneManager &sceneManager);
        Physic(const Physic &cpy) = delete;
        Physic& operator=(const Physic &cpy) = delete;
        void addElem(Sprint::Game::Model m, irr::scene::IAnimatedMesh &, irr::scene::IAnimatedMeshSceneNode &, irr::scene::IAnimatedMeshSceneNode &);
        ~Physic() = default;
        void    lockGravity();
        void    unlockGravity();
        void    setGravity(irr::core::vector3df newG);
        void    setCarGravity(Sprint::Game::Model m, irr::core::vector3df newG);
        irr::core::vector3df getGravity(Sprint::Game::Model m) const;
        void    disableCollision(irr::scene::IAnimatedMeshSceneNode &nodb, Sprint::Game::Model m);
    };
}