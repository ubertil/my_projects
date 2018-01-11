//
// Created by uberti_l on 5/23/17.
//

#include "Font/CGUITTFont.hpp"
#include "Game/BasicModel.hpp"
#include "Game/Car.hh"
#include "Game/Core.hpp"

Sprint::Game::Core::Core(bool dev_mode) :
        viewMode(Sprint::Camera::ViewMode::FIRST_PERSON), devMode(dev_mode), splitScreen(false), inMenu(true), needReset(false),
        nbPlayers(1), nbLap(3), FPS(60), menuPos(-10, 10, 0), menuCam(0, 0, 0), pos(0, 10, 0), cam(0.988, 10.15, -0.029)
{
    Sprint::Utils::Dir          conf_dir("../config/");
    Sprint::Utils::Dir          logo_dir("../resources/misc/logo");
    Sprint::Utils::Dir          font_dir("../resources/misc/font");
    std::vector<std::string>    files;

    files = font_dir.getFiles(1, "*.ttf");
    if (files.size() != 1)
        throw Sprint::Error::GameError("Could not load main font");
    this->font = files.at(0);
    files = conf_dir.getFiles(1, "*.ini");
    if (files.size() != 1)
        throw Sprint::Error::GameError("Couldn't load configuration file");
    this->iniManager = std::make_unique<Sprint::Utils::IniManager>(files.at(0));
    files = logo_dir.getFiles(1, "*.png");
    if (files.size() != 1)
        throw Sprint::Error::GameError("Couldn't load game logo");
    this->eventReceiver = std::make_unique<Sprint::Input::EventReceiver>();
    this->soundManager = std::make_unique<Sprint::Sound::Manager>();
    this->loadSounds();
    this->controllers.emplace_back(std::make_unique<Sprint::Input::Controller>(*this->eventReceiver.get(), 5., 0.035));
    this->device = irr::createDevice(irr::video::EDT_OPENGL,
                                     irr::core::dimension2du(this->iniManager->getData<int>("window", "width", 0),
                                                             this->iniManager->getData<int>("window", "height", 0)), 32,
                                     this->iniManager->getData<bool>("window", "fullscreen", 0), true,
                                     this->iniManager->getData<bool>("window", "vsync", 0), this->eventReceiver.get());
    this->device->getCursorControl()->setVisible(false);
    if (!dev_mode)
    {
        this->device->setResizable(true);
        this->device->getLogger()->setLogLevel(irr::ELL_ERROR);
    }
    else
        this->device->setResizable(false);
    this->device->setWindowCaption(L"Hyper Sprint");
    this->driver = device->getVideoDriver();
    this->sceneManager = device->getSceneManager();
    this->language = std::make_unique<Sprint::Language>(*this->device, this->iniManager->getData<std::string>("settings", "language", 0));
    this->physicEngine = std::make_unique<Sprint::Physic>(*this->sceneManager);
    this->setLightning();
    this->loadCars();
    this->loadDecoration();
    this->loadModel<Sprint::Game::Circuit>(Sprint::Game::Model::LUIGI_CIRCUIT, "../resources/tracks/LuigiCircuit");
    this->loadPhysic();
    this->logo  = this->sceneManager->addBillboardSceneNode(0, irr::core::dimension2d<irr::f32>(10.0f, 10.0f));
    this->logo->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    this->logo->setMaterialTexture(0, this->driver->getTexture(files.at(0).c_str()));
    this->logo->setMaterialType(irr::video::EMT_TRANSPARENT_ALPHA_CHANNEL_REF);
    if (this->driver->getScreenSize().Width == 800)
        this->logo->setPosition(irr::core::vector3df(0, 0, 6));
    else
        this->logo->setPosition(irr::core::vector3df(0, 0, 3));
    this->ATH = std::make_unique<Sprint::GUI::ATH>(*this->device, *this->language.get(), this->font);
    this->menu = std::make_unique<Sprint::GUI::Menu>(*this->device, this->sounds, this->objs, *this->iniManager.get(), *this->language.get(), this->font, this->nbPlayers,
                                                     this->playersCar);
    this->loadSkyBox("../resources/misc/skybox");
}

Sprint::Game::Core::~Core()
{
    this->device->drop();
}

void		        Sprint::Game::Core::setLightning()
{
    this->sceneManager->setAmbientLight(irr::video::SColorf(0.5, 0.5, 0.5, 1));
    this->sceneManager->addLightSceneNode(0, irr::core::vector3df(0, 100, 0), irr::video::SColorf(0.8, 0.8, 0.8, 0.0), 200.0);
}

void                Sprint::Game::Core::loadPhysic()
{
    for (auto const &car : this->objs)
    {
        if (car.second->getType() == Sprint::Game::Type::CAR)
            this->physicEngine->addElem(car.first, *this->meshes.at(Sprint::Game::Model::LUIGI_CIRCUIT),
                                        this->objs.at(Sprint::Game::Model::LUIGI_CIRCUIT)->getNode(),
                                        car.second->getNode());
    }
}

void                Sprint::Game::Core::loadSounds()
{
    Sprint::Utils::Dir          dir("../resources/sounds");
    std::vector<std::string>    files = dir.getFiles(1, "*.wav");
    float                       volume = this->iniManager->getData<float>("settings", "volume", 0);

    std::sort(files.begin(), files.end());
    if (files.size() != 8)
        throw Sprint::Error::SoundError("Missing sounds file");
    for (const std::string &file : files)
    {
        this->sounds.emplace_back(std::make_unique<Sprint::Sound::Source>(this->soundManager->loadSound(file)));
        this->sounds.back()->setVolume(volume);
    }
}

void                Sprint::Game::Core::loadCars()
{
    this->loadModel<Sprint::Game::Car>(Sprint::Game::Model::MARIO_KART, "../resources/cars/MarioKart");
    this->loadModel<Sprint::Game::Car>(Sprint::Game::Model::PEACH_KART, "../resources/cars/PeachKart");
    this->loadModel<Sprint::Game::Car>(Sprint::Game::Model::WARIO_KART, "../resources/cars/WarioKart");
    this->loadModel<Sprint::Game::Car>(Sprint::Game::Model::LUIGI_KART, "../resources/cars/LuigiKart");
    this->loadModel<Sprint::Game::Car>(Sprint::Game::Model::BOWSER_KART, "../resources/cars/BowserKart");
    this->loadModel<Sprint::Game::Car>(Sprint::Game::Model::TOAD_KART, "../resources/cars/ToadKart");
    this->loadModel<Sprint::Game::Car>(Sprint::Game::Model::YOSHI_KART, "../resources/cars/YoshiKart");
}

void                Sprint::Game::Core::loadDecoration()
{
    this->loadModel<Sprint::Game::BasicModel>(Sprint::Game::Model::REFEREE, "../resources/misc/decorations/Lakitu");
    this->loadModel<Sprint::Game::BasicModel>(Sprint::Game::Model::STATUE, "../resources/misc/decorations/Statue");
    this->loadModel<Sprint::Game::BasicModel>(Sprint::Game::Model::ZEPPELIN, "../resources/misc/decorations/Zeppelin");
}

void                Sprint::Game::Core::loadSkyBox(const std::string &path)
{
    Sprint::Utils::Dir          dir(path);
    std::vector<std::string>    mesh_files = dir.getFiles(-1, "*.tga");

    if (mesh_files.size() != 6)
        throw Sprint::Error::GameError("Missing files for skybox");
    std::sort(mesh_files.begin(), mesh_files.end());
    this->driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, false);
    this->skybox = this->sceneManager->addSkyBoxSceneNode(this->driver->getTexture(mesh_files.at(0).c_str()),
                                                          this->driver->getTexture(mesh_files.at(1).c_str()),
                                                          this->driver->getTexture(mesh_files.at(2).c_str()),
                                                          this->driver->getTexture(mesh_files.at(3).c_str()),
                                                          this->driver->getTexture(mesh_files.at(4).c_str()),
                                                          this->driver->getTexture(mesh_files.at(5).c_str()));
}

void                Sprint::Game::Core::showFPS() const
{
    irr::core::stringw tmp = L"Hyper Sprint | FPS: ";

    tmp += this->driver->getFPS();
    tmp += L" | Triangles: ";
    tmp += this->driver->getPrimitiveCountDrawn();
    this->device->setWindowCaption(tmp.c_str());
}

void                Sprint::Game::Core::unloadResources(Sprint::Game::Model model)
{
    if (model == Sprint::Game::Model::ALL)
    {
        for (auto const &mesh : this->meshes)
            mesh.second->drop();
        for (auto const &obj : this->objs)
        {
            obj.second->getNode().remove();
            obj.second->getNode().drop();
        }
        this->meshes.clear();
        this->objs.clear();

    }
    else if (objs.find(model) != objs.end() && meshes.find(model) != meshes.end())
    {
        this->objs.at(model)->getNode().remove();
        this->objs.at(model)->getNode().drop();
        this->meshes.at(model)->drop();
        this->meshes.erase(model);
        this->objs.erase(model);
    }
}

void                Sprint::Game::Core::moveCars()
{
    static irr::core::vector3df carCam[4] = { this->cam };
    static irr::core::vector3df carPos[4] = { this->pos };
    bool                        keyStates[4] = { this->eventReceiver->isPressed(irr::EKEY_CODE::KEY_KEY_Z),
                                                 this->eventReceiver->isPressed(irr::EKEY_CODE::KEY_KEY_I),
                                                 this->eventReceiver->isPressed(irr::EKEY_CODE::KEY_UP),
                                                 this->eventReceiver->getJoystickState().IsButtonPressed(0)
                                                };

    for (int i = 0; i < 4; ++i)
    {
        dynamic_cast<Sprint::Game::Car *>(this->objs.at(this->playersCar[i]).get())->move(i, this->playersCar[i], this->viewMode, this->controllers,
                                                                                          dynamic_cast<Sprint::Game::Circuit *>(this->objs.at(Sprint::Game::Model::LUIGI_CIRCUIT).get()),
                                                                                          carPos[i], carCam[i], keyStates[i], this->sceneManager, *this->physicEngine.get());
    }
}

void                Sprint::Game::Core::displayRanking()
{
    while (this->ranking.size() > 0)
        this->ranking.pop_back();
    for (int i = 0; i < 4; ++i)
    {
        int nbc = dynamic_cast<Sprint::Game::Car *>(this->objs.at(this->playersCar[i]).get())->getTotalCheckpoints();
        this->ranking.emplace_back(std::make_pair(this->playersCar[i], nbc));
    }
    std::sort(this->ranking.begin(), this->ranking.end(), [](std::pair<Sprint::Game::Model, int> a, std::pair<Sprint::Game::Model, int> b){
        return (a.second > b.second);
    });
}

bool                Sprint::Game::Core::isGameOver()
{
    irr::gui::CGUITTFont                    *tt_font;
    irr::core::ustring                      translated;
    const irr::core::dimension2d<irr::u32>  winDim = this->driver->getScreenSize();
    unsigned int                            font_size = 90;
    Sprint::Game::Model                     winner = Sprint::Game::Model::ALL;
    int                                     rot = 0;

    for (auto const &car : this->objs)
    {
        if (car.second->getType() == Sprint::Game::Type::CAR)
            if (dynamic_cast<Sprint::Game::Car *>(car.second.get())->getNbLoop() >= this->nbLap)
                winner = car.first;
    }
    if (winner == Sprint::Game::Model::ALL)
        return (false);
    this->sounds.at(Sprint::Sound::Song::RACE_THEME)->stop();
    this->sceneManager->addCameraSceneNode(0, irr::core::vector3df(0, 5, 0), irr::core::vector3df(-7.57135, 0, 0.847953));
    this->reset();
    this->objs.at(winner).get()->getNode().setPosition(irr::core::vector3df(-7.57135, 1.86, 0.847953));
    this->physicEngine->lockGravity();
    this->objs.at(winner).get()->getNode().setScale(irr::core::vector3df(0.06, 0.06, 0.06));
    tt_font = irr::gui::CGUITTFont::createTTFont(this->device->getGUIEnvironment(), this->font.c_str(), font_size);
    this->sounds.at(Sprint::Sound::Song::VICTORY_SOUND)->play();
    this->objs.at(Sprint::Game::Model::STATUE)->getNode().setVisible(false);
    while (this->device->run() && !this->eventReceiver->isPressed(irr::KEY_ESCAPE))
    {
        if (this->devMode)
            this->showFPS();
        this->driver->beginScene(true, true, irr::video::SColor(255, 255, 255, 255));
        this->objs.at(winner).get()->getNode().setRotation(irr::core::vector3df(this->objs.at(winner).get()->getNode().getRotation().X, rot++, this->objs.at(winner).get()->getNode().getRotation().Z));
        this->sceneManager->drawAll();
        translated = this->language->getTranslation("Winner");
        tt_font->draw(translated.c_str(), irr::core::rect<irr::s32>((winDim.Width / 100 * 50) - ((translated.size() * font_size) / 2), (winDim.Height / 100) * (50 + (font_size / 10) + 1), 200, 200),
                      irr::video::SColor(255, 255, 0, 0), false, false);
        this->driver->endScene();
    }
    for (auto const &car : this->objs)
        if (car.second->getType() == Sprint::Game::Type::CAR)
            dynamic_cast<Sprint::Game::Car *>(car.second.get())->reset();
    this->menu->reset();
    this->reset();
    this->menu->setInMenu();
    tt_font->drop();
    return (true);
}

void                Sprint::Game::Core::reset()
{
    if (this->needReset)
    {
        this->logo->setVisible(false);
        this->sounds.at(Sprint::Sound::Song::RACE_THEME)->setLooping(true);
        this->sounds.at(Sprint::Sound::Song::RACE_THEME)->play();
        for (auto const &obj : this->objs)
        {
            if (obj.second->getType() == Sprint::Game::Type::CAR)
                dynamic_cast<Sprint::Game::Car *>(obj.second.get())->reset();
            obj.second->getNode().setVisible(false);
            obj.second->getNode().setPosition(irr::core::vector3df(-27.636, 0.50, 20.1));
            obj.second->getNode().setScale(irr::core::vector3df(0.03, 0.03, 0.03));
            obj.second->getNode().setRotation(irr::core::vector3df(0, 0, 0));
        }
        this->objs.at(Sprint::Game::Model::LUIGI_CIRCUIT)->getNode().setVisible(true);
        this->objs.at(Sprint::Game::Model::LUIGI_CIRCUIT)->getNode().setPosition(irr::core::vector3df(0, 0, 0));
        this->objs.at(Sprint::Game::Model::LUIGI_CIRCUIT)->getNode().setScale(irr::core::vector3df(1, 1, 1));
        this->sounds.at(Sprint::Sound::Song::MAIN_THEME)->stop();
        this->physicEngine->unlockGravity();
        if (this->nbPlayers == 1)
        {
            this->viewMode = Sprint::Camera::ViewMode::FIRST_PERSON;
            this->pos = irr::core::vector3df(0, 10, 0);
            this->cam = irr::core::vector3df(0.988, 10.15, -0.029);
        }
        else
        {
            this->viewMode = Sprint::Camera::ViewMode::TOP_VIEW;
            this->pos = irr::core::vector3df(-20, 32, 3);
            this->cam = irr::core::vector3df(-20, 0, 2);
        }
        for (int i = 0; i < 4; ++i)
        {
            this->objs.at(this->playersCar[i])->getNode().setVisible(true);
            if (i < this->nbPlayers)
                dynamic_cast<Sprint::Game::Car *>(this->objs.at(this->playersCar[i]).get())->setIA(false);
            else
            {
                dynamic_cast<Sprint::Game::Car *>(this->objs.at(this->playersCar[i]).get())->setIA(true);
                this->physicEngine->disableCollision(this->objs.at(this->playersCar[i])->getNode(), this->playersCar[i]);
            }
        }
        this->setDecoration();
        this->sounds.at(Sprint::Sound::Song::RACE_SOUND)->play();
        this->ATH->displayStart(this->device);
        this->needReset = false;
    }
}

void                Sprint::Game::Core::setDecoration()
{
    // Zeppelin
    this->objs.at(Sprint::Game::Model::ZEPPELIN)->getNode().setVisible(true);
    this->objs.at(Sprint::Game::Model::ZEPPELIN)->getNode().setPosition(irr::core::vector3df(26.6712, 9.40312, 0.161703));
    this->objs.at(Sprint::Game::Model::ZEPPELIN)->getNode().setScale(irr::core::vector3df(0.32, 0.32, 0.32));
    // Referee
    this->objs.at(Sprint::Game::Model::REFEREE)->getNode().setVisible(true);
    this->objs.at(Sprint::Game::Model::REFEREE)->getNode().setPosition(irr::core::vector3df(-34.1724, 2.42096, 2.5931));
    this->objs.at(Sprint::Game::Model::REFEREE)->getNode().setRotation(irr::core::vector3df(0, 90, 0));
    this->objs.at(Sprint::Game::Model::REFEREE)->getNode().setScale(irr::core::vector3df(0.15, 0.15, 0.15));
    // Statue
    this->objs.at(Sprint::Game::Model::STATUE)->getNode().setVisible(true);
    this->objs.at(Sprint::Game::Model::STATUE)->getNode().setPosition(irr::core::vector3df(-7.57135, 1.66, 0.847953));
    this->objs.at(Sprint::Game::Model::STATUE)->getNode().setScale(irr::core::vector3df(0.2, 0.2, 0.2));
}

void                Sprint::Game::Core::splashScreen()
{
    bool            notFinished = true;
    float           vol;
    ALint           intro;
    ALint           intro_id;
    int             alpha = 0;

    this->sounds.at(Sound::Song::MAIN_THEME)->stop();
    this->sounds.at(Sound::Song::CAR_SOUND)->setLooping(true);
    this->sounds.at(Sound::Song::CAR_SOUND)->setPosition(500, 10, 50);
    this->sounds.at(Sound::Song::CAR_SOUND)->setVelocity(0, 0, 0);
    vol = this->sounds.at(Sound::Song::CAR_SOUND)->getVolume();
    this->sounds.at(Sound::Song::CAR_SOUND)->setVolume(100);
    this->sounds.at(Sound::Song::CAR_SOUND)->setPitch(3);
    this->sceneManager->addCameraSceneNode();
    for (auto const &obj : this->objs)
        obj.second->getNode().setVisible(false);
    this->skybox->setVisible(false);
    this->logo->setVisible(false);
    while (this->device->run() && alpha != 220)
    {
        this->driver->beginScene(true, true, irr::video::SColor(255, alpha, alpha, alpha));
        this->sceneManager->drawAll();
        alpha += 1;
        this->driver->endScene();
    }
    this->logo->setVisible(true);
    while (this->device->run() && alpha != 0)
    {
        this->driver->beginScene(true, true, irr::video::SColor(255, alpha, alpha, alpha));
        this->sceneManager->drawAll();
        alpha -= 1;
        this->driver->endScene();
    }
    this->logo->setVisible(false);
    alpha = 0;
    this->objs.at(Sprint::Game::Model::MARIO_KART)->getNode().setVisible(true);
    this->objs.at(Sprint::Game::Model::MARIO_KART)->getNode().setScale(irr::core::vector3df(0.4, 0.4, 0.4));
    this->objs.at(Sprint::Game::Model::MARIO_KART)->getNode().setPosition(irr::core::vector3df(500, 0, 50));
    this->objs.at(Sprint::Game::Model::MARIO_KART)->getNode().setRotation(irr::core::vector3df(0, 90, 0));
    this->sounds.at(Sound::Song::INTRO_SOUND)->play();
    intro_id = this->sounds.at(Sound::Song::INTRO_SOUND)->getSourceId();
    do
    {
        alGetSourcei(intro_id, AL_SOURCE_STATE, &intro);
    } while (intro == AL_PLAYING);
    this->sounds.at(Sound::Song::CAR_SOUND)->play();
    while (this->device->run() && notFinished)
    {
        this->driver->beginScene(true, true, irr::video::SColor(255, alpha, alpha, alpha));
        alpha = (alpha == 255) ? (255) : (alpha + 1);
        this->sceneManager->drawAll();
        this->driver->endScene();
        this->sounds.at(Sound::Song::CAR_SOUND)->setVelocity(this->sounds.at(Sound::Song::CAR_SOUND)->getVelocity().X - 0.5, 0, 0);
        if (this->sounds.at(Sound::Song::CAR_SOUND)->getVelocity().X < -50)
            this->sounds.at(Sound::Song::CAR_SOUND)->setVelocity(-50, 0, 0);
        this->sounds.at(Sound::Song::CAR_SOUND)->setPosition(this->sounds.at(Sound::Song::CAR_SOUND)->getPosition().X - 10, 10, 50);
        this->objs.at(Sprint::Game::Model::MARIO_KART)->getNode().setPosition(irr::core::vector3df(-this->sounds.at(Sound::Song::CAR_SOUND)->getPosition().X, 0, 30));
        if (this->sounds.at(Sound::Song::CAR_SOUND)->getPosition().X < -1000)
            notFinished = false;
    }
    this->sounds.at(Sound::Song::CAR_SOUND)->stop();
    this->sounds.at(Sound::Song::CAR_SOUND)->setPosition(0, 0, 0);
    this->sounds.at(Sound::Song::CAR_SOUND)->setVelocity(0, 0, 0);
    this->sounds.at(Sound::Song::CAR_SOUND)->setVolume(vol);
    this->sounds.at(Sound::Song::CAR_SOUND)->setPitch(1);
    this->sounds.at(Sound::Song::MAIN_THEME)->play();
    if (this->driver->getScreenSize().Width == 800)
        this->logo->setPosition(irr::core::vector3df(0, 7.5, 2.7));
    else
        this->logo->setPosition(irr::core::vector3df(0, 7.5, 8.5));
    this->skybox->setVisible(true);
    this->logo->setVisible(true);
}

void                Sprint::Game::Core::run()
{
    bool            check;

    while (this->device->run() && !this->menu->quit())
    {
        if (this->devMode)
            this->showFPS();
        this->sceneManager->addCameraSceneNode(0, this->pos, this->cam);
        this->driver->beginScene(true, true, irr::video::SColor(255, 255, 255, 255));
        check = this->menu->isInMenu();
        if (check != this->inMenu)
        {
            this->inMenu = !this->inMenu;
            this->needReset = true;
        }
        if (this->inMenu)
        {
            this->logo->setVisible(true);
            this->sounds.at(Sprint::Sound::Song::RACE_THEME)->stop();
            this->physicEngine->lockGravity();
            this->sceneManager->addCameraSceneNode(0, this->menuPos, this->menuCam);
            this->menu->move(*this->eventReceiver.get());
            this->sceneManager->drawAll();
            this->menu->drawAll();
        }
        else
        {
            this->sceneManager->addCameraSceneNode(0, this->pos, this->cam);
            this->reset();
            this->menu->move(*this->eventReceiver.get());
            if (!this->menu->isInPause())
            {
                this->moveCars();
                this->displayRanking();
                this->isGameOver();
                this->sceneManager->drawAll();
                if (this->nbPlayers == 1)
                {
                    int lapToWrite = dynamic_cast<Sprint::Game::Car *>(this->objs.at(this->playersCar[0]).get())->getNbLoop();
                    float speed = dynamic_cast<Sprint::Game::Car *>(this->objs.at(this->playersCar[0]).get())->getSpeed();
                    this->ATH->displayATH((lapToWrite <= 0) ? (1) : (lapToWrite + 1), this->nbLap, speed);
                }
                this->ATH->displayRanking(this->playersCar[0], this->nbPlayers, this->ranking);
            }
            else
            {
                this->sceneManager->drawAll();
                this->menu->drawAll();
            }
        }
        this->driver->endScene();
    }
    this->unloadResources();
}
