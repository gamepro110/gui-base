#pragma once
#include "GuiBase/App.h"

extern GuiBase::App* GuiBase::CreateApp(int argc, char** argv);

namespace GuiBase {
    bool GlobalAppRunning = true;

    int Main(int argc, char** argv) {
        while (GlobalAppRunning) {
            GuiBase::App* app = GuiBase::CreateApp(argc, argv);
            app->run();
            delete app;
        }

        return 0;
    }
}

#if WIN32

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow) {
	return ABC_Name::Main(__argc, __argv);
}

#else

int main(int argc, char** argv) {
    return GuiBase::Main(argc, argv);
}

#endif
