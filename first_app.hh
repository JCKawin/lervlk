#pragma once 

#include "window.hh"
#include "pipeline.hh"

namespace lervlk
{
    class FirstApp{
        public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;
        FirstApp();
        
        void run()  ;
        private :
        Window window_handle{WIDTH , HEIGHT , "Vulkan App #1"}; 
        Pipeline pipeline {"compiled_shaders/simple_shader.vert.spv" , "compiled_shaders/simple_shader.frag.spv"};
    };
    
} // namespace lervlk
