/*
** Sound.hh for cpp_indie_studio in /home/login_p/delivery/cpp_indie_studio/Sound.hh
**
** Made by Alexis Papadimitriou
** Login   <alexis.papadimitriou@epitech.eu>
**
** Started on  Tue May 23 13:19:36 2017 Alexis Papadimitriou
** Last update Tue May 23 13:19:36 2017 Alexis Papadimitriou
*/

#pragma once
# include <stdint.h>
# include "OpenAL/al.h"
# include "Irrlicht/irrlicht.h"

namespace			Sprint
{
    namespace			Sound
    {
        // 0 : Main Music
        // 1 : Bip mouvement
        // 2 : Bip enter
        // 3 : Car sound
        // 4 : Victory sound
        // 5 : Car race sound
        // 6 : Splash Screen sound
        // 7 : Bip Start race
        enum Song
        {
            MAIN_THEME,
            MENU_MOVEMENT,
            MENU_ENTER,
            CAR_SOUND,
            VICTORY_SOUND,
            RACE_THEME,
            INTRO_SOUND,
            RACE_SOUND,
        };

        class			Source
        {
        private:
            ALuint			            _source_id;
            ALuint			            _sound_id;
            ALint			            _looping;
            ALfloat			            _volume;
            ALfloat			            _pitch;
            irr::core::vector3df	    _pos;
            irr::core::vector3df	    _velocity;
            irr::core::vector3df	    _orientation;

        public:
            Source(ALuint sound_id);
            Source(const Source &cpy) = delete;
            ~Source();

            Source	&operator=(const Source &cpy) = delete;

            ALuint				        getSourceId() const;
            ALuint				        getSoundId() const;
            const irr::core::vector3df	&getPosition() const;
            const irr::core::vector3df	&getVelocity() const;
            const irr::core::vector3df	&getOrientation() const;
            const ALint			        &getLooping() const;
            const ALfloat			    &getVolume() const;
            const ALfloat			    &getPitch() const;

            void		                setPosition(ALfloat x, ALfloat y, ALfloat z);
            void		                setVelocity(ALfloat x, ALfloat y, ALfloat z);
            void		                setOrientation(ALfloat x, ALfloat y, ALfloat z);
            void 		                setLooping(ALint looping);
            void 		                setVolume(ALfloat volume);
            void		                setPitch(ALfloat pitch);

            void	 	                play();
            void		                pause();
            void 		                stop();
            void 		                rewind(); // stop and replay from the begining
        };
    }
}