#pragma once

#include <nex.hpp>

using namespace NEX::Prefabs;
using namespace NEX::Core;
using namespace NEX::GL;

namespace Game::Objects::Office
{
    struct Simulation
    {
        Simulation(int night);

        enum EndedStatus
        {
            ENDED_NOT_YET,
            ENDED_JUMPSCARE,
            ENDED_NO_POWER,
            ENDED_GF
        };

        struct
        {
            EndedStatus ended = ENDED_NOT_YET;
            uint8_t hour = 0;
        } state;

        enum AnimatronicIndex
        {
            ANIMATRONIC_FREDDY,
            ANIMATRONIC_BONNIE,
            ANIMATRONIC_CHICA,
            ANIMATRONIC_FOXY,
            ANIMATRONIC_COUNT
        };

        uint8_t levels[ANIMATRONIC_COUNT];

        uint8_t presets[6][ANIMATRONIC_COUNT] = {{0, 0, 0, 0}, {0, 3, 1, 1}, {1, 0, 5, 2}, {1, 2, 4, 6}, {3, 5, 7, 5}, {4, 10, 12, 16}};

        std::unique_ptr<MTSDF::Text> t_time, t_night;
        std::shared_ptr<MTSDF::Font> f_lcdsolid;

        void advance_hour(void);
        void draw(void);
        void update(double);
        void event(SDL_Event&);
    };
}; // namespace Game::Objects::Office
