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

/**
 * @brief Calculates and returns the 3D Euclidean distance between two glm::vec3 points in a 3D space.
 *
 * @note If you don't need the actual distance, but only need to compare distances, you should
 * use GetDistanceSquared instead.
 *
 * @param first The first glm::vec3 point.
 * @param second The second glm::vec3 point.
 * @return float The 3D Euclidean distance between the two glm::vec3 points.
 */
inline float GetDistance(const glm::vec3& first, const glm::vec3& second)
{
	return GetDistance(first.x, first.y, first.z, second.x, second.y, second.z);
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
 * @brief Calculates and returns the 2D Euclidean distance between the positions of two spawns.
 * 
 * @note If you don't need the actual distance, but only need to compare distances, you should
 * use GetDistanceSquared2D instead.
 *
 * @param spawn1 The first spawn.
 * @param spawn2 The second spawn.
 * @return float The 2D Euclidean distance between the positions of the two spawns.
 */
inline float GetDistance2D(const SPAWNINFO* spawn1, const SPAWNINFO* spawn2)
{
	if (!spawn1 || !spawn2)
		return 0.0f;

	return GetDistance(spawn1->X, spawn1->Y, spawn2->X, spawn2->Y);
}

/**
 * @brief Calculates and returns the 3D Euclidean distance between the positions of two spawns.
 *
 * @note If you don't need the actual distance, but only need to compare distances, you should
 * use GetDistanceSquared3D instead.
 *
 * @param spawn1 The first spawn.
 * @param spawn2 The second spawn.
 * @return float The 3D Euclidean distance between the positions of the two spawns.
 */
inline float GetDistance3D(const SPAWNINFO* spawn1, const SPAWNINFO* spawn2)
{
	if (!spawn1 || !spawn2)
		return 0.0f;

	return GetDistance(spawn1->X, spawn1->Y, spawn1->Z, spawn2->X, spawn2->Y, spawn2->Z);
}

/**
 * @brief Calculates and returns the 2D Euclidean distance between the positions of a spawn and a game object.
 *
 * @note If you don't need the actual distance, but only need to compare distances, you should
 * use GetDistanceSquared2D instead.
 *
 * @param spawn The first spawn.
 * @param gameObj The game object.
 * @return float The 2D Euclidean distance between the positions of the spawn and game object.
 */
inline float GetDistance2D(const SPAWNINFO* spawn, const MQGameObject& gameObj)
{
	if (!spawn)
		return 0.0f;

	return GetDistance(spawn->X, spawn->Y, gameObj.x, gameObj.y);
}

/**
 * @brief Calculates and returns the 3D Euclidean distance between the positions of a spawn and a game object.
 *
 * @note If you don't need the actual distance, but only need to compare distances, you should
 * use GetDistanceSquared3D instead.
 *
 * @param spawn The first spawn.
 * @param gameObj The game object.
 * @return float The 3D Euclidean distance between the positions of the spawn and game object.
 */
inline float GetDistance3D(const SPAWNINFO* spawn, const MQGameObject& gameObj)
{
	if (!spawn)
		return 0.0f;

	return GetDistance(spawn->X, spawn->Y, spawn->Z, gameObj.x, gameObj.y, gameObj.z);
}

DEPRECATE("Use GetDistance2D instead.")
inline float GetDistance(SPAWNINFO* spawn1, SPAWNINFO* spawn2)
{
	return GetDistance2D(spawn1, spawn2);
}

DEPRECATE("Use GetDistance2D instead.")
inline float DistanceToSpawn(SPAWNINFO* pChar, SPAWNINFO* pSpawn)
{
	return GetDistance2D(pChar, pSpawn);
}

template <typename T1, typename T2>
DEPRECATE("Use GetDistance3D instead.")
inline float Distance3DToSpawn(const T1& pSpawn1, const T2& pSpawn2)
{
	return GetDistance3D(pSpawn1, pSpawn2);
}

template <typename T1>
DEPRECATE("Use GetDistance3D instead.")
inline float Distance3DToSpawn(const T1& pSpawn1, const MQGameObject& gameObj)
{
	return GetDistance(
		pSpawn1->X, pSpawn1->Y, pSpawn1->Z,
		gameObj.x, gameObj.y, gameObj.z);
}

/**
 * @brief Calculates and returns the 2D Euclidean distance between a point in a 2D space and the player's position.
 *
 * @note If you don't need the actual distance, but only need to compare distances, you should
 * use GetDistanceSquaredFromPlayer instead.
 *
 * @param X1 The X coordinate of the point.
 * @param Y1 The Y coordinate of the point.
 * @return float The 2D Euclidean distance between the point and the player's position.
 */
inline float GetDistanceFromPlayer(float X1, float Y1)
{
	if (!pControlledPlayer)
		return 0.0f;

	return GetDistance(X1, Y1, pControlledPlayer->X, pControlledPlayer->Y);
}

/**
 * @brief Calculates and returns the 3D Euclidean distance between a point in a 3D space and the player's position.
 *
 * @note If you don't need the actual distance, but only need to compare distances, you should
 * use GetDistanceSquaredFromPlayer instead.
 *
 * @param X1 The X coordinate of the point.
 * @param Y1 The Y coordinate of the point.
 * @param Z1 The Z coordinate of the point.
 * @return float The 3D Euclidean distance between the point and the player's position.
 */
inline float GetDistanceFromPlayer(float X1, float Y1, float Z1)
{
	if (!pControlledPlayer)
		return 0.0f;

	return GetDistance(X1, Y1, Z1, pControlledPlayer->X, pControlledPlayer->Y, pControlledPlayer->Z);
}

DEPRECATE("Use GetDistanceFromPlayer instead.")
inline float GetDistance(float X1, float Y1)
{
	return GetDistanceFromPlayer(X1, Y1);
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

/**
 * @brief [3D] Calculates and returns the squared Euclidean distance between two glm::vec3 points in a 3D space.
 *
 * @note This function is often used when comparing distances, as squaring is cheaper than taking the square root.
 * If you actually need the distance, use the GetDistance function instead.
 *
 * @param first The glm::vec3 coordinate of the first point.
 * @param second The glm::vec3 coordinate of the second point.
 * @return float The squared Euclidean distance between the two points.
 */
inline float GetDistanceSquared(const glm::vec3& first, const glm::vec3& second)
{
	return GetDistanceSquared(first.x, first.y, first.z, second.x, second.y, second.z);
}

/**
 * @brief [2D] Calculates and returns the squared Euclidean distance between two spawns in a 2D space.
 *
 * @note This function is often used when comparing distances, as squaring is cheaper than taking the square root.
 * If you actually need the distance, use the GetDistance2D function instead.
 *
 * @param spawn1 The first spawn.
 * @param spawn2 The second spawn.
 * @return float The squared Euclidean distance between the two points.
 */
inline float GetDistanceSquared2D(const SPAWNINFO* spawn1, const SPAWNINFO* spawn2)
{
	if (!spawn1 || !spawn2)
		return 0.0f;

	return GetDistanceSquared(spawn1->X, spawn1->Y, spawn2->X, spawn2->Y);
}

/**
 * @brief [3D] Calculates and returns the squared Euclidean distance between two spawns in a 3D space.
 *
 * @note This function is often used when comparing distances, as squaring is cheaper than taking the square root.
 * If you actually need the distance, use the GetDistance3D function instead.
 *
 * @param spawn1 The first spawn.
 * @param spawn2 The second spawn.
 * @return float The squared Euclidean distance between the two points.
 */
inline float GetDistanceSquared3D(const SPAWNINFO* spawn1, const SPAWNINFO* spawn2)
{
	if (!spawn1 || !spawn2)
		return 0.0f;

	return GetDistanceSquared(spawn1->X, spawn1->Y, spawn1->Z, spawn2->X, spawn2->Y, spawn2->Z);
}

/**
 * @brief [2D] Calculates and returns the squared Euclidean distance between a spawn and game object in a 2D space.
 *
 * @note This function is often used when comparing distances, as squaring is cheaper than taking the square root.
 * If you actually need the distance, use the GetDistance2D function instead.
 *
 * @param spawn The spawn.
 * @param gameObj The game object.
 * @return float The squared Euclidean distance between the two points.
 */
inline float GetDistanceSquared2D(const SPAWNINFO* spawn, const MQGameObject& gameObj)
{
	if (!spawn)
		return 0.0f;

	return GetDistanceSquared(spawn->X, spawn->Y, gameObj.x, gameObj.y);
}

/**
 * @brief [3D] Calculates and returns the squared Euclidean distance between a spawn and game object in a 3D space.
 *
 * @note This function is often used when comparing distances, as squaring is cheaper than taking the square root.
 * If you actually need the distance, use the GetDistance3D function instead.
 *
 * @param spawn The spawn.
 * @param gameObj The game object.
 * @return float The squared Euclidean distance between the two points.
 */
inline float GetDistanceSquared3D(const SPAWNINFO* spawn, const MQGameObject& gameObj)
{
	if (!spawn)
		return 0.0f;

	return GetDistanceSquared(spawn->X, spawn->Y, spawn->Z, gameObj.x, gameObj.y, gameObj.z);
}

DEPRECATE("Use GetDistanceSquared2D instead")
inline float GetDistanceSquared(SPAWNINFO* pChar, SPAWNINFO* pSpawn)
{
	return GetDistanceSquared2D(pChar, pSpawn);
}

DEPRECATE("Use GetDistanceSquared instead")
inline float Get3DDistanceSquared(float X1, float Y1, float Z1, float X2, float Y2, float Z2)
{
	return GetDistanceSquared(X1, Y1, Z1, X2, Y2, Z2);
}

/**
 * @brief [2D] Calculates and returns the squared Euclidean distance between a point in a 2D space and the player's position.
 *
 * @note This function is often used when comparing distances, as squaring is cheaper than taking the square root.
 * If you actually need the distance, use the GetDistanceFromPlayer function instead.
 *
 * @param X1 The X coordinate of the point.
 * @param Y1 The Y coordinate of the point.
 * @return float The squared Euclidean distance between the point and the player's position.
 */
inline float GetDistanceSquaredFromPlayer(float X1, float Y1)
{
	if (!pControlledPlayer)
		return 0.0f;

	return GetDistanceSquared(X1, Y1, pControlledPlayer->X, pControlledPlayer->Y);
}

/**
 * @brief [3D] Calculates and returns the squared Euclidean distance between a point in a 3D space and the player's position.
 *
 * @note This function is often used when comparing distances, as squaring is cheaper than taking the square root.
 * If you actually need the distance, use the GetDistanceFromPlayer function instead.
 *
 * @param X1 The X coordinate of the point.
 * @param Y1 The Y coordinate of the point.
 * @param Z1 The Z coordinate of the point.
 * @return float The squared Euclidean distance between the point and the player's position.
 */
inline float GetDistanceSquaredFromPlayer(float X1, float Y1, float Z1)
{
	if (!pControlledPlayer)
		return 0.0f;

	return GetDistanceSquared(X1, Y1, Z1, pControlledPlayer->X, pControlledPlayer->Y, pControlledPlayer->Z);
}

} // namespace mq