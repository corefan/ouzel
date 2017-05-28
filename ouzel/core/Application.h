// Copyright (C) 2017 Elviss Strazdins
// This file is part of the Ouzel engine.

#pragma once

#include <vector>
#include <string>
#include <queue>
#include <functional>
#include <mutex>
#include "files/FileSystem.h"
#include "utils/Noncopyable.h"

namespace ouzel
{
    class Cursor;
    class CursorResource;

    class Application: public Noncopyable
    {
        friend Cursor;
    public:
        Application();
        Application(int aArgc, char* aArgv[]);
        Application(const std::vector<std::string>& aArgs);
        virtual ~Application();

        virtual int run();
        virtual void exit();
        bool isActive() const { return active; }

        int getArgc() const { return argc; }
        char** getArgv() const { return argv; }
        const std::vector<std::string>& getArgs() { return args; }

        virtual void execute(const std::function<void(void)>& func);

        FileSystem* getFileSystem() { return &fileSystem; }

        virtual bool openURL(const std::string& url);

        virtual void setScreenSaverEnabled(bool newScreenSaverEnabled);
        bool isScreenSaverEnabled() const { return screenSaverEnabled; }

    protected:
        void executeAll();

        virtual CursorResource* createCursorResource();
        void deleteCursorResource(CursorResource* cursorResource);

        bool active = true;
        bool screenSaverEnabled = true;
        int argc = 0;
        char** argv = nullptr;
        std::vector<std::string> args;

        std::queue<std::function<void(void)>> executeQueue;
        std::mutex executeMutex;

        FileSystem fileSystem;

        std::vector<CursorResource> cursorResources;
    };

    extern Application* sharedApplication;
}
