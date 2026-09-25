#include "first_app.hh"
#include <iostream>

#include <cstdlib>
#include <stdexcept>
#include <string>

int main() {
  lervlk::FirstApp app{};

  try {
    app.run();
  } catch (const std::exception &e) {
    std::cerr << e.what() << "\n";
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
