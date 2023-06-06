/*
 * quadsoln.cxx
 * 
 * Copyright 2023 mike <mike@pop-os>
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
#include <ostream>
#include <cmath>

#include "../inc/toolbox.hxx"

void determ_v1() {
	ul b_sq, ac4, q, m;
	double_t  dd, determ;
	for(q = 1; q != 135; ++q) {
		b_sq = (25 - q) * (25 - q);
		ac4  = 4 * (24 - 12*q);
		determ = std::sqrt(b_sq - ac4);
		if(determ == std::floor(determ))
			printf("dd: %lu q:%lu dterm:%f\n",(b_sq - ac4), q, determ);
	}
}

void determ_v2() {
	ul b_sq, ac4, q, m;
	double_t  dd, determ;
	const ul n = 12;	// set sequence base
	for(q = 1; q != 135; ++q) {
		b_sq = (2*n - 2*q + 1) * (2*n - 2*q + 1);
		ac4 = 8*n*(1-2*q);
		determ = std::sqrt(b_sq - ac4);
		if(determ == std::floor(determ))
			printf("V2 q:%lu dd: %lu dterm:%f\n", q, (b_sq - ac4), determ);
	}
}

int main(int argc, char **argv)
{
	determ_v2();
	return 0;
}

