//
// Created by uberti_l on 6/17/17.
//

#pragma once
# include "Game/IGameObject.hh"

namespace Sprint
{
    namespace Game
    {
        class BasicModel : public IGameObject
        {
        public:
            BasicModel(irr::scene::IAnimatedMeshSceneNode &node) :
                m_node(node)
            {
                this->m_node.setMaterialFlag(irr::video::EMF_LIGHTING, false);
                this->m_node.setMD2Animation(irr::scene::EMAT_STAND);
                this->m_node.setPosition(irr::core::vector3df(0, 0, 0));
                this->m_node.setScale(irr::core::vector3df(0.03, 0.03, 0.03));
                this->m_node.setMaterialFlag(irr::video::EMF_LIGHTING, true);
                this->m_node.addShadowVolumeSceneNode();
            }
            BasicModel(const BasicModel &cpy) = delete;
            BasicModel&    operator=(const BasicModel &cpy) = delete;
            ~BasicModel() = default;
            irr::scene::IAnimatedMeshSceneNode  &getNode() const
            {
                return (this->m_node);
            }

            Sprint::Game::Type                  getType() const
            {
                return (Sprint::Game::Type::MODEL);
            }
        private:
            irr::scene::IAnimatedMeshSceneNode  &m_node;
        };
    }
}
