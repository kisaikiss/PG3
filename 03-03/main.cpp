#include <iostream>

using namespace std;

class LivingThing {
public:
	virtual void Cry() = 0;
};

class Dog final : public LivingThing {
public:

};

int main() {


	return 0;
}