#ifndef SHAREDPOINTER_H

#define SHAREDPOINTER_H
#include "RefCount.h"

template <class T>
class SharedPointer{

private:
	IRefCount<T>* refCount;


	//------------------------------- inner class-------------------------//
	class RefCounter : public RefCount < T > {
	private:
		T* ptr;

	protected:
		virtual T* getPtr() const { return ptr; }
		virtual void destroyRef() { if(this) delete this; }

	public:
		RefCounter(T* _ptr) : ptr(_ptr){};
		virtual ~RefCounter() { RefCount<T>::destroyRef(); }

	};

	void assign(void* ptr){
		if (ptr == NULL){
			assign((IRefCount<T>*)NULL);
		}
		else {
			assign(new RefCounter(static_cast<T*>(ptr)));
		}
	}

	void assign(IRefCount<T>* _refCount){
		if (_refCount != NULL){
			_refCount->incRefCount();
		}
		IRefCount<T>* oldRef = refCount;
		refCount = _refCount;
		if (oldRef != NULL){
			oldRef->decRefCount();
		}
	}

public:
	SharedPointer() : refCount(NULL){}
	SharedPointer(T* ptr) : refCount(NULL) { assign(ptr); }
	SharedPointer(const SharedPointer& sp) : refCount(NULL) { assign(sp.refCount); }
	
	virtual ~SharedPointer() { assign((IRefCount<T>*)NULL); }
	
	T* getPtr() const { return refCount == NULL ? NULL : refCount->getPtr(); }
	
	SharedPointer& operator=(const SharedPointer& sp) {
		if (&sp == this) return *this;
		assign(sp.refCount);
		return *this;
	}

	T* operator->() { return getPtr() == NULL ? NULL : getPtr(); }

	operator T*() const { return getPtr(); }

	bool operator! () { return getPtr()==NULL }
	bool operator== (const SharedPointer& sp) { return getPtr() == sp.getPtr(); }
	bool operator!= (const SharedPointer& sp) { return getPtr() != sp.getPtr(); }

	int getCounter() const { return refCount->getCounter(); }

};

#endif