//
// Created by come on 23/05/17.
//

#include "Loader/RessourceLoader.hh"

namespace Sprint
{
    template <>
    irr::video::IImage *ResourceManager::Load<irr::video::IImage>(irr::video::IVideoDriver &driver,
                                                                  irr::scene::ISceneManager &sceneManager,
                                                                  const std::string &filepath)
    {
        return (driver.createImageFromFile(filepath.c_str()));
    }

    template <>
    void ResourceManager::Unload<irr::video::IImage>(irr::video::IImage &resource)
    {
        resource.drop();
    }

    template <>
    irr::scene::IAnimatedMesh *ResourceManager::Load<irr::scene::IAnimatedMesh>(irr::video::IVideoDriver &driver,
                                                                                irr::scene::ISceneManager &sceneManager,
                                                                                const std::string &filepath)
    {
        return (sceneManager.getMesh(filepath.c_str()));
    }

    template <>
    void ResourceManager::Unload<irr::scene::IAnimatedMesh>(irr::scene::IAnimatedMesh &resource)
    {

    }
}
