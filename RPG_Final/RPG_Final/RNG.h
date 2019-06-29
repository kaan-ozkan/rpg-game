#pragma once

#include <random>

class RNG {

public:
	typedef int rand_t;
	typedef float randf_t;

	// assign default constructor and destructors
	RNG() = default;
	~RNG() = default;

	// seed the mersenne twister engine for use
	RNG(std::mt19937::result_type seed) : eng(seed) { }

	// uniformly distribute numbers in range, use mersenne twister to pick
	// USAGE: pick(x, y) will return a random number between x and y both included. Order doesn't matter.
	rand_t pick(rand_t min, rand_t max) const {
		if (min > max)
			std::swap(min, max);
		return std::uniform_int_distribution<rand_t> {min, max} (eng);
	}

	// USAGE: pick(x, y) will return a random float between x and y both included. Order doesn't matter.
	randf_t pick_float(randf_t min, randf_t max) const {
		if (min > max)
			std::swap(min, max);
		return std::uniform_real_distribution<randf_t> {min, max} (eng);
	}

	// USAGE: chance(x) will return if something with X% chance has occured. False if it doesn't.
	bool chance(rand_t base) const {
		return std::uniform_int_distribution<rand_t> {1, 100} (eng) <= base;
	}

private:
	mutable std::mt19937 eng{ std::random_device{}() }; // mersenne twister is default
};
