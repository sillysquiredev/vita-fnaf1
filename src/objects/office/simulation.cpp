#include "objects/office/simulation.hpp"

#include <nex/core/random.hpp>
#include "nex/core/assetmanager.hpp"

using namespace Game::Objects::Office;

Simulation::Simulation(int night)
{
    if (night < 7)
        memcpy(this->levels, this->presets[night], ANIMATRONIC_COUNT * sizeof(uint8_t));

    if (night == 4)
        this->levels[ANIMATRONIC_BONNIE] += NEX::Core::Random::range(0, 2);

    this->f_lcdsolid = AssetManager::get<MTSDF::Font>("f_lcdsolid");
    this->t_time = std::make_unique<MTSDF::Text>(this->f_lcdsolid, "12 AM");
    this->t_time->x = 800.0 / 960.0;
    this->t_time->y = 466.0 / 540.0;
    this->t_time->o_x = -0.5;
    this->t_time->o_y = 0.5;
    this->t_time->s = 60 / 544.0;
    this->t_time->s_x = 0.6;

    this->t_night = std::make_unique<MTSDF::Text>(this->f_lcdsolid, "Night " + std::to_string(night));
    this->t_night->x = 800.0 / 960.0;
    this->t_night->y = 409.0 / 540.0;
    this->t_night->o_x = -0.5;
    this->t_night->o_y = 0.5;
    this->t_night->s = 30 / 544.0;
    this->t_night->s_x = 0.6;

    this->t_usage = std::make_unique<MTSDF::Text>(this->f_lcdsolid, "Usage:");
    this->t_usage->x = -900.0 / 960.0;
    this->t_usage->y = -466.0 / 540.0;
    this->t_usage->o_y = 0.5;
    this->t_usage->s = 35 / 544.0;
    this->t_usage->s_x = 0.6;

    this->t_power = std::make_unique<MTSDF::Text>(this->f_lcdsolid, "Power left: 100%");
    this->t_power->x = -900.0 / 960.0;
    this->t_power->y = -400.0 / 540.0;
    this->t_power->o_y = 0.5;
    this->t_power->s = 35 / 544.0;
    this->t_power->s_x = 0.6;

    this->tx_usage = AssetManager::get<Texture>("tx_usage");
    this->s_usage = AssetManager::get<Shader>("s_night_usage");
    this->spr_usage.refresh_from_rect(SDL_FRect{.x = -750.0 / 960, .y = -490.0 / 544, .w = 160.0 / 960, .h = 60.0 / 544});
}

void Simulation::advance_hour(void)
{
    state.hour += 1;
    if (state.hour == 2)
        levels[ANIMATRONIC_BONNIE] = std::min(levels[ANIMATRONIC_BONNIE] + 1, 20);

    if (state.hour == 3)
    {
        levels[ANIMATRONIC_BONNIE] = std::min(levels[ANIMATRONIC_BONNIE] + 1, 20);
        levels[ANIMATRONIC_CHICA] = std::min(levels[ANIMATRONIC_CHICA] + 1, 20);
        levels[ANIMATRONIC_FOXY] = std::min(levels[ANIMATRONIC_FOXY] + 1, 20);
    }

    if (state.hour == 4)
    {
        levels[ANIMATRONIC_BONNIE] = std::min(levels[ANIMATRONIC_BONNIE] + 1, 20);
        levels[ANIMATRONIC_CHICA] = std::min(levels[ANIMATRONIC_CHICA] + 1, 20);
        levels[ANIMATRONIC_FOXY] = std::min(levels[ANIMATRONIC_FOXY] + 1, 20);
    }
}

void Simulation::draw(void)
{
    this->t_time->draw();
    this->t_night->draw();

    this->t_usage->draw();
    this->t_power->draw();

    this->s_usage->use();
    this->s_usage->set_uniform("gt_texture.texture", 0);
    this->s_usage->set_uniform("gt_texture.index", 0.0);
    this->s_usage->set_uniform("gt_texture.width", 1.0);
    this->s_usage->set_uniform("gt_texture.height", 5.0);
    this->tx_usage->activate(GL_TEXTURE0);
    this->spr_usage.draw(*this->s_usage);
}

void Simulation::update(double dt)
{ UNUSED(dt); }

void Simulation::event(SDL_Event& event)
{ UNUSED(event); }