#pragma once

#include "GuiBase/Layer.h"
#include "GuiBase/Logger.h"

#include "imgui.h"
#include "vulkan/vulkan.h"

#include <string>
#include <vector>
#include <memory>
#include <functional>

struct GLFWwindow;

namespace GuiBase {
    struct WindowSettings {
		std::string Name = "...";
		uint32_t Width = 800;
		uint32_t Height = 600;
	};

    class App {
    public:
        App(WindowSettings settings);
        ~App();

    public:
        void run();
        void Close();

        template<typename T>
		void PushLayer() {
			static_assert(std::is_base_of<Layer, T>::value, "Pushed type is not subclass of Layer!!");
			layerStack.emplace_back(std::make_shared<T>())->OnAttach();
		}

		void PushLayer(const std::shared_ptr<Layer>& layer) {
			layerStack.emplace_back(layer);
			layer->OnAttach();
		}

    private:
        void Init();
        void Shutdown();

    private:
        WindowSettings settings;
        bool running = false;
        GLFWwindow* windowHandle;
        std::vector<std::shared_ptr<Layer>> layerStack;
    };

    App* CreateApp(int argc, char** argv);
}
