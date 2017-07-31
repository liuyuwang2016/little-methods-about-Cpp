#include <iostream>
#include <string>
using namespace std;

class Iterator {
public:
	virtual ~Iterator() {}
	virtual bool operator!=(const Iterator &other) const = 0;
	virtual const Iterator& operator++ () = 0;
	virtual const Iterator& operator++(int) = 0;
	virtual float& operator*() const = 0;
	virtual float* operator->() const = 0;
	bool operator==(const Iterator &other) const {
		return !(*this != other);
	}
};

class Collection {
public:
	virtual ~Collection() { }
	virtual Iterator* begin() const = 0;
	virtual Iterator* end() const = 0;
	virtual int size() = 0;
};

void analyse(Iterator* begin, Iterator* end) {
	int passed = 0, count = 0;
	for (Iterator* p = begin; *p != *end; (*p)++) {
		if (**p >= 60)
			passed++;
		count++;
	}
	cout << "Passing rate = " << (float)passed / count << endl;
}

int main(int argc, char *argv[]) {
	Collection *collection;
	analyse(collection->begin(), collection->end());
}