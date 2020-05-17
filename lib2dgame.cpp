#include "lib2dgame.h"

namespace world
{
    bool check_collison(types::tpos rt1, types::tpos rb1, types::tpos rt2, types::tpos rb2)
    {
        return (
            rt1.x <= rt2.x && rt2.x <= rb1.x &&
            rt1.y <= rt2.y && rt2.y <= rb1.y
        ) || (
            rt1.x <= rb2.x && rb2.x <= rb1.x &&
            rt1.y <= rb2.y && rb2.y <= rb1.y
        );
    }
    void room::poll_events()
    {
        for(int i = 0; i < this->sprites.size(); i++)
        {
            for(int j = i + 1; i < this->sprites.size(); j++)
            {}
        }
    }
    void room::init(types::tileset_t _tileset, types::level_t _levels, size_t _tilesize, stileset_t _stileset, spritelist _sprites)
    {
        tilemap::init(_tileset, _levels, _tilesize);
        this->stileset = _stileset;
        this->sprites = _sprites;
    }
    void room::render()
    {
        if(tilemap::render() != 0)
            return -1;
        
    }
}