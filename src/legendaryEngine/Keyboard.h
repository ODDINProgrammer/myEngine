#include <vector>

class Keyboard {
private:
	std::vector<int> Keycodes;
public:
	bool getKey(int keyCode);
	bool getKeyDown(int keyCode);
	bool getKeyUp(int keyCode);


};