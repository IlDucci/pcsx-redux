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

#include "ImGuiColorTextEdit/TextEditor.h"
#include "imgui.h"

namespace PCSX {
namespace Widgets {

class VRAMViewer {
  public:
    void init();
    void drawVRAM(unsigned int textureID, ImVec2 dimensions);
    void resetView() {
        m_cornerTL = {0.0f, 0.0f};
        m_cornerBR = {1.0f, 1.0f};
    }
    void drawEditor();
    void destroy();

  private:
    void compileShader(const char *VS, const char *PS);
    static void imguiCBtrampoline(const ImDrawList *parentList, const ImDrawCmd *cmd) {
        VRAMViewer *that = reinterpret_cast<VRAMViewer *>(cmd->UserCallbackData);
        that->imguiCB(parentList, cmd);
    }
    void imguiCB(const ImDrawList *parentList, const ImDrawCmd *cmd);

    unsigned int m_vertexShader = 0;
    unsigned int m_pixelShader = 0;
    unsigned int m_shaderProgram = 0;
    int m_attribLocationTex;
    int m_attribLocationProjMtx;
    int m_attribLocationVtxPos;
    int m_attribLocationVtxUV;
    int m_attribLocationHovered;
    int m_attribLocationMousePos;
    int m_attribLocationMouseUV;
    int m_attribLocationResolution;
    int m_attribLocationOrigin;
    int m_attribLocationMagnify;
    int m_attribLocationMagnifyRadius;
    int m_attribLocationMagnifyAmount;
    int m_attribLocationCornerTL;
    int m_attribLocationCornerBR;

    bool m_hovered = false;
    bool m_magnify = false;
    float m_magnifyAmount = 5.0f;
    float m_magnifyRadius = 150.0f;
    ImVec2 m_mousePos;
    ImVec2 m_resolution;
    ImVec2 m_origin;
    ImVec2 m_cornerTL = {0.0f, 0.0f};
    ImVec2 m_cornerBR = {1.0f, 1.0f};
    unsigned int m_textureID;
    TextEditor m_vertexShaderEditor;
    TextEditor m_pixelShaderEditor;

    std::string m_errorMessage;
};

}  // namespace Widgets
}  // namespace PCSX
