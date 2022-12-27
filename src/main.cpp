#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include "include/SongPlayer.hpp"

int main(int argc, char *argv[])
{
    SongPlayer player;
    if (!player.loadSong("Burgers.mp3"))
    {
        // An error occurred while loading the song
        std::cout << "Error loading song" << std::endl;
        return 1;
    }
    player.play();
    SDL_Delay(500000);
    return 0;
}
