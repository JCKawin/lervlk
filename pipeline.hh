#pragma once

#include <vector>
#include <string>
#include "device.hh"


namespace lervlk {
    struct PipelineConfigInfo {

    };


    class Pipeline {
        public:
            Pipeline(const std::string& vertFilePath , const std::string& fragFilePath,
            const Device &device , const PipelineConfigInfo& configInfo);

        private:
            static std::vector<char> readFile(const std::string& filePath);

            void createGraphicsPipeline(const std::string& vertShader , const std::string& fragShader);

    };
}