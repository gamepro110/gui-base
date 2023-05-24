#include "GuiExample.h"

void GuiExample::OnAttach() {
    TRACE("GuiExample layer onattach");
}

void GuiExample::OnUpdate() {
    LOG("GuiExample layer onupdate");
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

void GuiExample::OnDetach() {
    TRACE("GuiExample layer ondetach");
}
