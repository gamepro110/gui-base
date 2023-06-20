# GuiBase

glfw and imgui base setup

## todo

- [ ] fix crossplatform build
  - [ ] windows
    - [ ] c compiler messing with cpp build
  - [x] linux
- [ ] fix build flags
  - [ ] platform safe-guards
    - [ ] linux
    - [ ] windows
  - [ ] flags themself
    - [x] linux
    - [ ] windows
- [ ] tests
- [x] example documentation
- [ ] improve documentation
- [x] setup submodules
  - [x] glfw
  - [x] dear-imgui

## ideas borrowed from Cherno/walnut.git

- EntryPoint.h
  - App* CreateApp(int argc, char** argv);
- Layer.h
- app::pushLayer()
- app::layerStack
