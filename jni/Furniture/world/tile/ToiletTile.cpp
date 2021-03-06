#include "ToiletTile.h"

int ToiletTile::_id = 210;

ToiletTile::ToiletTile(int id, Material const* material) : RotatableTile(id, material) {
	Tile::solid[id] = false;
	Tile::lightBlock[id] = 0;

	setNameId("toiletTile");
	setSoundType(Tile::SOUND_STONE);
	setDestroyTime(1.0F);
	tex = getTextureUVCoordinateSet("quartz_block", 0);
}

void ToiletTile::addAABBs(TileSource* region, int x, int y, int z, AABB const* posAABB, std::vector<AABB, std::allocator<AABB>>& pool) {
	addAABB(AABB(0.0F, 0.0F, 0.0F, 1.0F, 0.5F, 1.0F).move(x, y, z), posAABB, pool);
	addAABB(CollisionHelper::getRotatedCollisionBox(region->getData(x, y, z), 0.65F, 0.5F, 0.0F, 1.0F, 1.1F, 1.0F).move(x, y, z), posAABB, pool);
}

bool ToiletTile::use(Player* player, int x, int y, int z) {
	return false;
}

int ToiletTile::getResource(int data, Random* rand) {
	return ToiletItem::_id;
}
