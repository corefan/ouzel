// Copyright (C) 2015 Elviss Strazdins
// This file is part of the Ouzel engine.

#pragma once

#include "Widget.h"

namespace ouzel
{
    class Label: public Widget
    {
    public:
        Label(std::string const& font, std::string const& text);
        virtual ~Label();
    };
}
