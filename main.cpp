#if define(DEBUG) || defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif//define(DEBUG) || defined(_DEBUG)
// Application
#include "App/App.h"
// log
#include "Logger/Logger.hpp"

int wmain(int argc, wchar_t** argv, wchar_t** evnp)
{
#if defined(DEBUG) || defined(_DEBUG)
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif//defined(DEBUG) || defined(_DEBUG)
	// spdlogの初期化
    spdlog::set_pattern("[%H:%M:%S][%^%l%$][%s:%#] %v");
    spdlog::set_level(spdlog::level::trace);

    // アプリケーションの実行
    App app(960, 540);
    app.Run();

    return 0;
}