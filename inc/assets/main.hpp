#pragma once

#include <GLES2/gl2.h>
#include <nex.hpp>

using namespace NEX::Prefabs;
using namespace NEX::Core;
using namespace NEX::GL;

inline void queue_assets(uint8_t* count)
{
    // clang-format off
    (*count)++;
    AssetManager::queue<Texture>("t_menu_background",
        TextureConfig{.path = "assets/images/menu/background.png", .min_filter = GL_LINEAR, .mag_filter = GL_LINEAR}
    );

    (*count)++;
    AssetManager::queue<TextureArray>("t_menu_blip", std::vector<TextureConfig>{
        TextureConfig{.path = "assets/images/misc/white_bars/1.png", .min_filter = GL_LINEAR, .mag_filter = GL_LINEAR},
        TextureConfig{.path = "assets/images/misc/white_bars/2.png", .min_filter = GL_LINEAR, .mag_filter = GL_LINEAR},
        TextureConfig{.path = "assets/images/misc/white_bars/3.png", .min_filter = GL_LINEAR, .mag_filter = GL_LINEAR},
        TextureConfig{.path = "assets/images/misc/white_bars/4.png", .min_filter = GL_LINEAR, .mag_filter = GL_LINEAR},
        TextureConfig{.path = "assets/images/misc/white_bars/5.png", .min_filter = GL_LINEAR, .mag_filter = GL_LINEAR},
        TextureConfig{.path = "assets/images/misc/white_bars/6.png", .min_filter = GL_LINEAR, .mag_filter = GL_LINEAR},
        TextureConfig{.path = "assets/images/misc/white_bars/7.png", .min_filter = GL_LINEAR, .mag_filter = GL_LINEAR},
    });

    (*count)++;
    AssetManager::queue<TextureArray>("t_static", std::vector<TextureConfig>{
        TextureConfig{.path = "assets/images/static_top.png", .min_filter = GL_LINEAR, .mag_filter = GL_LINEAR},
        TextureConfig{.path = "assets/images/static_bottom.png", .min_filter = GL_LINEAR, .mag_filter = GL_LINEAR}
    });

    (*count)++;
    AssetManager::queue<TextureArray>("t_blip", std::vector<TextureConfig>{
        TextureConfig{.path = "assets/images/misc/night_bars/1.png", .min_filter = GL_LINEAR, .mag_filter = GL_LINEAR},
        TextureConfig{.path = "assets/images/misc/night_bars/2.png", .min_filter = GL_LINEAR, .mag_filter = GL_LINEAR},
        TextureConfig{.path = "assets/images/misc/night_bars/3.png", .min_filter = GL_LINEAR, .mag_filter = GL_LINEAR},
        TextureConfig{.path = "assets/images/misc/night_bars/4.png", .min_filter = GL_LINEAR, .mag_filter = GL_LINEAR},
        TextureConfig{.path = "assets/images/misc/night_bars/5.png", .min_filter = GL_LINEAR, .mag_filter = GL_LINEAR},
        TextureConfig{.path = "assets/images/misc/night_bars/6.png", .min_filter = GL_LINEAR, .mag_filter = GL_LINEAR},
        TextureConfig{.path = "assets/images/misc/night_bars/7.png", .min_filter = GL_LINEAR, .mag_filter = GL_LINEAR},
        TextureConfig{.path = "assets/images/misc/night_bars/8.png", .min_filter = GL_LINEAR, .mag_filter = GL_LINEAR},
        TextureConfig{.path = "assets/images/misc/night_bars/9.png", .min_filter = GL_LINEAR, .mag_filter = GL_LINEAR},
    });

    (*count)++;
    AssetManager::queue<Texture>("t_newspaper",
        TextureConfig{.path = "assets/images/misc/NEWSPAPER.png", .min_filter = GL_LINEAR, .mag_filter = GL_LINEAR}
    );

    (*count)++;
    AssetManager::queue<Shader>("s_menu_background",
        "assets/shaders/menu/background.vert", "assets/shaders/menu/background.frag"
    );

    (*count)++;
    AssetManager::queue<Audio>("a_static2",
        "assets/audio/menu/static2.mp3", true
    );

    (*count)++;
    AssetManager::queue<Audio>("a_blip3",
        "assets/audio/blip3.mp3", true
    );

    (*count)++;
    AssetManager::queue<Audio>("a_darkness_music",
        "assets/audio/menu/darkness music.mp3", true
    );

    (*count)++;
    AssetManager::queue<NEX::GL::MTSDF::Font>("f_consolas",
        "assets/images/fonts/consolas.sdf.png", "assets/images/fonts/consolas.csv"
    );

    (*count)++;
    AssetManager::queue<NEX::GL::MTSDF::Font>("f_lcdsolid",
        "assets/images/fonts/lcdsolid.sdf.png", "assets/images/fonts/lcdsolid.csv"
    );

    (*count)++;
    AssetManager::queue<NEX::GL::MTSDF::Font>("f_consolas_bold",
        "assets/images/fonts/consolas_bold.sdf.png", "assets/images/fonts/consolas_bold.csv"
    );
    // clang-format on
}