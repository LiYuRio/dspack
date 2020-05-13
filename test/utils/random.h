#pragma once
#include <memory>
#include <random>

template <typename T>
void random_uniform(T *values, int nums, float a, float b) {
  int random_seed = std::random_device{}();
  std::unique_ptr<std::mt19937> random_generator;
  random_generator.reset(new std::mt19937(random_seed));
  std::uniform_real_distribution<float> distribution(a, b);
  for (int i = 0; i < nums; i++) {
    values[i] = static_cast<T>(distribution(*random_generator.get()));
  }

}
template <typename T>
void random_normal(T *values, int nums, float a, float b) {
  int random_seed = std::random_device{}();
  std::unique_ptr<std::mt19937> random_generator;
  random_generator.reset(new std::mt19937(random_seed));
  std::normal_distribution<float> distribution(a, b);
  for (int i = 0; i < nums; i++) {
    values[i] = static_cast<T>(distribution(*random_generator.get()));
  }
}