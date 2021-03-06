/***************************************************************************
 *   Copyright (C) 2008 by Ralf Kaestner                                   *
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

#include <string.h>
#include <sys/stat.h>

#include "path.h"

int file_path_exits(const char* path) {
  struct stat stat_buffer;
  return (stat(path, &stat_buffer) == 0);
}

int file_path_is_file(const char* path) {
  struct stat stat_buffer;  
  return ((stat(path, &stat_buffer) == 0) &&
    S_ISREG(stat_buffer.st_mode));
}

int file_path_is_directory(const char* path) {
  struct stat stat_buffer;  
  return ((stat(path, &stat_buffer) == 0) &&
    S_ISDIR(stat_buffer.st_mode));
}
