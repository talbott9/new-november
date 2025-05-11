november: november.cpp sdlstuff.cpp globalvars.h renderer.h renderer.cpp menu.h menu.cpp media.cpp collision.cpp scripts.cpp scriptseach.cpp cutscene.h cutscene.cpp
	g++ november.cpp -IC:\mingw_dev_lib\include -LC:\mingw_dev_lib\lib -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -o november
