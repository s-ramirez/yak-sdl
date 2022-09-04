#pragma once

namespace Yak
{
    struct Config
    {
        const char *name = "MyGame";
        int width = 320;
        int height = 240;
        int target_fps = 60;
        bool fullscreen = false;

        void (*OnInit)();
        void (*OnUpdate)();
        void (*OnRender)();
    };

}