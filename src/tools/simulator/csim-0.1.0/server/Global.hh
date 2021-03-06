/*
 *  Gazebo - Outdoor Multi-Robot Simulator
 *  Copyright (C) 2003  
 *     Nate Koenig & Andrew Howard
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */
/* Desc: Generic Typedefs, macros, functions, etc
 * Author: Nate Koenig
 * Date: 16 June 2003
 * CVS: $Id: Global.hh 8443 2009-11-24 19:39:13Z natepak $
 */

#ifndef GZGLOBAL_HH
#define GZGLOBAL_HH

/////////////////////////////////////////////////////////////////////////////
// Includes
/////////////////////////////////////////////////////////////////////////////

#include <math.h>

#include "GazeboError.hh"
#include "GazeboMessage.hh"


/////////////////////////////////////////////////////////////////////////////
// Defines
/////////////////////////////////////////////////////////////////////////////
#ifndef NULL
#define NULL 0
#endif

#ifndef GZ_COLLIDE_BITS

#define GZ_ALL_COLLIDE 0x0FFFFFFF
#define GZ_NONE_COLLIDE 0x00000000
#define GZ_FIXED_COLLIDE 0x00000001
#define GZ_SENSOR_COLLIDE 0x00000002
#define GZ_GHOST_COLLIDE 0x10000000

#endif

#ifndef GZ_CAMERA_BITS

#define GZ_ALL_CAMERA 0xFFFFFFFF
#define GZ_LASER_CAMERA 0x00000001

#endif

/////////////////////////////////////////////////////////////////////////////
// Macros
/////////////////////////////////////////////////////////////////////////////

// Convert radians to degrees
#define RTOD(r) ((r) * 180 / M_PI)

// Convert degrees to radians
#define DTOR(d) ((d) * M_PI / 180)

// Normalize an angle in the range -Pi to Pi
#define NORMALIZE(a) (atan2(sin(a), cos(a)))

// Odd and even macros
#define ISEVEN(x) ( ((x) % 2) == 0)
#define ISODD(x) ( ((x) % 2) != 0)

#define ROUND(x) ( (int)( floor((x)+0.5) ) )

#undef USE_THREADPOOL

#endif
