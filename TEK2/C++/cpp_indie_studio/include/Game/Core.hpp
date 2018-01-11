//
// Created by uberti_l on 5/23/17.
//

#pragma once
# include <vector>
# include <memory>
# include "Irrlicht/irrlicht.h"
# include "Input/Controller.hh"
# include "Game/IGameObject.hh"
# include "Game/Camera.hh"
# include "Game/Model.hh"
# include "Physic/Physic.hh"
# include "GUI/ATH.hh"
# include "GUI/Menu.hh"
# include "Utils/IniManager.hpp"
# include "Utils/Dir.hpp"
# include "Loader/RessourceLoader.hh"
# include "Sound/Manager.hh"
# include "Sound/Source.hh"
# include "Language.hpp"

namespace Sprint
{
    namespace Game
    {
        class Core
        {
        public:
            Core(bool dev_mode);
            Core(const Core &cpy) = delete;
            Core    &operator=(const Core &cpy) = delete;
            ~Core();

            void    run();
            void    splashScreen();

        private:
            void    showFPS() const;
            void    loadCars();
            void    loadDecoration();
            void    setDecoration();
            void    loadPhysic();
            void    reset();
            void    loadSounds();
            void    setLightning();
            void    unloadResources(Sprint::Game::Model model = Sprint::Game::Model::ALL);

            template <typename T>
            void    loadModel(Sprint::Game::Model model, const std::string &path)
            {
                Sprint::Utils::Dir          dir(path);
                std::vector<std::string>    mesh_files = dir.getFiles(-1, "*.obj");

                for (const std::string &file : mesh_files)
                {
                    this->meshes[model] = Sprint::ResourceManager::Load<irr::scene::IAnimatedMesh>(*this->driver, *this->sceneManager, file);
                    this->meshes.at(model)->grab();
                    this->objs[model] = std::make_unique<T>(*this->sceneManager->addAnimatedMeshSceneNode(this->meshes.at(model)));
                    this->objs.at(model)->getNode().grab();
                }
            }

            void    loadSkyBox(const std::string &path);
            void    moveCars();
            bool    isGameOver();
            void    displayRanking();

            Sprint::Camera::ViewMode                                                                viewMode;
            bool                                                                                    devMode;
            bool                                                                                    splitScreen;
            bool                                                                                    inMenu;
            bool                                                                                    needReset;
            int                                                                                     nbPlayers;
            int                                                                                     nbLap;
            int                                                                                     FPS;
            irr::scene::IBillboardSceneNode                                                         *logo;
            std::unique_ptr<Sprint::Utils::IniManager>                                              iniManager;
            std::unique_ptr<Sprint::Sound::Manager>                                                 soundManager;
            std::unique_ptr<Sprint::Input::EventReceiver>                                           eventReceiver;
            std::unique_ptr<Sprint::GUI::Menu>                                                      menu;
            std::unique_ptr<Sprint::GUI::ATH>                                                       ATH;
            std::unique_ptr<Sprint::Language>                                                       language;
            std::unique_ptr<Sprint::Physic>                                                         physicEngine;
            irr::core::vector3df                                                                    menuPos;
            irr::core::vector3df                                                                    menuCam;
            irr::core::vector3df                                                                    pos;
            irr::core::vector3df                                                                    cam;
            irr::IrrlichtDevice	                                                                    *device;
            irr::video::IVideoDriver                                                                *driver;
            irr::scene::ISceneManager                                                               *sceneManager;
            std::string                                                                             font;
            std::unordered_map<Sprint::Game::Model, irr::scene::IAnimatedMesh *>                    meshes;
            std::unordered_map<Sprint::Game::Model, std::unique_ptr<Sprint::Game::IGameObject> >    objs;
            std::vector<std::pair<Sprint::Game::Model, int> >                                       ranking;
            scene::ISceneNode                                                                       *skybox;
            std::vector<std::unique_ptr<Sprint::Sound::Source> >                                    sounds;
            std::vector<std::unique_ptr<Sprint::Input::Controller> >                                controllers;
            Sprint::Game::Model                                                                     playersCar[4];
        };
    }
}