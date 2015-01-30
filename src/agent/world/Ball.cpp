/*
 * Copyright (C) 2009-2015,
 * Intelligent Robotics and Intelligent Systems (IRIS) Lab
 * CAMBADA robotic soccer team – http://robotica.ua.pt/CAMBADA/
 * University of Aveiro, Portugal
 *
 * This file is part of the CAMBADA AGENT
 *
 * CAMBADA AGENT is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CAMBADA AGENT is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this package.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Ball.h"

namespace cambada {

Ball::Ball() {
	clear();
}

void Ball::clear() {
	pos			= Vec::zero_vector;
	posRel		= Vec::zero_vector;
	vel			= Vec::zero_vector;

	height		= 0.0f;
	own			= false;
	engaged		= false;
	visible		= false;
	airborne	= false;

	hasMoved	= false;
}

float Ball::distance() {
	return posRel.length();
}

} /* namespace cambada */
