#pragma once
#include <random>
#include <thread>

namespace rdm {
	class random {
	public:
		static std::mt19937& get_engine() {
			thread_local std::mt19937 engine(std::random_device{}());
			return engine;
		}

		template<typename T> requires std::is_arithmetic_v<T>
		static T next(T min, T max) {
			if (min > max) std::swap(min, max);

			if constexpr (std::is_integral_v<T>) {
				std::uniform_int_distribution<T>dist(min, max);
				return dist(get_engine());
			}
			else {
				std::uniform_real_distribution<T> dist(min, max);
				return dist(get_engine());
			}
		}

		static bool nextBoolean(double probability = 0.5) {
			std::bernoulli_distribution dist(probability);
			return dist(get_engine());
		}
	};
}