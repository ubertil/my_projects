/*
** Manager.hh for cpp_indie_studio in /home/login_p/delivery/cpp_indie_studio/Manager.hh
**
** Made by Alexis Papadimitriou
** Login   <alexis.papadimitriou@epitech.eu>
**
** Started on  Tue May 23 11:00:42 2017 Alexis Papadimitriou
** Last update Tue May 23 11:00:42 2017 Alexis Papadimitriou
*/

#pragma once
#include <memory>
#include <unordered_map>
#include <array>
#include <unordered_map>
#include "OpenAL/al.h"
#include "OpenAL/alc.h"
#include "Irrlicht/irrlicht.h"

namespace					Sprint
{
    namespace					Sound
    {
        class					Manager
        {
        private:
            ALCdevice					            *_device;
            ALCcontext				                *_context;
            std::unordered_map<std::string, ALuint>	_sounds;
            irr::core::vector3df			        _listener_pos;
            irr::core::vector3df			        _listener_velocity;
            std::array<ALfloat, 6>			        _listener_orientation;

        public:
            Manager();
            Manager(const Manager &cpy) = delete;
            ~Manager();

            Manager					                &operator=(const Manager &cpy) = delete;

            void 		                            setListenerPosition(ALfloat x, ALfloat y, ALfloat z);
            void 		                            setListenerVelocity(ALfloat x, ALfloat y, ALfloat z);
            void 		                            setListenerOrientation(ALfloat lx, ALfloat ly, ALfloat lz,
                                                                            ALfloat ux, ALfloat uy, ALfloat uz);

            ALuint		                            loadSound(std::string const &file_name);
        };
    }
}