//
// Created by Dmitry Morozov on 27/8/22.
//

#include "gtest/gtest.h"

#include "shared/RegionsBase.hpp"
#include "shared/Region.hpp"


TEST (RegionsBase, testCounter) {
    std::vector<Region> regionsBase = {
            {
                    "Moscow",
                    "Russia",
                    {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                    89
            },
            {
                    "Russia",
                    "Eurasia",
                    {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
                    89
            },
            {
                    "Moscow",
                    "Russia",
                    {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                    89
            },
            {
                    "Moscow",
                    "Russia",
                    {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                    89
            },
            {
                    "Russia",
                    "Eurasia",
                    {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
                    89
            },
    };

    EXPECT_EQ (FindMaxRepetitionCount (regionsBase), 3);

    regionsBase = {
            {
                    "Moscow",
                    "Russia",
                    {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"},      {Lang::IT, "Mosca"}},
                    89
            },
            {
                    "Russia",
                    "Eurasia",
                    {{Lang::DE, "Russland"}, {Lang::FR, "Russie"},      {Lang::IT, "Russia"}},
                    89
            },
            {
                    "Moscow",
                    "Russia",
                    {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
                    89
            },
            {
                    "Moscow",
                    "Toulouse",
                    {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"},      {Lang::IT, "Mosca"}},
                    89
            },
            {
                    "Moscow",
                    "Russia",
                    {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"},      {Lang::IT, "Mosca"}},
                    31
            },
    };

    EXPECT_EQ (FindMaxRepetitionCount (regionsBase), 1);


}
