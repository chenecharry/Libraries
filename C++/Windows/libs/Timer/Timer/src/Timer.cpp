#include "Timer.h"
#include<iostream>
#include<chrono>

// Lib by learncpp.com


// get an external constructor to work


Timer::Timer() : m_beg(clock_t::now()){   }


void Timer::reset() {
	m_beg = clock_t::now();
}

double Timer::elapsed() const {
	return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
}
