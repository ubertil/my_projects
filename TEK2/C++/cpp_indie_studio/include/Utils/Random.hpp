//
// Created by uberti_l on 5/22/17.
//

#pragma once
# include <random>

namespace Sprint
{
    namespace Utils
    {
        class Random
        {
        public:
            static Random       &getInstance()
            {
                static Random   instance;

                return (instance);
            }

            int                 getNb(const int lower_bound, const int upper_bound)
            {
                rng.seed(std::random_device()());
                std::uniform_int_distribution<std::mt19937::result_type> res(static_cast<unsigned>(lower_bound),
                                                                             static_cast<unsigned>(upper_bound));
                return (static_cast<int>(res(this->rng)));
            }

        private:
            Random() = default;
            Random(const Random &cpy) = delete;
            Random  operator&(const Random &cpy) = delete;
            ~Random() = default;

            std::mt19937        rng;
        };
    };
};
