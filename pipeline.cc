#include "pipeline.hh"
#include <fstream>
#include <iostream>
#include <stdexcept>

namespace lervlk {
Pipeline::Pipeline(const std::string &vertFilePath,
                   const std::string &fragFilePath, const Device &device,
                   const PipelineConfigInfo &configInfo) {
  createGraphicsPipeline(vertFilePath, fragFilePath);
}

std::vector<char> Pipeline::readFile(const std::string &filePath) {
  std::ifstream file{filePath, std::ios::ate | std::ios::binary};

  if (!file.is_open()) {
    throw std::runtime_error("Failed to open the file " + filePath);
  }

  size_t fileSize = static_cast<size_t>(file.tellg());

  std::vector<char> buffer(fileSize);
  file.seekg(0);
  file.read(buffer.data(), fileSize);

  file.close();
  return buffer;
}

void Pipeline::createGraphicsPipeline(const std::string &vertFilePath,
                                      const std::string &fragFilePath) {

  auto fragShader = readFile(fragFilePath);
  auto vertShader = readFile(vertFilePath);

  std::cout << "Size of Fragment Shader " << fragShader.size() << "\n";
  std::cout << "Size of Vertex Shader " << vertShader.size() << "\n";
}
} // namespace lervlk