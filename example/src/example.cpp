#include "GuiBase/Entrypoint.h"
#include "GuiBase/App.h"
#include "GuiBase/Layer.h"
#include "GuiBase/Logger.h"

#include <iostream>

class GuiExample : public GuiBase::Layer {
public:
    void OnAttach() override {
        GuiBase::TRACE("GuiExample layer onattach");
    }
    void OnUpdate() override {
        GuiBase::LOG("GuiExample layer onupdate");
        ImGui::Begin("example window", NULL);

        ImGui::Text("showDemo: %c", showDemo ? 'Y' : '_');
        ImGui::Checkbox("show debug menu", &showDemo);

        if (ImGui::CollapsingHeader("indented submenu", defaultFlags)) {
            ImGui::Indent();
            ImGui::TextUnformatted("indented text");
            ImGui::Unindent();
        }

        static float arr[] = { 0.6f, 0.1f, 1.0f, 0.5f, 0.92f, 0.1f, 0.2f };
        ImGui::PlotLines("Frame Times", arr, IM_ARRAYSIZE(arr));
        ImGui::PlotHistogram("Histogram", arr, IM_ARRAYSIZE(arr), 0, NULL, 0.0f, 1.0f, ImVec2(0, 80.0f));

        ImGui::End();

        //
        ImGui::ShowDemoWindow(&showDemo);
    }
    void OnDetach() override {
        GuiBase::TRACE("GuiExample layer ondetach");
    }

private:
    ImGuiTreeNodeFlags defaultFlags = ImGuiTreeNodeFlags_DefaultOpen | ImGuiTreeNodeFlags_Leaf;
    bool showDemo = false;
};

GuiBase::App* GuiBase::CreateApp(int argc, char** argv) {
    WindowSettings settings;

    settings.Name = std::string("Settings app");
    settings.Width = 1200;
    settings.Height = 800;

    GuiBase::App* app = new GuiBase::App(settings);
    Logger::setLogLevel(LogLevel::trace);
    GuiBase::LOG("app start");

    for (int i = 0; i < argc; i++) {
        std::string str{ "arg( " + std::to_string(i) + " )> " + argv[i] };
        GuiBase::LOG(str);
    }

    app->PushLayer<GuiExample>();
    GuiBase::WARN("pushed layer 'tmp'");

    GuiBase::LOG("returning app*");
    return app;
}
