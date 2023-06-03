/*
 * fs_s.cxx
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
#include "../inc/toolbox.hxx"


int main(int argc, char **argv)
{
	ul n,m,z,c,r;
	ul S[5] = { 24, 39, 104, 299, 624 };
	std::vector<ul> primes;
	std::vector<ul> factors;
	
	SieveOfEratosthenes(primes,10000U);
	find_factors(primes,125,factors);
	for(auto i = factors.begin(); i != factors.end(); ++i)
	{
		printf("%lu ",*i);
	}
	printf("\n");
	return 0;
}

