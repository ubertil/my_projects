/*
** Source.cpp for cpp_indie_studio in /home/login_p/delivery/cpp_indie_studio/Source.cpp
**
** Made by Alexis Papadimitriou
** Login   <alexis.papadimitriou@epitech.eu>
**
** Started on  Tue May 23 14:08:43 2017 Alexis Papadimitriou
** Last update Tue May 23 14:08:43 2017 Alexis Papadimitriou
*/

#include "Sound/Source.hh"

Sprint::Sound::Source::Source(ALuint sound_id) :
        _sound_id(sound_id)
{
    alGenSources(1, &this->_source_id);
    alSourcei(this->_source_id, AL_BUFFER, this->_sound_id);
    this->setLooping(0);
    this->setVolume(1);
    this->setPitch(1);
}

Sprint::Sound::Source::~Source()
{
    this->stop();
    alSourcei(this->_source_id, AL_BUFFER, 0);
    alDeleteSources(1, &this->_source_id);
}

ALuint				Sprint::Sound::Source::getSourceId() const
{
    return (this->_source_id);
}

ALuint				Sprint::Sound::Source::getSoundId() const
{
    return (this->_sound_id);
}

const irr::core::vector3df	&Sprint::Sound::Source::getPosition() const
{
    return (this->_pos);
}

const irr::core::vector3df	&Sprint::Sound::Source::getVelocity() const
{
    return (this->_velocity);
}

const irr::core::vector3df	&Sprint::Sound::Source::getOrientation() const
{
    return (this->_orientation);
}

const ALint			&Sprint::Sound::Source::getLooping() const
{
    return (this->_looping);
}

const ALfloat			&Sprint::Sound::Source::getVolume() const
{
    return (this->_volume);
}

const ALfloat			&Sprint::Sound::Source::getPitch() const
{
    return (this->_pitch);
}

void		Sprint::Sound::Source::setPosition(ALfloat x, ALfloat y, ALfloat z)
{
    this->_pos.set(x, y, z);
    alSource3f(this->_source_id, AL_POSITION, x, y, z);
}

void		Sprint::Sound::Source::setVelocity(ALfloat x, ALfloat y, ALfloat z)
{
    this->_velocity.set(x, y, z);
    alSource3f(this->_source_id, AL_VELOCITY, x, y, z);
}

void		Sprint::Sound::Source::setOrientation(ALfloat x, ALfloat y, ALfloat z)
{
    this->_orientation.set(x, y, z);
    alSource3f(this->_source_id, AL_ORIENTATION, x, y, z);
}

void 		Sprint::Sound::Source::setLooping(ALint looping)
{
    this->_looping = looping;
    alSourcei(this->_source_id, AL_LOOPING, looping);
}

void 		Sprint::Sound::Source::setVolume(ALfloat volume)
{
    this->_volume = volume;
    alSourcef(this->_source_id, AL_GAIN, volume);
}

void 		Sprint::Sound::Source::setPitch(ALfloat pitch)
{
    this->_pitch = pitch;
    alSourcef(this->_source_id, AL_PITCH, pitch);
}

void		Sprint::Sound::Source::play()
{
    alSourcePlay(this->_source_id);
}

void		Sprint::Sound::Source::pause()
{
    alSourcePause(this->_source_id);
}

void 		Sprint::Sound::Source::stop()
{
    alSourceStop(this->_source_id);
}

void 		Sprint::Sound::Source::rewind()
{
    alSourceRewind(this->_source_id);
}