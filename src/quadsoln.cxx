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

void quad_solve(int64_t n, std::set<int64_t>* squares, std::vector<int64_t>* m_values ) {
	int64_t m_max = n * (n - 2);
	m_values->clear();
	// The term associated with m_max is(m+1)(m+2*n)
	int64_t m_max_term = (2*n*(m_max+1) + m_max*m_max + m_max) / 2;
	int64_t q_max = m_max_term / (n + m_max);
	// now consider the determinant of the quadratic eqn. for m
	// 4q^2 - q(8n + 4) + (2n - 1)^2 = Z^2
	// here a = 4, b = (8n + 4), c = (2n - 1)^2
	for(int64_t q = 2; q <= q_max; ++q) {
		int64_t ZZ = 4*q*q - q*(8*n + 4) + (2*n + 1)*(2*n + 1);
		if(squares->contains( ZZ ) == true) {
			// now have the value for q
			// subs in m^2 + m(2n - 2q + 1) + 2n(1 - q)
			// where: a = 1, b = (2n - 2q + 1) and c = 2n(1 - q)
			std::vector<double_t> roots = solve_quadratic(1.0, (2.0*n - 2.0*q + 1), (2.0*n * (1.0 - q)));
			for(auto i = roots.begin(); i != roots.end(); ++i)
				if( (*i - floor(*i) == 0.0) ) {
					std::cout << *i << " ";
					break;
				}
		} //~if
	} //~for
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	std::vector<ul> primes;
	std::vector<ul> factors;
	SieveOfEratosthenes(primes,100000UL);
	
	std::set<int64_t> squares;
	for(int64_t s = 1; s != 50000; ++s) squares.insert(s*s);
	std::vector<int64_t> m_values;
	
	for(int64_t n = 20000; n <= 21000; n+=10)
		quad_solve(n, &squares, &m_values);
	
	
	
	//~ for(ul n = 10; n != 11; ++n)
		//~ determ_v2(n, primes, factors);
	//~ return 0;
}

