#include "test.hh"
#include <cstdlib>
#include <ctime>

int main(int argc, char *argv[]) {

srand(time(NULL));

Test start;

start.run(argc, argv);

return 0;

}
