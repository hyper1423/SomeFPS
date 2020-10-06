#include "resource.hpp"

long Resource::referenceCount = 0;

template <typename T>
Resource<T>::Resource() : tablePtr(nullptr), resourcePtr(nullptr) { }

template <typename T>
template <typename U>
Resource<T>::Resource(U* resourcePtr) : tablePtr(new SharedPtrTableImpl<U>(resourcePtr)), resourcePtr(resourcePtr) { }

template <typename T>
Resource<T>::Resource(const Resource& resource) : resourcePtr(resource.resourcePtr), tablePtr(resource.tablePtr) { if (tablePtr) tablePtr->incrementCount(); }
template <typename T>
template <typename U>
Resource<T>::Resource(const Resource<U>& resource) : resourcePtr(resource.resourcePtr), tablePtr(resource.tablePtr) { if (tablePtr) tablePtr->incrementCount(); }

template <typename T>
Resource<T>::~Resource() { }

template <typename T>
long Resource<T>::use_count() const { return table->referenceCount; }

template <typename T>
T& Resource<T>::operator*() { return table-> }
template <typename T>
T* Resource<T>::operator->() { }

template <typename T>
Resource<T>::SharedPtrTable::SharedPtrTable() : referenceCount(1) { }

template <typename T>
void Resource<T>::SharedPtrTable::incrementCount() {
	referenceCount++;
}
template <typename T>
bool Resource<T>::SharedPtrTable::decrementCount() {
	if (referenceCount > 0) {
		referenceCount--;
		return true;
	} else {
		return false;
	}
}