/***************************************************************************
 *   Copyright (C) 2004 by Ralf Kaestner                                   *
 *   ralf.kaestner@gmail.com                                               *
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
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <stdio.h>

#include "config/parser.h"
#include "ftdi/ftdi.h"

int main(int argc, char **argv) {
  config_parser_t parser;
  int i;

  config_parser_init_default(&parser, "List FTDI devices",
    "The command displays lsusb-like information about USB buses in "
    "the system and the FTDI devices connected to them.");
  config_parser_parse(&parser, argc, argv, config_parser_exit_both);
  
  ftdi_context_init(ftdi_default_context);
  if (ftdi_default_context->num_devices) {
    for (i = 0; i < ftdi_default_context->num_devices; ++i)
      ftdi_print(stdout, &ftdi_default_context->devices[i]);
  }
  else
    fprintf(stdout, "No devices found.\n");

  ftdi_context_release(ftdi_default_context);
  return 0;
}
