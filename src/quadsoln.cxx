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

void determ_v2(const int64_t n, std::vector<ul> &primes, std::vector<ul> &factors) {
	int64_t b_sq, ac4, q, m1,m2,m1_max = n*n -2*n;
	double_t  dd, determ;
	printf("====================\nN = %ld\n",n);
	q = 1;
	while(true) {
		b_sq = (2*n - 2*q + 1) * (2*n - 2*q + 1);
		ac4 = 8*n*(1-q);
		determ = std::sqrt(b_sq - ac4);
		if(determ == std::floor(determ)) {
			// From determinant calculate 2 values of m
			printf("V2 q:%ld determ:%ld\n", q, (int64_t)determ);
			m1 = (-(2*n - 2*q + 1) + (int64_t)determ) / 2;
			m2 = (-(2*n - 2*q + 1) - (int64_t)determ) / 2;
			printf("m1:%ld  m2:%ld\n",m1,m2);
			// find and print the factors of m
			factors.clear();
			find_factors(primes, m1, factors);
			printf("m1 => ");
			for(auto i = factors.begin(); i != factors.end(); ++i) printf("%lu ",*i);
			printf("\n\n");
			if(m1 == m1_max) break;
		}//~if
		q += 1;
	}//~while
}//~determ_v2

int main(int argc, char **argv)
{
	std::vector<ul> primes;
	std::vector<ul> factors;
	SieveOfEratosthenes(primes,100000UL);
	
	for(ul n = 380; n != 400; ++n)
		determ_v2(n, primes, factors);
	return 0;
}

