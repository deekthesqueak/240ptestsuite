/* 
 * 240p Test Suite
 * Copyright (C)2011 Artemio Urbina
 *
 * This file is part of the 240p Test Suite
 *
 * The 240p Test Suite is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * The 240p Test Suite is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with 240p Test Suite; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA	02111-1307	USA
 */

#include <kos.h>
#include <stdlib.h>
#include <dc/sound/sound.h>
#include <dc/sound/sfxmgr.h>

#include "controller.h"
#include "image.h"
#include "font.h"
#include "vmodes.h"
#include "vmu.h"

#include "patterns.h"

#include "help.h"


void DrawPluge();
void DrawWhiteScreen();
void DrawGrayRamp();
void DrawColorBars();
void Draw601ColorBars();
void DrawGrid();
void DrawLinearity();

void DrawPluge()
{
	int 				done = 0;
	uint16			oldbuttons, pressed;		
	ImagePtr		back;
	controller	*st;

	oldbuttons = InitController(0);
	back = LoadKMG("/rd/pluge.kmg.gz", 1);
	if(!back)
		return;
		
	updateVMU(" Pluge ", "", 1);
	while(!done) 
	{
		pvr_wait_ready();

		st = ReadController(0);
		if(st)
		{
			pressed = st->buttons & ~oldbuttons;
			oldbuttons = st->buttons;
					
			if (pressed & CONT_START)
				done =	1;								

			if(st->rtrig > 5)
				oldbuttons = HelpWindow(PLUGEHELP, back);
		}

		pvr_scene_begin();

		pvr_list_begin(PVR_LIST_TR_POLY);
		DrawImage(back);
		DrawScanlines();
		pvr_list_finish();				

		pvr_scene_finish();
	}
	FreeImage(&back);
	return;
}

void DrawGrayRamp()
{
	int 				done = 0;
	uint16			oldbuttons, pressed;		
	ImagePtr		back;
	controller	*st;

	oldbuttons = InitController(0);
	back = LoadKMG("/rd/grayramp.kmg.gz", 1);
	if(!back)
		return;
		
	updateVMU("Gray Ramp", "", 1);
	while(!done) 
	{
		pvr_wait_ready();

		st = ReadController(0);
		if(st)
		{
			pressed = st->buttons & ~oldbuttons;
			oldbuttons = st->buttons;
					
			if (pressed & CONT_START)
				done =	1;								

			if(st->rtrig > 5)
				oldbuttons = HelpWindow(GRAYRAMPHELP, back);
		}

		pvr_scene_begin();

		pvr_list_begin(PVR_LIST_TR_POLY);
		DrawImage(back);
		DrawScanlines();
		pvr_list_finish();				

		pvr_scene_finish();
	}
	FreeImage(&back);
	return;
}

void DrawWhiteScreen()
{
	int 				done = 0, color = 0;
	uint16			oldbuttons, pressed;		
	ImagePtr		back;
	controller	*st;

	oldbuttons = InitController(0);
	back = LoadKMG("/rd/white.kmg.gz", 1);
	if(!back)
		return;
		
	updateVMU("White scr", "", 1);
	while(!done) 
	{
		pvr_wait_ready();

		st = ReadController(0);
		if(st)
		{
			pressed = st->buttons & ~oldbuttons;
			oldbuttons = st->buttons;
					
			if (pressed & CONT_START)
				done =	1;								

			if (pressed & CONT_A)
				color ++;

			if (pressed & CONT_B)
				color --;
		}

		pvr_scene_begin();

		if(color > 4)
			color = 0;
		if(color < 0)
			color = 4;

		switch(color)
		{
				case 0:
					back->r = 1.0f;
					back->g = 1.0f;
					back->b = 1.0f;
					break;
				case 1:
					back->r = 0.0f;
					back->g = 0.0f;
					back->b = 0.0f;
					break;
				case 2:
					back->r = 1.0f;
					back->g = 0.0f;
					back->b = 0.0f;
					break;
				case 3:
					back->r = 0.0f;
					back->g = 1.0f;
					back->b = 0.0f;
					break;
				case 4:
					back->r = 0.0f;
					back->g = 0.0f;
					back->b = 1.0f;
					break;
		}

		pvr_list_begin(PVR_LIST_TR_POLY);
		DrawImage(back);
		DrawScanlines();
		pvr_list_finish();				

		pvr_scene_finish();
	}
	FreeImage(&back);
	return;
}

void DrawColorBars()
{
	int 				done = 0;
	uint16			oldbuttons, pressed;		
	ImagePtr		back;
	controller	*st;

	oldbuttons = InitController(0);
	back = LoadKMG("/rd/color.kmg.gz", 1);
	if(!back)
		return;
		
	updateVMU("Colorbars", "", 1);
	while(!done) 
	{
		pvr_wait_ready();

		st = ReadController(0);
		if(st)
		{
			pressed = st->buttons & ~oldbuttons;
			oldbuttons = st->buttons;
					
			if (pressed & CONT_START)
				done =	1;								

			if(st->rtrig > 5)
				oldbuttons = HelpWindow(COLORBARSHELP, back);
		}

		pvr_scene_begin();

		pvr_list_begin(PVR_LIST_TR_POLY);
		DrawImage(back);
		DrawScanlines();
		pvr_list_finish();				

		pvr_scene_finish();
	}
	FreeImage(&back);
	return;
}

void Draw601ColorBars()
{
	int 				done = 0;
	uint16			oldbuttons, pressed;		
	ImagePtr		back;
	controller	*st;

	oldbuttons = InitController(0);
	back = LoadKMG("/rd/601701cb.kmg.gz", 1);
	if(!back)
		return;
		
	updateVMU("Colorbars", "with gray", 1);
	while(!done) 
	{
		pvr_wait_ready();

		st = ReadController(0);
		if(st)
		{
			pressed = st->buttons & ~oldbuttons;
			oldbuttons = st->buttons;
					
			if (pressed & CONT_START)
				done =	1;								
		}

		pvr_scene_begin();

		pvr_list_begin(PVR_LIST_TR_POLY);
		DrawImage(back);
		DrawScanlines();
		pvr_list_finish();				

		pvr_scene_finish();
	}
	FreeImage(&back);
	return;
}

void DrawGrid()
{
	int 				done = 0;
	uint16			oldbuttons, pressed;		
	ImagePtr		back;
	char				msg[20];
	controller	*st;

	oldbuttons = InitController(0);
	if(vmode != NATIVE_640_FS)
	{
		back = LoadKMG("/rd/grid.kmg.gz", 1);
		if(!back)
			return;
	}
	else
	{
		back = LoadKMG("/rd/480/grid-480.kmg.gz", 1);
		if(!back)
			return;
		back->scale = 0;
	}

	updateVMU(" 	Grid	", "", 1);
	while(!done) 
	{
		pvr_wait_ready();

		st = ReadController(0);
		if(st)
		{
			pressed = st->buttons & ~oldbuttons;
			oldbuttons = st->buttons;
					
			if (pressed & CONT_START)
				done =	1;								
			if (pressed & CONT_A)
			{
				back->x = 0.0f;
				back->y = 0.0f;
			}
			if (pressed & CONT_DPAD_UP)
				back->y -= 1.0f;
			if (pressed & CONT_DPAD_DOWN)
				back->y += 1.0f;
			if (pressed & CONT_DPAD_LEFT)
				back->x -= 1.0f;
			if (pressed & CONT_DPAD_RIGHT)
				back->x += 1.0f;
			if (st->rtrig > 5)
				oldbuttons = HelpWindow(GRIDHELP, back);
		}

		pvr_scene_begin();

		pvr_list_begin(PVR_LIST_TR_POLY);
		DrawImage(back);
		if(back->x != 0.0f || back->y != 0.0f)
		{
			sprintf(msg, "%d,%d", (int)back->x, (int)back->y);
			DrawStringB(275.0f, 5.0f, 1.0f, 1.0f,	1.0f, msg);
		}
		DrawScanlines();
		pvr_list_finish();				

		pvr_scene_finish();
	}

	FreeImage(&back);
	return;
}

void DrawLinearity()
{
	int 				done = 0, gridpattern = 0, showgrid = 1;
	uint16			oldbuttons, pressed;
	ImagePtr		circles, grid, gridd;
	controller	*st;

	oldbuttons = InitController(0);
	circles = LoadKMG("/rd/circles.kmg.gz", 1);
	if(!circles)
		return;
	grid = LoadKMG("/rd/circles_grid.kmg.gz", 1);
	if(!grid)
		return;
	gridd = LoadKMG("/rd/circles_griddot.kmg.gz", 1);
	if(!gridd)
		return;
	grid->w = 320;
	grid->h = 240;
	gridd->w = 320;
	gridd->h = 240;
		
	updateVMU("Linearity", "", 1);
	while(!done) 
	{
		pvr_wait_ready();

		st = ReadController(0);
		if(st)
		{
			pressed = st->buttons & ~oldbuttons;
			oldbuttons = st->buttons;
					
			if (pressed & CONT_A)
				showgrid = !showgrid;
		
			if (pressed & CONT_B)
				gridpattern = !gridpattern;
		
			if (pressed & CONT_START)
				done =	1;				
		}
						
		pvr_scene_begin();

		pvr_list_begin(PVR_LIST_TR_POLY);
		if(showgrid)
		{
			if(gridpattern)
				DrawImage(gridd);
			else
				DrawImage(grid);
		}
		DrawImage(circles);
		DrawScanlines();
		pvr_list_finish();				

		pvr_scene_finish();
	}

	FreeImage(&gridd);
	FreeImage(&grid);
	FreeImage(&circles);
	return;
}


