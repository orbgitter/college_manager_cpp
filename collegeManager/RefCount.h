#ifndef REFCOUNT_H
#define REFCOUNT_H
template <class T>

class IRefCount{
	template <class U> friend class SharedPointer;
protected:
	virtual void incRefCount() = 0;
	virtual void decRefCount() = 0;
	virtual T* getPtr() const = 0;

public:
	virtual int getCounter() const = 0;
};

//--------------------------------------------------------------//

template <class T>
class RefCount : public IRefCount < T >{
	int counter;
	void inline printCounter() { std::cout << counter << "\n"; }

protected:
	virtual void incRefCount() { counter++;}
	virtual void decRefCount() {
		counter--;
		if (counter <= 0) destroyRef();
	}

	virtual T* getPtr() const {	return (T*)this;}

	virtual void destroyRef(){ if (getPtr()) delete getPtr(); }
	RefCount() : counter(0) {}

	
public:
	virtual int getCounter() const {
		return counter;
	}
};

#endif