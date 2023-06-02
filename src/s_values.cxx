/*
 * s_find.cxx
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
#define UL unsigned long

int main(int argc, char **argv)
{
	UL n,m,z,c,r;

	n = 26;
	UL S[5] = { 24, 39, 104, 299, 624 };
	for (int i = 0; i < std::size(S); ++i)
	{
		S[i] = (2*n*(S[i] + 1) + S[i]*S[i] + S[i]);
		printf("%lu ",S[i]);
	}
	printf("\n");
	return 0;
}

