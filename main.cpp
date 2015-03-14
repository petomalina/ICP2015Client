#include "src/Client.h"

int main (int argc, char *argv[])
{
	Client client{};

	return static_cast<int>(client.run());
}