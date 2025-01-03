// This file is part of the ClayNDS project.
//
// (c) 2025 Tommaso Dimatore
//
// For the full copyright and license information, please view the LICENSE
// file that was distributed with this source code.

#ifndef __CLAYNDS_H
#define __CLAYNDS_H

#include <stdio.h>
#include <stdlib.h>

#include <gl2d.h>
#include <nds.h>

#include "clay.h"

#define ClayNDSi__CLAY_COLOR_TO_RGB15(cc) RGB15((u8)(cc.r / 8.f), (u8)(cc.g / 8.f), (u8)(cc.b / 8.f))

static void ClayNDS_Render(Clay_RenderCommandArray renderCommands)
{
  for (u32 i = 0; i < renderCommands.length; i++)
  {
    Clay_RenderCommand* renderCommand = Clay_RenderCommandArray_Get(&renderCommands, i);
    Clay_BoundingBox box = renderCommand->boundingBox;

    switch (renderCommand->commandType)
    {
    case CLAY_RENDER_COMMAND_TYPE_RECTANGLE: {
      Clay_RectangleElementConfig* config = renderCommand->config.rectangleElementConfig;
      u16 color = ClayNDSi__CLAY_COLOR_TO_RGB15(config->color);
      break;
    }
    default: {
      fprintf(stderr, "error: unhandled render command: %d\n", renderCommand->commandType);
      exit(1);
    }
    }
  }
}

#endif // __CLAYNDS_H
