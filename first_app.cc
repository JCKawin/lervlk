#include "first_app.hh"

namespace lervlk {
FirstApp::FirstApp() {}

void FirstApp::run() {
  while (!window_handle.shouldClose()) {
    glfwPollEvents();
  }
}
} // namespace lervlk