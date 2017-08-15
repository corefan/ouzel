// Copyright (C) 2017 Elviss Strazdins
// This file is part of the Ouzel engine.

#pragma once

#include <memory>
#include "utils/Noncopyable.hpp"
#include "Renderer.hpp"
#include "math/Color.hpp"

namespace ouzel
{
    namespace graphics
    {
        class BlendState;
        class Shader;
        class Texture;

        class Material: public Noncopyable
        {
        public:
            std::shared_ptr<BlendState> blendState;
            std::shared_ptr<Shader> shader;
            std::shared_ptr<Texture> texture;
            graphics::Renderer::CullMode cullMode = graphics::Renderer::CullMode::BACK;
            Color diffuseColor = Color::WHITE;
        };
    } // namespace graphics
} // namespace ouzel
