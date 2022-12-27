all: bin/main.exe

bin/main.exe: obj/main.o obj/renderWindow.o obj/songPlayer.o
	g++ obj/main.o obj/renderWindow.o obj/songPlayer.o -o bin/main.exe -I C:/SDL2-w64/include -I . -L C:\SDL2-w64\lib -L .\bin -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer

obj/main.o: src/main.cpp include/RenderWindow.hpp
	g++ -c src/main.cpp -o obj/main.o -I C:/SDL2-w64/include -I . -L C:\SDL2-w64\lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer

obj/renderWindow.o: src/renderWindow.cpp include/RenderWindow.hpp
	g++ -c src/renderWindow.cpp -o obj/renderWindow.o -I C:/SDL2-w64/include -I . -L C:\SDL2-w64\lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer

obj/songPlayer.o: src/songPlayer.cpp include/SongPlayer.hpp
	g++ -c src/songPlayer.cpp -o obj/songPlayer.o -I C:/SDL2-w64/include -I . -L C:\SDL2-w64\lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer

clean:
	rm -f obj/*.o bin/*.exe

# Path: main.cpp