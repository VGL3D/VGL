#include "irrklang/irrKlang.h"
#include "stdio.h"
#include "unistd.h"
using namespace irrklang;
ISoundEngine *SoundEngine = createIrrKlangDevice();
int main()
{
    ISoundEngine *SoundEngine = createIrrKlangDevice();
    if (!SoundEngine)
    {
        printf("Could not create sound engine\n");
        return 1;
    }
    while (1)
    {
        SoundEngine->play2D("Assets/sounds/explosion.wav", true);
        sleep(2000);
    }
    return 0;
}