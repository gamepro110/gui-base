# pragma once

#include "GuiBase/Entrypoint.h"
#include "GuiBase/App.h"
#include "GuiBase/Layer.h"
#include "GuiBase/Logger.h"

class GuiExample : public GuiBase::Layer {
public:
    void OnAttach() override;
    void OnUpdate() override;
    void OnDetach() override;

private:
    ImGuiTreeNodeFlags defaultFlags = ImGuiTreeNodeFlags_DefaultOpen | ImGuiTreeNodeFlags_Leaf;
    bool showDemo = false;
};
