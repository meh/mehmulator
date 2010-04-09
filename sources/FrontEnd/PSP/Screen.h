/****************************************************************************
 * Copyleft meh. [http://meh.doesntexist.org | meh.ffff@gmail.com]          *
 *                                                                          *
 * This file is part of mehmulator. A cross platform emulator.              *
 *                                                                          *
 * mehmulator is free software: you can redistribute it and/or modify       *
 * it under the terms of the GNU Affero General Public License as           *
 * published by the Free Software Foundation, either version 3 of the       *
 * License, or (at your option) any later version.                          *
 *                                                                          *
 * mehmulator is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of           *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
 * GNU Affero General Public License for more details.                      *
 *                                                                          *
 * You should have received a copy of the GNU Affero General Public License *
 * along with mehmulator.  If not, see <http://www.gnu.org/licenses/>.      *
 ****************************************************************************/

#ifndef _MEHMULATOR_FRONTEND_PSP_SCREEN_H
#define _MEHMULATOR_FRONTEND_PSP_SCREEN_H

#include <SDL/SDL.h>

namespace mehmulator {

namespace FrontEnd {

#define WIDTH  480
#define HEIGHT 272
#define BPP    32

class Screen
{
  protected:
    Screen (void);

  public:
    static Screen* instance (void);

    inline Uint32 RGB (r, g, b, a = 255);

  private:
    Screen* _singleton;

    SDL_Surface* _surface;
};

}

}

#endif
