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
#define UL unsigned long

int main(int argc, char **argv)
{
	UL a,n,m,r;
	for(n = 3; n < 100; ++n)
	{
		printf("s(%lu) {",n);
		a = n;
		for(m = 1; m < 1000000; ++m)
		{
			a = a + (n + m);
			if ((a % (n+m))==0) { printf(" %lu",m); }
		}
		printf(" }\n");
	}
	return 0;
}

