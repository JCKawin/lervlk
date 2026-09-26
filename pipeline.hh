#pragma once

#include <vector>
#include <string>
#include "device.hh"


namespace lervlk {
    struct PipelineConfigInfo {
        VkViewport viewport;
  VkRect2D scissor;
  VkPipelineViewportStateCreateInfo viewportInfo;
  VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
  VkPipelineRasterizationStateCreateInfo rasterizationInfo;
  VkPipelineMultisampleStateCreateInfo multisampleInfo;
  VkPipelineColorBlendAttachmentState colorBlendAttachment;
  VkPipelineColorBlendStateCreateInfo colorBlendInfo;
  VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
  VkPipelineLayout pipelineLayout = nullptr;
  VkRenderPass renderPass = nullptr;
  uint32_t subpass = 0;
    };
    class Pipeline {
        public:
            Pipeline(const std::string& vertFilePath , const std::string& fragFilePath,
            Device &device , const PipelineConfigInfo& configInfo);

            Pipeline(const Pipeline&) = delete;
            void operator=(const Pipeline&) = delete;

            static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width , uint32_t height);

        private:
            static std::vector<char> readFile(const std::string& filePath);
            void createGraphicsPipeline(const std::string& vertShader , const std::string& fragShader , struct PipelineConfigInfo configInfo);
            void createShaderModule(const std::vector<char> &code , VkShaderModule* shaderModule); 
            
            Device &pipelineDevice;
            VkPipeline graphicsPipeline;
            VkShaderModule vertShaderModule;
            VkShaderModule fragShaderModule;
    };
}