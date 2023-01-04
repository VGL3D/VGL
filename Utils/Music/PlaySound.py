import playsound
import multiprocessing


class LoadSounds:
    def PlayCustom(file=None):
        playsound.playsound(f'../../Sources/Audios/{file}.mp3')
        print('playing sound using  playsound')


sound1 = LoadSounds();
