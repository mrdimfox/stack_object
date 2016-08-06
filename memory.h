#ifndef GENERIC_MEMORY_H_
#define GENERIC_MEMORY_H_

#include <cstddef>
#include <cstdint>

template<typename T>
class StackObject {
public:
	typedef T Type;
	typedef T* TypePointer;
	typedef std::uint8_t Byte;
	static constexpr std::size_t size = sizeof(T);

	~StackObject() {
		pointer()->~Type();
	}

	TypePointer pointer() {
		return reinterpret_cast<TypePointer>(&_obj);
	}

	template<class ... Types>
	void construct(Types... args) {
		new (&_obj) Type(args...);
	}

	void destruct() {
		pointer()->~Type();
	}

	Type* operator->() {
		return pointer();
	}

	Type& operator*() {
		return *pointer();
	}

private:
	Byte _obj[size];
};

#endif /* GENERIC_MEMORY_H_ */
