#include "hdd/img_manager.h"

using namespace ARL;

bool IMG_Manager::load_media()
{
	testvec.resize(testvec.size() + 1);
	return true;
}

IMG_Manager::IMG_Manager()
{
	testvec.resize(testvec.size() + 1);
}
