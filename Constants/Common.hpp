//
// Created by soham on 12/15/22.
//

#ifndef GAMECLION_COMMON_H
#define GAMECLION_COMMON_H

#define QUOTE(...) #__VA_ARGS__
const char *pyCode = QUOTE(
        import sys;
        import os;
        sys.path.append('/home/soham/Documents/gameclion/Utils');
        from Music import PlaySound;
        //print('Hello from Python!!');
);

char *getPycode(){
    return const_cast<char *>(pyCode);
}
static const char *helptext[] = {
        "Hello world in game",
        0
};

static const char *scene2[] = {
        "You reached scene2",
        0
};

#endif //GAMECLION_COMMON_H
