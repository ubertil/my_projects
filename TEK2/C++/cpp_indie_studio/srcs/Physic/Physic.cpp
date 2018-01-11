//
// Created by Nicolas on 31/05/17.
//

#include <iostream>
#include <Irrlicht/irrlicht.h>
#include "Physic/Physic.hh"
#include "Game/Model.hh"

void    Sprint::Physic::disableCollision(irr::scene::IAnimatedMeshSceneNode &nodb,
                                        Sprint::Game::Model m)
{
    nodb.removeAnimator(this->anim.at(m));
    this->disabled_collisions.push_back(m);
}

void    Sprint::Physic::setCarGravity(Sprint::Game::Model m,
                                       irr::core::vector3df newG)
{
    int found = 0;

    for (auto const &e : this->disabled_collisions)
    {
        if (e == m)
            found = 1;
    }
    if (found == 0)
        this->anim.at(m)->setGravity(newG);
}


void    Sprint::Physic::setGravity(irr::core::vector3df newG)
{
    int found;

    for (auto const &e : this->anim)
    {
        found = 0;
        for (auto const &b : this->disabled_collisions)
        {
            if (b == e.first)
                found = 1;
        }
        if (found == 0)
            e.second->setGravity(newG);
    }
}

irr::core::vector3df Sprint::Physic::getGravity(Sprint::Game::Model m) const
{
    return (this->anim.at(m)->getGravity());
}

void    Sprint::Physic::lockGravity()
{
    int found;

    for (auto const &e : this->anim)
    {
        found = 0;
        for (auto const &b : this->disabled_collisions)
        {
            if (b == e.first)
                found = 1;
        }
        if (found == 0)
            e.second->setGravity(irr::core::vector3df(0, 0, 0));
    }
}

void    Sprint::Physic::unlockGravity()
{
    int found;

    for (auto const &e : this->anim)
    {
        found = 0;
        for (auto const &b : this->disabled_collisions)
        {
            if (b == e.first)
                found = 1;
        }
        if (found == 0)
            e.second->setGravity(irr::core::vector3df(0, -0.4, 0));
    }
}

void    Sprint::Physic::addElem(Sprint::Game::Model m,
                                irr::scene::IAnimatedMesh &mesha,
                                irr::scene::IAnimatedMeshSceneNode &noda,
                                irr::scene::IAnimatedMeshSceneNode &nodb)
{
    this->metaSelector.emplace_back(this->_sceneManager.createMetaTriangleSelector());
    this->selector.emplace_back(this->_sceneManager.createOctTreeTriangleSelector(&mesha, &noda));
    this->metaSelector.back()->addTriangleSelector(this->selector.back());
    const irr::core::aabbox3d<irr::f32> &box = nodb.getBoundingBox();
    irr::core::vector3df radius = (box.MaxEdge - box.getCenter());
    radius.X *= 0.03 * 0.5;
    radius.Y *= 0.03 * 0.5;
    radius.Z *= 0.03 * 0.5;
    this->anim[m] = this->_sceneManager.createCollisionResponseAnimator(this->metaSelector.back(), &nodb, radius, irr::core::vector3df(0, 0, 0));
    nodb.addAnimator(this->anim.at(m));
    this->anim.at(m)->drop();
    this->unlockGravity();
}

Sprint::Physic::Physic(irr::scene::ISceneManager &sceneManager) : _sceneManager(sceneManager)
{
}