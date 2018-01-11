//
// Created by Nicolas on 23/05/17.
//

#include <iostream>
#include "Utils/Random.hpp"
#include "Game/Car.hh"

int                             Sprint::Game::Car::getTotalCheckpoints() const
{
    return (this->nb_checkpoint_ranking);
}

void                            Sprint::Game::Car::setIA(bool ia)
{
    this->IA = ia;
    if (ia == false)
    {
        this->m_maxSpeed = 130;
    }
}

Sprint::Game::Type              Sprint::Game::Car::getType() const
{
    return (Sprint::Game::Type::CAR);
}

void                            Sprint::Game::Car::move(const int i, Sprint::Game::Model m,
                                                        Sprint::Camera::ViewMode v,
                                                        std::vector<std::unique_ptr<Sprint::Input::Controller> > &controllers,
                                                        Sprint::Game::Circuit *circuit,
                                                        irr::core::vector3df &pos,
                                                        irr::core::vector3df &cam,
                                                        bool z_pressed,
                                                        irr::scene::ISceneManager *sceneManager,
                                                        Sprint::Physic &physic)
{
    if (this->IA)
    {
        this->moveIA(circuit);
        return ;
    }
    irr::core::vector3df my_pos;
    irr::core::vector3df my_dir;
    if (v == Sprint::Camera::ViewMode::FIRST_PERSON)
    {
        my_pos = pos;
        my_dir = cam;
    }
    else if (v == Sprint::Camera::ViewMode::TOP_VIEW)
    {
        my_pos = this->pos;
        my_dir = this->dir;
    }
    irr::core::vector3df tmp = controllers.at(0)->mappedAction(i, my_pos, my_dir);
    if (tmp.X != 0 || tmp.Y != 0 || tmp.Z != 0)
        this->acceleration = tmp;
    if (z_pressed)
        this->subaddSpeed(0.5);
    else
        this->subaddSpeed(-this->getSpeed() + (this->getSpeed() / 1.02));
    circuit->checkSpeedBoost(*this);
    circuit->checkSlowBoost(*this);
    circuit->checkGravityBoost(m, *this, physic);
    this->m_node.setPosition(this->m_node.getPosition() + acceleration * this->getSpeed() / 10);
    this->m_node.setRotation(irr::core::vector3df(this->m_node.getRotation().X,
                                                  std::atan2((my_dir.X - my_pos.X), (my_dir.Z - my_pos.Z)) * 57.295779513, this->m_node.getRotation().Z));
    if (circuit->distanceCheckPoint(circuit->getCheckpoint(), this->index_checkpoint, *this) < 6)
    {
        this->incrIndexCheckPoint(circuit->getCheckpoint());
        this->nb_checkpoint_ranking++;
    }
    if (v == Sprint::Camera::ViewMode::FIRST_PERSON)
    {
        sceneManager->addCameraSceneNode(0, this->m_node.getPosition() + irr::core::vector3df(0, 0.3, 0),
                                         this->m_node.getPosition() + (my_dir - my_pos) * 2 + irr::core::vector3df(0, 0.15, 0));
        pos = my_pos;
        cam = my_dir;
    }
    else if (v == Sprint::Camera::ViewMode::TOP_VIEW)
    {
        this->pos = my_pos;
        this->dir = my_dir;
    }
    if (this->index_checkpoint == 0 &&
        this->m_node.getPosition().X >= -26 && this->m_node.getPosition().X <= -25 &&
        this->m_node.getPosition().Z >= 18 && this->m_node.getPosition().Z <= 22)
    {
        this->nb_loop++;
        this->incrIndexCheckPoint(circuit->getCheckpoint());
        this->nb_checkpoint_ranking += 2;
    }
}

void                            Sprint::Game::Car::moveIA(Circuit *circuit)
{
    irr::core::vector3df new_pos = this->m_node.getPosition();
    irr::core::vector3df from = circuit->getCheckpointIA().at((this->index_checkpoint == 0) ? (circuit->getCheckpointIA().size() - 1) : (this->index_checkpoint - 1));
    irr::core::vector3df to = circuit->getCheckpointIA().at((this->index_checkpoint));

    if (to.X != from.X)
    {
        float tX = (this->m_node.getPosition().X - from.X) / (to.X - from.X) + (this->m_maxSpeed * 0.004 / 130);
        if (tX > 1)
            tX = 1;
        if (tX < 0)
            tX = 0;
        float interX = (1 - tX) * from.X + tX * to.X;
        new_pos.X = interX;
    }
    if (to.Y != from.Y)
    {
        float tY = (this->m_node.getPosition().Y - from.Y) / (to.Y - from.Y) + (this->m_maxSpeed * 0.004 / 130);
        if (tY > 1)
            tY > 1;
        if (tY < 0)
            tY = 0;
        float interY = (1 - tY) * from.Y + tY * to.Y;
        new_pos.Y = interY;
    }
    if (to.Z != from.Z)
    {
        float tZ = (this->m_node.getPosition().Z - from.Z) / (to.Z - from.Z) + (this->m_maxSpeed * 0.004 / 130);
        if (tZ > 1)
            tZ = 1;
        if (tZ < 0)
            tZ = 0;
        float interZ = (1 - tZ) * from.Z + tZ * to.Z;
        new_pos.Z = interZ;
    }
    this->m_node.setRotation(irr::core::vector3df(
            this->m_node.getRotation().X,
            std::atan2((new_pos.X - this->m_node.getPosition().X), (new_pos.Z - this->m_node.getPosition().Z)) * 57.295779513,
            this->m_node.getRotation().Z
    ));
    this->m_node.setPosition(new_pos);
    if (circuit->distanceCheckPoint(circuit->getCheckpointIA(), this->index_checkpoint, *this) < 1)
        this->incrIndexCheckPoint(circuit->getCheckpointIA());
    if (circuit->distanceCheckPoint(circuit->getCheckpoint(), this->index_ranking_ia, *this) < 6)
    {
        this->nb_checkpoint_ranking++;
        if (this->index_ranking_ia == circuit->getCheckpoint().size() - 1)
            this->index_ranking_ia = 0;
        else
            this->index_ranking_ia++;
    }
    if (this->index_checkpoint == 0 &&
        this->m_node.getPosition().X >= -27 && this->m_node.getPosition().X <= -24 &&
        this->m_node.getPosition().Z >= 17 && this->m_node.getPosition().Z <= 23)
    {
        this->nb_loop++;
        this->incrIndexCheckPoint(circuit->getCheckpointIA());
        this->nb_checkpoint_ranking += 2;
    }
}

int                             Sprint::Game::Car::getNbLoop() const
{
    return (this->nb_loop);
}

void                            Sprint::Game::Car::reset()
{
    this->nb_loop = -1;
    this->m_speed = 0;
    this->index_checkpoint = 0;
    this->nb_checkpoint_ranking = 0;
    this->index_ranking_ia = 0;
}

void                            Sprint::Game::Car::incrIndexCheckPoint(std::vector<irr::core::vector3df> &s)
{
    if (this->index_checkpoint == s.size() - 1)
        this->index_checkpoint = 0;
    else
        this->index_checkpoint++;
}

void                                Sprint::Game::Car::subaddSpeed(float v)
{
    this->setSpeed(this->getSpeed() + v);
}

const float                           Sprint::Game::Car::getMaxSpeed() const
{
    return (this->m_maxSpeed);
}

const float                           Sprint::Game::Car::getSpeed() const
{
    return (this->m_speed);
}
void                                Sprint::Game::Car::setSpeed(float v)
{
    if (v < 0)
        this->m_speed = 0;
    else
        this->m_speed = v;
    if (this->m_speed > this->m_maxSpeed)
        this->m_speed -= 1;
}

Sprint::Game::Car::Car(irr::scene::IAnimatedMeshSceneNode &node) :
        IA(true), init_pos(-28.5104, 0.563048, 20.0618), m_maxSpeed(130), m_speed(0), m_node(node), index_checkpoint(0), nb_checkpoint_ranking(0), index_ranking_ia(0), nb_loop(-1), pos(0, 10, 0), dir(0.988, 10.15, -0.029)
{
    this->m_node.setMaterialFlag(irr::video::EMF_LIGHTING, false);
    this->m_node.setMD2Animation(irr::scene::EMAT_STAND);
    this->m_node.setPosition({this->init_pos});
    this->m_node.setScale(irr::core::vector3df(0.03, 0.03, 0.03));
    this->m_node.setMaterialFlag(irr::video::EMF_LIGHTING, true);
    this->m_node.addShadowVolumeSceneNode();
    this->m_maxSpeed = Sprint::Utils::Random::getInstance().getNb(50, 130);
}

irr::scene::IAnimatedMeshSceneNode  &Sprint::Game::Car::getNode() const
{
    return (this->m_node);
}