#ifndef RESOURCE_HPP
#define RESOURCE_HPP

#include "../renderer/vertex_array/vertex_array.hpp"
#include "../renderer/model/model.hpp"
#include "../renderer/resources/texture/image/image.hpp"

#include <glm/glm.hpp>

#include <string>
#include <vector>
template <typename T>
class Resource {
public:
	Resource();
	template <typename U>
	Resource(U* resource);
	Resource(const Resource& resource);
	template <typename U>
	Resource(const Resource<U>& resource);
	~Resource();

	long use_count() const;

	T& operator*();
	T* operator->();
private:
	struct SharedPtrTable {
		long referenceCount;

		SharedPtrTable();
		virtual ~SharedPtrTable() = default;

		void incrementCount();
		bool decrementCount();

		virtual void destroy() = 0;
	};
	template <typename U>
	struct SharedPtrTableImpl: SharedPtrTable {
		U* resourcePtr;

		SharedPtrTableImpl(U* resourcePtr) : resourcePtr(resourcePtr) { }

		void destroy() override {
			delete resourcePtr;
		}
	};
	SharedPtrTable* tablePtr;
	T* resourcePtr;
};
#endif