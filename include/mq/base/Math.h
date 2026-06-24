/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2023 MacroQuest Authors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2, as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#pragma once

#include "mq/base/Deprecation.h"

#include <cmath>

namespace mq {

/**
 * @brief Calculates and returns the 2D Euclidean distance between two points in a 2D space.
 *
 * @note If you don't need the actual distance, but only need to compare distances, you should
 * use GetDistanceSquared instead.
 *
 * @param X1 The X coordinate of the first point.
 * @param Y1 The Y coordinate of the first point.
 * @param X2 The X coordinate of the second point.
 * @param Y2 The Y coordinate of the second point.
 * @return float The 2D Euclidean distance between the two points.
 */
inline float GetDistance(float X1, float Y1, float X2, float Y2)
{
	float dX = X1 - X2;
	float dY = Y1 - Y2;
	return sqrtf(dX * dX + dY * dY);
}

/**
 * @brief Calculates and returns the 3D Euclidean distance between two points in a 3D space.
 *
 * @note If you don't need the actual distance, but only need to compare distances, you should
 * use GetDistanceSquared instead.
 *
 * @param X1 The X coordinate of the first point.
 * @param Y1 The Y coordinate of the first point.
 * @param Z1 The Z coordinate of the first point.
 * @param X2 The X coordinate of the second point.
 * @param Y2 The Y coordinate of the second point.
 * @param Z2 The Z coordinate of the second point.
 * @return float The 3D Euclidean distance between the two points.
 */
inline float GetDistance(float X1, float Y1, float Z1, float X2, float Y2, float Z2)
{
	float dX = X1 - X2;
	float dY = Y1 - Y2;
	float dZ = Z1 - Z2;
	return sqrtf(dX * dX + dY * dY + dZ * dZ);
}

DEPRECATE("Use GetDistance instead.")
inline float GetDistance3D(float X1, float Y1, float Z1, float X2, float Y2, float Z2)
{
	return GetDistance(X1, Y1, Z1, X2, Y2, Z2);
}

DEPRECATE("Use GetDistance instead.")
inline float Get3DDistance(float X1, float Y1, float Z1, float X2, float Y2, float Z2)
{
	return GetDistance(X1, Y1, Z1, X2, Y2, Z2);
}

/**
 * @brief [2D] Calculates and returns the squared Euclidean distance between two points in a 2D space.
 *
 * @note This function is often used when comparing distances, as squaring is cheaper than taking the square root.
 * If you actually need the distance, use the GetDistance function instead.
 *
 * @param X1 The X coordinate of the first point.
 * @param Y1 The Y coordinate of the first point.
 * @param X2 The X coordinate of the second point.
 * @param Y2 The Y coordinate of the second point.
 * @return float The squared Euclidean distance between the two points.
 */
inline float GetDistanceSquared(float X1, float Y1, float X2, float Y2)
{
	float dX = X1 - X2;
	float dY = Y1 - Y2;
	return dX * dX + dY * dY;
}

/**
 * @brief [3D] Calculates and returns the squared Euclidean distance between two points in a 3D space.
 *
 * @note This function is often used when comparing distances, as squaring is cheaper than taking the square root.
 * If you actually need the distance, use the GetDistance function instead.
 *
 * @param X1 The X coordinate of the first point.
 * @param Y1 The Y coordinate of the first point.
 * @param Z1 The Z coordinate of the first point.
 * @param X2 The X coordinate of the second point.
 * @param Y2 The Y coordinate of the second point.
 * @param Z2 The Z coordinate of the second point.
 * @return float The squared Euclidean distance between the two points.
 */
inline float GetDistanceSquared(float X1, float Y1, float Z1, float X2, float Y2, float Z2)
{
	float dX = X1 - X2;
	float dY = Y1 - Y2;
	float dZ = Z1 - Z2;
	return dX * dX + dY * dY + dZ * dZ;
}

DEPRECATE("Use GetDistanceSquared instead")
inline float Get3DDistanceSquared(float X1, float Y1, float Z1, float X2, float Y2, float Z2)
{
	return GetDistanceSquared(X1, Y1, Z1, X2, Y2, Z2);
}

} // namespace mq
