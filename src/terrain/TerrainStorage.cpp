#include "TerrainStorage.h"

TerrainStorage::TerrainStorage(int32_t rootNodeCount, int32_t LoDCount) : rootNodeCount(rootNodeCount), LoDCount(LoDCount) {

	cells = new TerrainStorageCell*[LoDCount];
	LoDSideLengths = new int32_t[LoDCount];

	for (int32_t i = 0; i < LoDCount; i++) {

		cells[i] = new TerrainStorageCell[rootNodeCount * (int32_t)powf(4, (float)i)];
		LoDSideLengths[i] = (int32_t)sqrtf((float)rootNodeCount * powf(4.0f, (float)i));

		for (int32_t x = 0; x < LoDSideLengths[i]; x++) {
			for (int32_t y = 0; y < LoDSideLengths[i]; y++) {
				cells[i][x * LoDSideLengths[i] + y].x = x;
				cells[i][x * LoDSideLengths[i] + y].y = y;
				cells[i][x * LoDSideLengths[i] + y].LoD = i;
			}
		}
	}

}

TerrainStorageCell* TerrainStorage::GetCell(int32_t x, int32_t y, int32_t LoD) {

	return &cells[LoD][x * LoDSideLengths[LoD] + y];

}