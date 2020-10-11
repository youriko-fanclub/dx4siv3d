#pragma once

#include <string>
#include <vector>
#include <Siv3D/String.hpp>
#include <Siv3D/Font.hpp>
#include "Singleton.hpp"

namespace dx {
namespace app {

class AssetManager final : public cmp::Singleton<AssetManager> {
public: // static_const/enum
  struct FontDesc {
  public:
    s3d::String key;
    unsigned size;
    s3d::String typefaceString = U"";
    s3d::Typeface typeface;
  public:
    FontDesc(
      const s3d::String& key,
      unsigned size,
      const s3d::String& typeface) :
      key(key), size(size), typefaceString(typeface) {}
    FontDesc(
      const s3d::String& key,
      unsigned size,
      const s3d::Typeface& typeface) :
      key(key), size(size), typeface(typeface) {}
  };
public: // static
public: // public function
  void initialize(const std::vector<FontDesc>& descs);

private: // field
private: // private function
public: // ctor/dtor
};

}
}


