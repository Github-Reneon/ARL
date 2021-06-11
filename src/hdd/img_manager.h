#ifndef IMG_MANAGER
#define IMG_MANAGER

#include <vector>

namespace ARL{
	
	class IMG_Manager {
		

		public:

		enum rows { DEBUG=0, WORLD=1, CHARACTERS=2, MONSTERS=3 };
		enum columns { ARCH=0 };
		
		std::vector<std::vector<int>> testvec;

		bool load_media();		

		// Constructor
		IMG_Manager();
	};

}

#endif
