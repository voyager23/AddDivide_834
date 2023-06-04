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
	std::vector<ul> fact;	// return value from find_factors
	std::map<ul, std::vector<ul>> d_facts;	//dictionary of factors
	
	SieveOfEratosthenes(primes,10000U);
	
	// Constuct the dictionary up to 1000000UL
	for(n = 3; n != 1000000; ++n) {
		find_factors(primes,n,fact);
		auto r = d_facts.insert(std::pair<ul,std::vector<ul>>(n,fact));
		if(r.second == false) {
			printf("Insert failed.\n");
			exit(1);
		}
	}
		
	return 0;
}

