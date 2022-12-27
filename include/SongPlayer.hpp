#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

class SongPlayer
{
public:
    SongPlayer();
    ~SongPlayer();
    bool loadSong(const char *fileName);
    void play();
    void pause();
    void resume();
    void stop();

private:
    Mix_Music *music;
    static void songFinishedCallback();
};