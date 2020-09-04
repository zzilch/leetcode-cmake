#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch.h"
#include "L0001.h"

#include <random>

TEST_CASE("L0001", "[L]")
{
    Solution solution;
    vector<int> nums;
    int target;
    vector<int> output;
    std::tie(nums, target, output) = GENERATE(
        make_tuple(vector{2, 7, 11, 15}, 9, vector{0, 1}),
        make_tuple(vector{3, 2, 4}, 6, vector{1, 2}),
        make_tuple(vector{3, 3}, 6, vector{0, 1}));

    SECTION("Brute Force")
    {
        REQUIRE(solution.twoSum_BF(nums, target) == output);
    }

    SECTION("Hash Map")
    {
        REQUIRE(solution.twoSum_Hash(nums, target) == output);
    }

    SECTION("Hash Map2")
    {
        REQUIRE(solution.twoSum_Hash2(nums, target) == output);
    }
}

TEST_CASE("L0001_Benchmark", "[B]")
{
    Solution solution;
    int n = 10000;
    random_device rd;
    default_random_engine dre(rd());
    uniform_int_distribution uid(0, n - 1);

    BENCHMARK_ADVANCED("Brute Force")
    (Catch::Benchmark::Chronometer meter)
    {
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            nums[i] = uid(dre);
        vector<int> output{uid(dre), uid(dre)};
        int target = nums[output[0]] + nums[output[1]];
        meter.measure([&] { return solution.twoSum_BF(nums, target); });
    };

    BENCHMARK_ADVANCED("Hash Map")
    (Catch::Benchmark::Chronometer meter)
    {
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            nums[i] = uid(dre);
        vector<int> output{uid(dre), uid(dre)};
        int target = nums[output[0]] + nums[output[1]];
        meter.measure([&] { return solution.twoSum_Hash(nums, target); });
    };

    BENCHMARK_ADVANCED("Hash Map2")
    (Catch::Benchmark::Chronometer meter)
    {
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            nums[i] = uid(dre);
        vector<int> output{uid(dre), uid(dre)};
        int target = nums[output[0]] + nums[output[1]];
        meter.measure([&] { return solution.twoSum_Hash2(nums, target); });
    };
}
