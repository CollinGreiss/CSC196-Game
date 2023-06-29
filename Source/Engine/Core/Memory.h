#pragma once
namespace kiko {

	struct MemoryAllocatoin {

		void* address;
		size_t size;
		MemoryAllocatoin* next;

	};

	class MemoryTracker {
	
	public:

		void Add(void* address, size_t size);

	private:
	
	};

};

