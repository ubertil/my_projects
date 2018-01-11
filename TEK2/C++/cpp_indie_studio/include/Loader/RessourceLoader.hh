//
// Created by Nicolas on 22/05/17.
//

#pragma once
# include <string>
# include <memory>
# include <Irrlicht/irrlicht.h>
# include <Irrlicht/IImage.h>
# include <Irrlicht/IAnimatedMesh.h>

namespace Sprint
{
    class ResourceManager
    {
    public:
        ResourceManager() = default;
        ~ResourceManager() = default;
        template<class T> static T *Load(irr::video::IVideoDriver &,
                                  irr::scene::ISceneManager &,
                                  const std::string &filepath);
        template<class T> void Unload(T &resource);
    };
}