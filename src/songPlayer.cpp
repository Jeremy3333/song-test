#include "include/SongPlayer.hpp"
#include <iostream>

SongPlayer::SongPlayer()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_AUDIO) < 0)
    {
        // Error handling
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return;
    }

    // Initialize SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        // Error handling
        std::cout << "Mix_OpenAudio Error: " << Mix_GetError() << std::endl;
        return;
    }
}

SongPlayer::~SongPlayer()
{
    // Clean up
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_Quit();
}

bool SongPlayer::loadSong(const char *fileName)
{
    // Load the music file
    music = Mix_LoadMUS(fileName);
    if (!music)
    {
        // Error handling
        std::cout << "Mix_LoadMUS Error: " << Mix_GetError() << std::endl;
        return false;
    }
    return true;
}

void SongPlayer::play()
{
    Mix_HookMusicFinished(songFinishedCallback);
    Mix_PlayMusic(music, 0);
}

void SongPlayer::pause()
{
    Mix_PauseMusic();
}

void SongPlayer::resume()
{
    Mix_ResumeMusic();
}

void SongPlayer::stop()
{
    Mix_HaltMusic();
}

void SongPlayer::songFinishedCallback()
{
    std::cout << "Song finished playing" << std::endl;
    Mix_HaltMusic();
}