/***************************************************************************
 *   Copyright (C) 2019 PCSX-Redux authors                                 *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.           *
 ***************************************************************************/

#pragma once

#include "imgui.h"

namespace PCSX {
namespace Widgets {

class VRAMViewer {
  public:
    void init();
    void draw(unsigned int textureId, ImVec2 dimensions);

  private:
    static void imguiCBtrampoline(const ImDrawList *parent_list, const ImDrawCmd *cmd);
    void imguiCB(const ImDrawList *parent_list, const ImDrawCmd *cmd);
    unsigned int m_shaderProgram;
    int m_attribLocationTex;
    int m_attribLocationProjMtx;
    int m_attribLocationVtxPos;
    int m_attribLocationVtxUV;
    int m_attribLocationVtxColor;
};

}
}
