/*
** Manager.cpp for cpp_indie_studio in /home/login_p/delivery/cpp_indie_studio/Manager.cpp
**
** Made by Alexis Papadimitriou
** Login   <alexis.papadimitriou@epitech.eu>
**
** Started on  Tue May 23 11:22:25 2017 Alexis Papadimitriou
** Last update Tue May 23 11:22:25 2017 Alexis Papadimitriou
*/

#include <vector>
#include "Sound/Manager.hh"
#include "sndfile/sndfile.h"
#include "Error.hpp"

Sprint::Sound::Manager::Manager()
{
    if ((this->_device = alcOpenDevice(nullptr)) == nullptr)
        throw Sprint::Error::SoundError("Failed to open a sound device");
    if ((this->_context = alcCreateContext(this->_device, nullptr)) == nullptr)
        throw Sprint::Error::SoundError("Failed to create an OpenAL context");
    if (!alcMakeContextCurrent(this->_context))
        throw Sprint::Error::SoundError("Failed to activate OpenAL context");
    this->setListenerPosition(0, 0, 0);
    this->setListenerVelocity(0, 0, 0);
    this->setListenerOrientation(0, 0, 1, 0, 1, 0);
}

Sprint::Sound::Manager::~Manager()
{
    alcMakeContextCurrent(nullptr);
    alcDestroyContext(this->_context);
    alcCloseDevice(this->_device);
    for (auto &sound : this->_sounds)
        alDeleteBuffers(1, &sound.second);
}

ALuint		Sprint::Sound::Manager::loadSound(std::string const &file_name)
{
    SF_INFO	file_info;
    SNDFILE	*file;
    ALsizei	nb_samples;
    ALsizei	sample_rate;
    ALenum	format;
    ALuint	sound_id;

    if (this->_sounds.find(file_name) != this->_sounds.end())
        return (this->_sounds[file_name]);
    if (!(file = sf_open(file_name.c_str(), SFM_READ, &file_info)))
    {
        sf_perror(file);
        throw Sprint::Error::SoundError("Failed to open file: " + file_name);
    }
    nb_samples = file_info.channels * file_info.frames;
    sample_rate = file_info.samplerate;

    std::vector<ALshort>	samples(nb_samples);

    if (sf_read_short(file, &samples[0], nb_samples) < nb_samples)
        throw Sprint::Error::SoundError("Failed to load data from file: " + file_name);
    sf_close(file);
    switch (file_info.channels)
    {
        case 1 : format = AL_FORMAT_MONO16  ; break;
        case 2 : format = AL_FORMAT_STEREO16; break;
        default:
            throw Sprint::Error::SoundError("Cannot determinate sound format from file: " + file_name);
    }
    alGenBuffers(1, &sound_id);
    alBufferData(sound_id, format, &samples[0], nb_samples * sizeof(ALushort), sample_rate);
    if (alGetError() != AL_NO_ERROR)
        throw Sprint::Error::SoundError("Failed to create an OpenAL sound buffer from file: " + file_name);
    this->_sounds[file_name] = sound_id;
    return (sound_id);
}

void 		Sprint::Sound::Manager::setListenerPosition(ALfloat x, ALfloat y, ALfloat z)
{
    this->_listener_pos.set(x, y, z);
    alListener3f(AL_POSITION, x, y, z);
}

void 		Sprint::Sound::Manager::setListenerVelocity(ALfloat x, ALfloat y, ALfloat z)
{
    this->_listener_velocity.set(x, y, z);
    alListener3f(AL_VELOCITY, x, y, z);
}

void 		Sprint::Sound::Manager::setListenerOrientation(ALfloat lx, ALfloat ly, ALfloat lz,
                                                           ALfloat ux, ALfloat uy, ALfloat uz)
{
    this->_listener_orientation[0] = lx;
    this->_listener_orientation[1] = ly;
    this->_listener_orientation[2] = lz;
    this->_listener_orientation[3] = ux;
    this->_listener_orientation[4] = uy;
    this->_listener_orientation[5] = uz;
    alListenerfv(AL_ORIENTATION, &this->_listener_orientation[0]);
}