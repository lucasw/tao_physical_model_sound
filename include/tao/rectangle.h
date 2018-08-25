/* Tao - A software package for sound synthesis with physical models
 * Copyright (C) 1993-1999 Mark Pearson
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <tao/cell.h>
#include <tao/instrument.h>

#ifdef WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

class DLLEXPORT TaoRectangle : public TaoInstrument {
public:
  TaoRectangle(std::shared_ptr<Tao> tao, const TaoPitch &xpitch, const TaoPitch &ypitch,
               float decay);
  TaoRectangle(std::shared_ptr<Tao> tao, const char *name, const TaoPitch &xpitch,
               const TaoPitch &ypitch,
               float decay);
  inline TaoCell &at(float x, float y) {
    return rows[(int)(ymax * y)].cells[(int)(xmax * x)];
  }

  void createTheMaterial();
};

#endif
