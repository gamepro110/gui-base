#pragma once

namespace GuiBase {
    class Layer {
    public:
        virtual ~Layer() = default;

    public:
        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
    };
}
