#include "ApplicationManager.hpp"

#include <Siv3D/System.hpp>
#include <Siv3D/UserAction.hpp>
#include <Siv3D/Window.hpp>
#include <Siv3D/Scene.hpp>
#include <Siv3D/Color.hpp>

namespace dx {
namespace app {

/* ---------- ApplicationManager ---------- */

// static ----------------------------------------
// public function -------------------------------
void ApplicationManager::initialize(const Desc& desc) {
    if (desc.is_close_by_escape_key) {
        s3d::System::SetTerminationTriggers(s3d::UserAction::CloseButtonClicked);
    }
    
    // タイトルを設定
    s3d::Window::SetTitle(desc.window_title);
    s3d::Window::Resize(desc.window_size);
    
    // 背景色を設定
    s3d::Scene::SetBackground(s3d::ColorF(0.2, 0.8, 0.4));
}
// private function ------------------------------
// ctor/dtor -------------------------------------


}
}
