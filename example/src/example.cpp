#include "GuiExample.h"

#include "GuiBase/Entrypoint.h"
#include "GuiBase/App.h"
#include "GuiBase/Layer.h"
#include "GuiBase/Logger.h"

#include <iostream>

GuiBase::App* GuiBase::CreateApp(int argc, char** argv) {
    WindowSettings settings;

    settings.Name = std::string("Settings app");
    settings.Width = 1200;
    settings.Height = 800;

    GuiBase::App* app = new GuiBase::App(settings);
    Logger::setLogLevel(LogLevel::trace);
    LOG("app start");

    for (int i = 0; i < argc; i++) {
        std::string str{ "arg( " + std::to_string(i) + " )> " + argv[i] };
        LOG(str);
    }

    app->PushLayer<GuiExample>();
    WARN("pushed layer 'tmp'");

    LOG("returning app*");
    return app;
}
